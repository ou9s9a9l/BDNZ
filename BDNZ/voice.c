//  精简rdata2
//free(tmp)
//0.81版本  精简了radata3 缩小了5倍提高了可适应性
//解决输出不正确
//关于0011变成1100会有四个纪录数的解决
//n=0即可跳出 不用继续下面的
//search中的b没初始化为0
//判断不影响UDR1的值 赋值才影响
//c mkii shiyan shiyan   笔记本  新安村txt


#include "voice.h"
#include "define.h"
#include "bdn_txt.h"
unsigned int resflag=0;

extern int m_freedelay=0;					////k是rdata3里面的条件数//x代表rdata123的第几个 //n代表与条件 如果是1则成立h为已经成立条件数




extern unsigned short factor[5][4];
unsigned int rdata4[50],m_count = 0;
unsigned char Bcast[6][3];
unsigned char remote_sendflag = 0;

int signalflag = 0;

									
void EEPROM_write(unsigned int uiAddress, unsigned char  ucData)
{
/*  Wait for completion of previous write */
while(EECR & (1<<EEPE));
/* Set up address and Data Registers */
EEAR = uiAddress;
EEDR = ucData;
/*  Write logical one to EEMPE */
EECR |= (1<<EEMPE);
/* Start eeprom write by setting EEPE */
EECR |= (1<<EEPE);
}
unsigned char  EEPROM_read( unsigned int uiAddress)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE))
;
/* Set up address register */
EEAR = uiAddress;
/*  Start eeprom read by writing EERE */
EECR |= (1<<EERE);
/* Return data from Data Register */
return EEDR;
}


//发送一个字节 usart
void uart_sendB(unsigned char data) 
{
   while ( !( UCSR0A & (1<<UDRE0)) ); 
    UDR0=data;
}
void uart_sendB1(unsigned char data)
{
	while ( !( UCSR1A & (1<<UDRE1)) );
	UDR1=data;
}
//延迟
void Uart_SendString(unsigned char *data)
{
	volatile unsigned int a=0;
	while(data[a]!=0)
	{uart_sendB(data[a]);a++;} 
}
//定时器初始化

//串口初始化
/*
void USART0_Init( void )
{
     UBRR0L=16;         //8m 51 1m  12 4800   8888 16是2x情况下57600
	 UCSR0A =(1<<U2X0);         
     UCSR0B = (1<<RXEN0)|(1<<TXEN0); 
	 UCSR0C =0x0e;// (1<<USBS0)|(3<<UCSZ0);
}*/
void USART0_Init( void )
{
	#ifdef USART0_SPEED
	UBRR0L = USART0_SPEED;
	#else
	UBRR0L=143;         //35 38400 ;143 9600
	#endif
	UCSR0A =(1<<U2X0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C =0x0e;// (1<<USBS0)|(3<<UCSZ0);
	UCSR0B |=(1<<RXCIE0);

}
/*
void USART1_Init( void )//wifi
{
	UBRR1L=51;         //8m 51 1m  12 4800   8888 16是2x情况下57600
	UCSR1A =(1<<U2X1);
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	UCSR1C =0x0e;// (1<<USBS0)|(3<<UCSZ0);
}*/
void USART1_Init( void )//wifi
{
	UBRR1L=11;         //8m 51 1m  12 4800   8888 16是2x情况下57600
	UCSR1A =(1<<U2X1);
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	UCSR1C =0x0e;// (1<<USBS0)|(3<<UCSZ0);
	UCSR1B |=(1<<RXCIE1);
}
///////////////////////////////////////接收并储存到ram里//////////////////////////////////////////////////////////

//crc 校验

void qingling(unsigned char *rdat,unsigned char length)
{
	unsigned int a;
	for(a=0;a<length;a++)
	rdat[a]=0;
}
//////////////////////////////////
void add2Bcast(unsigned char Num1,unsigned char Num2,unsigned char Num3)
{
if (Bcast[5][0]==0){Bcast[5][0]=Num1;Bcast[5][1]=Num2;Bcast[5][2]=Num3;}
else if (Bcast[4][0]==0){Bcast[4][0]=Num1;Bcast[4][1]=Num2;Bcast[4][2]=Num3;}
else if	(Bcast[3][0]==0){Bcast[3][0]=Num1;Bcast[3][1]=Num2;Bcast[3][2]=Num3;}
else if	(Bcast[2][0]==0){Bcast[2][0]=Num1;Bcast[2][1]=Num2;Bcast[2][2]=Num3;}
else if	(Bcast[1][0]==0){Bcast[1][0]=Num1;Bcast[1][1]=Num2;Bcast[1][2]=Num3;}
/*else 
{{for(b=0;b<5;b++)
Bcast[b]=Bcast[b+1];}
Bcast[5]=Num;}*/

}
void sendcast(void)
{
	if(Bcast[0][0]!=0)qingling(Bcast[0],3);
	
	//if(m_count<10)return;
	//if(rdata1[0]==0)
	//for(int a=0;a<6;a++)//开始1分钟不报
	//{Bcast[a][0]=0;Bcast[a][1]=0;Bcast[a][2]=0;}
	
	volatile unsigned char b=0;
	if(Bcast[5][2]!=0)
	{
	m_freedelay=0;
	//_delay_ms(send_delay);
	//send_moni(Bcast[5][2],Bcast[5][0],Bcast[5][1]);
	//b=send_int(Bcast[5][0],Bcast[5][1],Bcast[5][2]);
	_delay_ms(10);
	//if(b)
	{
	//if(!resflag)
	{
	//_delay_ms(500);
	uart_sendB1(0xff);
	uart_sendB1(Bcast[5][0]);
	uart_sendB1(Bcast[5][1]);
	uart_sendB1(Bcast[5][2]);
	uart_sendB1(0xff);
	//_delay_ms(500);	
	}
	uart_sendB(Bcast[5][0]);
	uart_sendB(Bcast[5][1]);
	uart_sendB(Bcast[5][2]);
	for(b=5;b!=0;b--)
	{
		
		Bcast[b][0]=Bcast[b-1][0];
		Bcast[b][1]=Bcast[b-1][1];
		Bcast[b][2]=Bcast[b-1][2];
		
	}
	}	
	m_count=0;
	_delay_ms(100);
	
	}
	
	#if SELECT==2009				   //处理程序zyz
	if (m_freedelay>=60)
	#endif
	
	if (m_freedelay>=2)
	{
		add2Bcast(0,0,254);//正定 3分钟一次
		send_moni(0,0);
		m_freedelay=0;
	}
}


void Timer_Init(void)
{
	cli();
	TCCR1B=0x05;// 1024  5devide
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	TIMSK1=0x01;//1开启中断
	sei();
}
void setsleep(void)
{
	SMCR|=(1<<SE);	
}
extern unsigned char flag_8 ;
extern unsigned char flag_9 ;
int six_second = count_times;
ISR(TIMER1_OVF_vect)
{
	if(flag_8==1){factor[1][0]=0;factor[1][1]=0;}
	if(flag_8>0)flag_8--;
	if(flag_9==1){factor[2][0]=0;factor[2][1]=0;}
	if(flag_9>0)flag_9--;
	uart_sendB1(0x33);
	uart_sendB1(remote_sendflag);
if(six_second == 0)
{
	send_moni(221,0,0);
	//uart_sendB1(0x33);
	if(signalflag == 1)
	{
	_delay_ms(1000);
	{uart_sendB1(0xff);
		uart_sendB1(0xDD);
		uart_sendB1(0x00);
		uart_sendB1(0xfe);
	uart_sendB1(0xff);	}
	}
	
	signalflag=1;
	six_second = count_times;
}
six_second--;
	//resflag++;
	//重启无线模块
}

ISR(USART1_RX_vect)
{	
	volatile int temp,a=0,b=0;
	
	if(UCSR1A & (1<<RXC1))
	temp=UDR1;
	if(temp==0x30){wdt_enable(WDTO_8S);uart_sendB1(0x33);}
	if(temp==0x31){uart_sendB1(0x33);
		if(remote_sendflag==0)
		remote_sendflag = 1;
		else
		remote_sendflag = 0;
		uart_sendB1(remote_sendflag);
		}
	if(temp==0x33)
	if(resflag==1)resflag=0;//wdt_reset();
	else resflag=1;
}







void send_to_server(unsigned char *source,unsigned int len)
{
	unsigned int i = 0;
	for(i=0;i<len;i++)
		uart_sendB1(source[i]);
	
}
void read_prog(unsigned char *RamVar,unsigned char b)
{
	//#if SELECT==2006||SELECT==2010
	for(unsigned char a = 0;a<30;a++)
	RamVar[a] = pgm_read_byte( &s[b][a] );
	//#endif
	
}
void send_moni(unsigned char b,unsigned char c,unsigned char d)
{
	unsigned char RamVar[4][33]={0}; //定义无符号整型变量(Ram变量)
	_PB1 = !_PB1;//red
	m_freedelay=-1;
	_delay_ms(15);
	if(d==0)
	read_prog(RamVar[0],254);
	if(d==1)
	read_prog(RamVar[0],253);
	read_prog(RamVar[1],b);
	read_prog(RamVar[2],c);
	unsigned char k = 0;
	for(unsigned char i = 0;i<3;i++)
		for(unsigned char j = 0;j<30;j++)
		if(RamVar[i][j]!=0)
			RamVar[3][k++]=RamVar[i][j];
    uart_sendB1(0xff);
	uart_sendB1(b);
	uart_sendB1(c);
	uart_sendB1(0xfe);
	uart_sendB1(0xff);			
	unsigned char flag = send_int(RamVar[3]);
	//while(!send_int(RamVar[3]));
	if(flag == 0)
	flag=send_int(RamVar[3]);
	if(flag == 0)
	send_int(RamVar[3]);
	
	_delay_ms(500);
	//_PB0 = !_PB0;//red
}
unsigned char rxbuffer[32];
#include <avr/boot.h>
unsigned char testbuf[32];

Init_Para para;
