//  精简rdata2
//free(tmp)
//0.81版本  精简了radata3 缩小了5倍提高了可适应性
//解决输出不正确
//关于0011变成1100会有四个纪录数的解决
//n=0即可跳出 不用继续下面的
//search中的b没初始化为0
//判断不影响UDR1的值 赋值才影响
//c mkii shiyan shiyan   笔记本  新安村txt


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <AVR/sleep.h>
#include <avr/wdt.h> 
#include "nRF24L01.h"
#include "voicebdn.h"
//#include "nRF24L01_Reg.h"
#include "macr.h"
//#include "nRF24L01.h"
unsigned char *p;//flag
unsigned char *j=((unsigned char *)0x000800);//数据存储位置

unsigned int resflag=0;

#ifndef F_CPU
#define F_CPU 8000000
#endif
#include <util/delay.h>

BYTEBIT  Cdata1,Cdata2;
#define FORMAT(Addr) SET_BIT8_FORMAT(Addr)
//#ifdef Cdata1
	#define Cdat1_0   Cdata1.BIT0
	#define Cdat1_1   Cdata1.BIT1
	#define Cdat1_2   Cdata1.BIT2
	#define Cdat1_3   Cdata1.BIT3
	#define Cdat1_4   Cdata1.BIT4
	#define Cdat1_5   Cdata1.BIT5
	#define Cdat1_6   Cdata1.BIT6
	#define Cdat1_7   Cdata1.BIT7
//#endif
//#ifdef Cdata2
	#define Cdat2_0   Cdata2.BIT0
	#define Cdat2_1   Cdata2.BIT1
	#define Cdat2_2   Cdata2.BIT2
	#define Cdat2_3   Cdata2.BIT3
	#define Cdat2_4   Cdata2.BIT4
	#define Cdat2_5   Cdata2.BIT5
	#define Cdat2_6   Cdata2.BIT6
	#define Cdat2_7   Cdata2.BIT7
//#endif
#define LED_OFF  _PA3=1;
#define LED_ON  _PA3=0;
#define LED_TWINKEL {LED_ON;_delay_ms(1000);LED_OFF;_delay_ms(1000);}
int hei[3]; 
unsigned int m_freedelay=0;					////k是rdata3里面的条件数//x代表rdata123的第几个 //n代表与条件 如果是1则成立h为已经成立条件数
volatile unsigned int delay=0,rx0x12=0,rx0x11=0;
unsigned int m_save,m_crc,m_count;
volatile char rdata[size]={0};
volatile char rdata1[size]={0};
volatile char rdatatemp[size]={0};
volatile unsigned int DoWithArray[80]={0};
//unsigned int rdata2[11]={115,117,119,121,123,125,127,129,131,133};
volatile unsigned int rdata3[150]={0};
unsigned int rdata4[DELAY];
unsigned char Bcast[6][3];



									
void EEPROM_write(unsigned int uiAddress, unsigned char  ucData)
{
/*  Wait for completion of previous write */
while(EECR & (1<<EEPE))
;
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
	UBRR0L=11;         //8m 51 1m  12 4800   8888 16是2x情况下57600
	UCSR0A =(1<<U2X0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C =0x0e;// (1<<USBS0)|(3<<UCSZ0);
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
}
///////////////////////////////////////接收并储存到ram里//////////////////////////////////////////////////////////
void input_usart()
{
	//设置p为初始指针 j用为操作指针
	int a=0,b=0;
	p=j;
	while(1)
	{
		while ( !(UCSR0A & (1<<RXC0)) );
		b=UDR0;
		hei[0]=b;
		if(b!=0)
		{m_crc=b;
		m_crc++;}
		if(0x3c==b)	
		{
		LED_ON
		*j++=b;
			while(a<2500)//全数据4000   接收半数据封闭
			{
			while ( !(UCSR0A & (1<<RXC0)) );
			b=UDR0;
			if(b==0x7c)return;
			else *j++=b;
			a++;
			}
		
		}
	}
}
//crc 校验
unsigned int CRC(char* pBuf,int Len)
{
	unsigned int CRC = 0;
unsigned char R;
	int i,j,k,m;
	CRC=0;
		if(Len<=0) return 0;
		for(i=1;i<Len;i++)    {
		R=pBuf[i];
			for(j=0;j<8;j++)	
			{
			if (R>127) k=1;else k=0;
			R<<=1;
			if(CRC>0x7fff) m=1;	else m=0;
			if (k+m==1) k=1; 	else k=0;
			CRC<<=1;
			if (k==1) CRC^=0x1021;
			}
		}
		return CRC; 
}


////////////////////////////////////////判断////////////////////////////////////////////////////////////////////////////////
unsigned char Quest_len_int(unsigned int *Par)
{
unsigned char b=0;
while(*Par++!=0&&b<size)b++;
return b;
}
unsigned char Quest_len_char(unsigned char *Par)
{
unsigned char b=0;
while(*Par++!=0&&b<size)b++;
return b;
}
//Cdata1,Cdata2;
//0xff查询长度
void cut(unsigned int Num)
{
volatile unsigned char a,b,c,temp_len,count=0;

	for(b=0;b<Quest_len_int(rdata3);b++)
	if(rdata3[b]==Num)
	{
	temp_len=Quest_len_int(rdata3);
	for(;b<temp_len;b++)rdata3[b]=rdata3[b+1];
	}


while(count<CON2_LENGTH)
	{


		//////////////////////成功
		if(Num==conditon2[count][0])
		{
		factor[count].what=0;
		factor[count].howmany=0;		
		}
	count++;
	}
	for(c=0;c<DELAY-10;c++)
	{
	if(Num==rdata4[c])
		rdata4[c]=0;
	}

/*	for(c=DELAY-9;c<DELAY;c++)
	{
	if(Num==rdata4[c])
		for(;c<DELAY-1;c++)////////////////////////////////
		rdata4[c]=rdata4[c+1];
	}*/

}
unsigned char find(unsigned int *rdat,unsigned int source)
{
	unsigned char b=0,temp;
	temp=Quest_len_int(rdat);
	if (rdat[DELAY-9]!=0&&0==temp)
	temp=DELAY-1;
	for (unsigned char a=0;a<=temp;a++)
	{if(rdat[a]==source)return 1;}
		
	return 0;
}

void add(unsigned char Data2,unsigned char Data1,volatile unsigned int Ident)
{
	
	volatile unsigned int dat=0;
	Cdata1=FORMAT(Data1);
	Cdata2=FORMAT(Data2);
	dat=Ident*8-Startcharlen*8+1;//4*8-1
	if(Cdat1_0>Cdat2_0&&!find(rdata3,dat+0))
	{rdata3[Quest_len_int(rdata3)]=dat+0;
	}
	
	if(Cdat1_1>Cdat2_1&&!find(rdata3,dat+1))
	{rdata3[Quest_len_int(rdata3)]=dat+1;
	//if(find(rdata2,(dat+6))&&(!find(rdata4,(dat+6))))addto4_last(dat+6);
	}
	
	if(Cdat1_2>Cdat2_2&&!find(rdata3,dat+2))
	{rdata3[Quest_len_int(rdata3)]=dat+2;
	}

	
	if(Cdat1_3>Cdat2_3&&!find(rdata3,dat+3))
	{rdata3[Quest_len_int(rdata3)]=dat+3;
	//if(find(rdata2,(dat+4))&&(!find(rdata4,(dat+4))))addto4_last(dat+4);
	}
	
	if(Cdat1_4>Cdat2_4&&!find(rdata3,dat+4))
	{rdata3[Quest_len_int(rdata3)]=dat+4;
	}
	
	if(Cdat1_5>Cdat2_5&&!find(rdata3,dat+5))
	{rdata3[Quest_len_int(rdata3)]=dat+5;
	//if(find(rdata2,(dat+2))&&(!find(rdata4,(dat+2))))addto4_last(dat+2);
	}
	
	if(Cdat1_6>Cdat2_6&&!find(rdata3,dat+6))
	{rdata3[Quest_len_int(rdata3)]=dat+6;
	}
	
	if(Cdat1_7>Cdat2_7&&!find(rdata3,dat+7))
	{rdata3[Quest_len_int(rdata3)]=dat+7;
	//if(find(rdata2,(dat+0))&&(!find(rdata4,(dat+0))))addto4_last(dat+0);
	}
	
	if(Cdat1_0<Cdat2_0||Cdat1_0==0){cut((dat+0));}
	if(Cdat1_1<Cdat2_1||Cdat1_1==0){cut((dat+1));}
	if(Cdat1_2<Cdat2_2||Cdat1_2==0){cut((dat+2));}
	if(Cdat1_3<Cdat2_3||Cdat1_3==0){cut((dat+3));}
	if(Cdat1_4<Cdat2_4||Cdat1_4==0){cut((dat+4));}
	if(Cdat1_5<Cdat2_5||Cdat1_5==0){cut((dat+5));}
	if(Cdat1_6<Cdat2_6||Cdat1_6==0){cut((dat+6));}
	if(Cdat1_7<Cdat2_7||Cdat1_7==0){cut((dat+7));}

	
 }
 void add1(unsigned char Data2,unsigned char Data1,volatile unsigned int Ident)
{
	
	volatile unsigned int dat=0;
	Cdata1=FORMAT(Data1);
	Cdata2=FORMAT(Data2);
	dat=Ident*8-Startcharlen*8+1;//4*8-1
	
	if(Cdat1_7>Cdat2_7&&!find(rdata3,dat+0))
	{rdata3[Quest_len_int(rdata3)]=dat+0;
	//if(find(rdata2,(dat+0))&&(!find(rdata4,(dat+0))))addto4_last(dat+0);
	}
	if(Cdat1_6>Cdat2_6&&!find(rdata3,dat+1))
	{rdata3[Quest_len_int(rdata3)]=dat+1;
	}
	if(Cdat1_5>Cdat2_5&&!find(rdata3,dat+2))
	{rdata3[Quest_len_int(rdata3)]=dat+2;
	//if(find(rdata2,(dat+2))&&(!find(rdata4,(dat+2))))addto4_last(dat+2);
	}

	if(Cdat1_4>Cdat2_4&&!find(rdata3,dat+3))
	{rdata3[Quest_len_int(rdata3)]=dat+3;
	}
	

	
	if(Cdat1_3>Cdat2_3&&!find(rdata3,dat+4))
	{rdata3[Quest_len_int(rdata3)]=dat+4;
	//if(find(rdata2,(dat+4))&&(!find(rdata4,(dat+4))))addto4_last(dat+4);
	}
	

	if(Cdat1_2>Cdat2_2&&!find(rdata3,dat+5))
	{rdata3[Quest_len_int(rdata3)]=dat+5;
	}
	
	
	if(Cdat1_1>Cdat2_1&&!find(rdata3,dat+6))
	{rdata3[Quest_len_int(rdata3)]=dat+6;
	//if(find(rdata2,(dat+6))&&(!find(rdata4,(dat+6))))addto4_last(dat+6);
	}
	if(Cdat1_0>Cdat2_0&&!find(rdata3,dat+7))
	{rdata3[Quest_len_int(rdata3)]=dat+7;
	}
	

	if(Cdat1_0<Cdat2_0){cut((dat+7));}
	if(Cdat1_1<Cdat2_1){cut((dat+6));}
	if(Cdat1_2<Cdat2_2){cut((dat+5));}
	if(Cdat1_3<Cdat2_3){cut((dat+4));}
	if(Cdat1_4<Cdat2_4){cut((dat+3));}
	if(Cdat1_5<Cdat2_5){cut((dat+2));}
	if(Cdat1_6<Cdat2_6){cut((dat+1));}
	if(Cdat1_7<Cdat2_7){cut((dat+0));}

	
 }

void addto4(unsigned int Num)
{
	volatile  char b;
	for(b=0;b<(DELAY-11);b++)
	rdata4[b]=rdata4[b+1];
	rdata4[DELAY-11]=Num;
}

void Judge(void)//传入一个接收到的rxdata数组 这个数组依次和前一个比较结果存到类似   05 51  这样的结果中第五位为51
{
	int b=0,a=0;
//		for (b=0;b<150;b++)
//		rdata3[b]=0;
		for (b=DELAY-9;b<DELAY;b++)
		{
			rdata4[b]=0;
		}
		rdata4[41]=133;
		for (int d=0;d<collectlen;d++)
		for (a=start1[d]+Startcharlen;a<last1[d]+Startcharlen;a++)
		{
	#if SELECT==2010
		add(rdata1[a],rdata[a],a); 
	#else if SELECT==2006                          //处理程序2010
		add1(rdata1[a],rdata[a],a);							   //处理程序2006
	#endif
		}
		
	for(a=0;a<size;a++)
	{rdata1[a]=rdata[a];rdata[a]=0;}
}


////////////////////////////////////////////////////////////////////



void addx(unsigned int q,unsigned int *t,unsigned char r)
{
for(int i=0;i<Quest_len_int(t);i++)
if (t[i]==q)
{
	return;
}
*(t+r)=q;	
}
///////////////////////////////////传入一个当前条件的指针，无输出  弄出已经输出列表
//void cut(int *q,int *t,int *r,char s)//q是现有的  t为要消除的 r是q的最大条件数目 s为t最大的条件
///////////////////////////////////传入一个指针  判断是否为以输出

/////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////	

void input_rom(void)
{
	volatile unsigned char sum=0;
	volatile int	a=0,b=0;
	struct word *tmp;
	char array[3]={0};
	
while(EEPROM_read(++b)!=0x2e)
{
	b--;
	tmp=(struct word*)malloc(sizeof(struct word));
	 if (NULL == tmp) 
    { 
        exit (1); 
    } 
	unsigned int *x=tmp->con;
	unsigned char *y=tmp->sent;
	for(a=0;a<ConSize;a++)
	tmp->con[a]=0;
	for(a=0;a<SentSize;a++)
	tmp->sent[a]=0;
if(EEPROM_read(b)==0x3C)
	{
	b++;
	while(1)
		{
    	if(EEPROM_read(b)==0x3e)break;
		else 
		for (a=0;a<3;a++)
		array[a]=EEPROM_read(b++);
		*x++=atoi(array);
		}
	}

if(EEPROM_read(b)==0x3e)
	{
	b++;
	while(1)
		{
		if(EEPROM_read(b)==0x3c)break;
		else 
		*y++=EEPROM_read(b++);
		}
	sum++;
	}
		if(head==NULL)
		{
		head=tmp;
		pthis=head;
		}
		else
		{
		pthis->next=tmp;
		pthis=pthis->next;
		}
}
pthis->next=NULL;
//uart_sendB(sum);
//str_send(luxi);
}
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
	m_count++;m_freedelay++;
	if(m_count<10)return;
	if(rdata1[0]==0)
	for(int a=0;a<6;a++)//开始1分钟不报
	{Bcast[a][0]=0;Bcast[a][1]=0;Bcast[a][2]=0;}
	if (m_freedelay>60)
		{
			add2Bcast(0,0,254);//正定 3分钟一次
			m_freedelay=0;
		}
	volatile unsigned char b=0;
	if(Bcast[5][2]!=0)
	{
	m_freedelay=0;
	
	LED_ON
	b=send_int(Bcast[5][0],Bcast[5][1],Bcast[5][2]);
	_delay_ms(10);
	if(b)
	{
	if(!resflag)
	{uart_sendB1(0xff);
	uart_sendB1(Bcast[5][0]);
	uart_sendB1(Bcast[5][1]);
	uart_sendB1(Bcast[5][2]);
	uart_sendB1(0xff);	}
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
	LED_OFF
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
int signalflag = 0;
ISR(TIMER1_OVF_vect)
{
	if (READ_PA3==0)
	_PA3=1;
	else 
	_PA3=0;
	if(signalflag == 1)
	{uart_sendB1(0x33);
	_delay_ms(1000);}
	uart_sendB1(0x33);
	signalflag=1;
	
	//resflag++;
	//重启无线模块
}

ISR(USART1_RX_vect)
{	
	volatile int temp,a=0,b=0;
	
	if(UCSR1A & (1<<RXC1))
	temp=UDR1;
	if(temp==0x30)wdt_enable(WDTO_8S);
	if(temp==0x33)
	if(resflag==1)resflag=0;//wdt_reset();
	else resflag=1;
}
int rxflag=0,succflag=0,count=0,resetflag=0;
ISR(USART0_RX_vect)
{	
	int temp,a=0,b=0;
	
	if(UCSR0A & (1<<RXC0))
	temp=UDR0;
	if(temp==0x01)succflag=1;
	signalflag=0;
//	if(resetflag==1)
//	if(temp==0x0A)
//	wdt_enable(WDTO_15MS);//使能看门狗定时器，溢出时间设置为1秒
//	else resetflag=0;
//	if(temp==0xff)resetflag=1;
	//if(temp==0x43)uart_sendB(0x01);
	if(1==count&&temp==0x14)
	{sendcastflag=1;}
	if(1==count&&(temp==0x14||temp==0x15))
	 {
		 succflag=0;count=0;return;
	 }
	
	 //if(1==count&&(temp==0x11||temp==0x12))LED_ON
	if (count>(size-10))
	{
	for (a=0;a<size;a++)
	rdatatemp[a]=0;
	succflag=0;
	count=0;
	}
	

	if(succflag)
	{
	 rdatatemp[count]=temp;
	
	
	if (rdatatemp[count]==0x03)
	 {
		
	int c=0;
	if (count==13)
	{for (a=14;a>2;a--)
	rdatatemp[a]=rdatatemp[a-1];rdatatemp[2]=0x04;count++;}
	if (count==287)
	{for (a=288;a>2;a--)
	rdatatemp[a]=rdatatemp[a-1];rdatatemp[2]=0x16;count++;}
		  m_save=CRC(rdatatemp,count-2);
		  m_crc=rdatatemp[count-2];
		  m_crc<<=8;
		  m_crc|=rdatatemp[count-1];
		  if(m_save!=m_crc||m_crc==0)
		  {
			hei[0]=m_crc;
			  for (a=0;a<=count;a++)
			  rdatatemp[a]=0;
			  hei[0]=m_crc;
		  }
		  
		  
		 if(rdatatemp[1]==0x11)
		 {
		if(rdata[0]!=0)
		for (b=0;b<cachelen;b++)
		{
			if(rdatacache[b][0]==0)
			for (int a=0;a<cachelen1;a++)
			{{
				rdatacache[b][a]=rdata[a];
			}c=1;}
			if (c==1){/*uart_sendB(b);*/break;}
		}
		for (a=0;a<=20;a++)
		rdata[a]=0;
		for ( a=0;a<=count;a++)
		 {
			 rdata[a]=rdatatemp[a];
		 }
		 
		 }
		 else{
		 if(rdata[0]==0)
		for ( a=0;a<=count;a++)
		 {
			 rdata[a]=rdatatemp[a];
		 }
		 for (b=0;b<cachelen;b++)
		{
			if(rdatacache[b][0]==0)
			for (int a=0;a<cachelen1;a++)
			{{
				rdatacache[b][a]=rdatatemp[a];
			}c=1;}
			if (c==1){break;}
		}
		 }		    	
		
		
		 /*else if(rdatacache[0][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[0][a]=rdatatemp[a];
		 }
		 else if(rdatacache[1][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[1][a]=rdatatemp[a];
		 }
		 else if(rdatacache[2][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[2][a]=rdatatemp[a];
		 }
		 else if(rdatacache[3][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[3][a]=rdatatemp[a];
		 }
		 else if(rdatacache[4][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[4][a]=rdatatemp[a];
		 }
		 else if(rdatacache[5][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[5][a]=rdatatemp[a];
		 }
		 else if(rdatacache[6][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[6][a]=rdatatemp[a];
		 }
		 else if(rdatacache[6][0]==0)
		 for (int a=0;a<15;a++)
		 {
			 rdatacache[6][a]=rdatatemp[a];
		 }*/
		
	
	 if(rdatatemp[1]==0x12)
	 rx0x12=0;
	 if(rdatatemp[1]==0x11)
	 rx0x11=0;	 
	 count=-1;
	 succflag=0;
	 LED_OFF
	 
	 for (a=0;a<=count;a++)
	rdatatemp[a]=0;
	 }
	  if (rxflag==1)      				          //转译标志
	 switch(rdatatemp[count])
	 {
		 case 0x81: rdatatemp[count-1]=0x01;count--;rxflag=0;break;
		 case 0x83: rdatatemp[count-1]=0x03;count--;rxflag=0;break;
		 case 0x90: rdatatemp[count-1]=0x10;count--;rxflag=3;break;
		 default:rxflag=0;break;
	 }
	 if (rdatatemp[count]==0x10&&rxflag!=3)
	 rxflag=1;     //设置转译标志	 
	 else rxflag=0;
	 count++;
	 //辨别终止位
	 }	 
}



unsigned char DoWithTiaoJian(unsigned int *rdat)//左1右0
{
	volatile unsigned char a,b,c=0,DoWithCount=1,DoWithvalue=0;
	for (a=1;a<LENGTH;a++)
		for ( b=0;b<7;b++)
			for (c=0;c<150;c++)
				if (x_middle[a][b]==rdat[c]&&x_middle[a][b]!=0)//reserve条件成立
					{
					if(b==0&&find(rdata3,x_left[a][0])&&find(rdata3,x_left[a][1])&&find(rdata3,x_left[a][2])
					&&find(rdata3,x_left[a][3])&&find(rdata3,x_left[a][4])&&find(rdata3,x_left[a][5])
					&&(find(rdata3,x_left[a][6])||find(rdata3,x_left[a][7])))//reserver左边判断
					
					{DoWithArray[DoWithCount++]=x_middle[a][b];
					DoWithArray[DoWithCount++]=a;}
					
					else if(b==1&&find(rdata3,x_right[a][0])&&find(rdata3,x_right[a][1])&&find(rdata3,x_right[a][2])
					&&find(rdata3,x_right[a][3])&&find(rdata3,x_right[a][4])&&find(rdata3,x_right[a][5])
					&&(find(rdata3,x_right[a][6])||find(rdata3,x_right[a][7])))//reserver又边判断
					
					{DoWithArray[DoWithCount++]=x_middle[a][b];
					DoWithArray[DoWithCount++]=a;}
					
					if (b!=0&&b!=1)//reserver其他判断（正轨）
					{
					DoWithArray[DoWithCount++]=x_middle[a][b];
					DoWithArray[DoWithCount++]=a;
					}
					}
	
	if (DoWithCount>1)
	{
		for (a=1;a<40;a++)
			if (DoWithArray[a*2]==DoWithArray[a*2+2]&&DoWithArray[a*2]==DoWithArray[a*2+4]&&DoWithArray[a*2]==DoWithArray[a*2+6]&&DoWithArray[a*2]==DoWithArray[a*2+8]&&DoWithArray[a*2]==DoWithArray[a*2+10]&&DoWithArray[a*2]==DoWithArray[a*2+12]
			&&DoWithS[DoWithvalue-1].what!=DoWithArray[a*2]&&DoWithArray[a*2]!=0)
			{DoWithS[DoWithvalue].howmany=7;DoWithS[DoWithvalue].what=DoWithArray[a*2];DoWithvalue++;}
			else if (DoWithArray[a*2]==DoWithArray[a*2+2]&&DoWithArray[a*2]==DoWithArray[a*2+4]&&DoWithArray[a*2]==DoWithArray[a*2+6]&&DoWithArray[a*2]==DoWithArray[a*2+8]&&DoWithArray[a*2]==DoWithArray[a*2+10]
			&&DoWithS[DoWithvalue-1].what!=DoWithArray[a*2]&&DoWithArray[a*2]!=0)
			{DoWithS[DoWithvalue].howmany=6;DoWithS[DoWithvalue].what=DoWithArray[a*2];DoWithvalue++;}
			else if (DoWithArray[a*2]==DoWithArray[a*2+2]&&DoWithArray[a*2]==DoWithArray[a*2+4]&&DoWithArray[a*2]==DoWithArray[a*2+6]&&DoWithArray[a*2]==DoWithArray[a*2+8]
			&&DoWithS[DoWithvalue-1].what!=DoWithArray[a*2]&&DoWithArray[a*2]!=0&&DoWithArray[a*2-1]!=DoWithArray[a*2+1])
			{DoWithS[DoWithvalue].howmany=5;DoWithS[DoWithvalue].what=DoWithArray[a*2];DoWithvalue++;}
			else if (DoWithArray[a*2]==DoWithArray[a*2+2]&&DoWithArray[a*2]==DoWithArray[a*2+4]&&DoWithArray[a*2]==DoWithArray[a*2+6]
			&&DoWithS[DoWithvalue-1].what!=DoWithArray[a*2]&&DoWithArray[a*2]!=0&&DoWithArray[a*2-1]!=DoWithArray[a*2-3]&&DoWithArray[a*2+1]==DoWithArray[a*2+3]&&DoWithArray[a*2+1]!=DoWithArray[a*2-1])
			{DoWithS[DoWithvalue].howmany=4;DoWithS[DoWithvalue].what=DoWithArray[a*2];DoWithvalue++;}
			else if(DoWithArray[a*2]==DoWithArray[a*2+2]&&DoWithArray[a*2]==DoWithArray[a*2+4]&&DoWithArray[a*2]!=DoWithArray[a*2+6]
			&&DoWithS[DoWithvalue-1].what!=DoWithArray[a*2]&&DoWithArray[a*2]!=0&&DoWithArray[a*2-1]!=DoWithArray[a*2+1]&&DoWithArray[a*2-3]!=DoWithArray[a*2-1])
			{
				DoWithS[DoWithvalue].what=DoWithArray[a*2];
				DoWithS[DoWithvalue].howmany=3;
				DoWithvalue++;
				}
	}
}
int DupliDoWith(int x,int y)
{
	int b=1;
	int a=0;
	for(a=0;a<x;a++)
 	b|=(DoWithArray[y*2]==DoWithArray[y*2+2+a*2]);
	return b;
}

int ddd=0;
void rx12(void)
{
	volatile unsigned int a,b=0,c=0,tempNum;
	for (a=0;a<rdata[Startcharlen];a++)
	{
		c=0;
		tempNum=rdata[a*2+Startcharlen+2];//10
		tempNum|=rdata[a*2+Startcharlen+3]<<8;
		for (int d=0;d<collectlen;d++)
		 if((tempNum&0x0fff)>start12[d]&&(tempNum&0x0fff)<last12[d])
				{
					if (tempNum&0x8000)
					{
						for (b=0;b<150;b++)
						{
						if(((tempNum&0x0fff)+1)==rdata3[b])
						c=1;
						}
						if (c==0)
						{
							hei[0]=(tempNum&0x0fff)+1;
							rdata3[Quest_len_int(rdata3)]=(tempNum&0x0fff)+1;
						}
					}
					else
					cut((tempNum&0x0fff)+1);
				}
			
	}
	ddd++;
	for (a=0;a<size;a++)
	{
		rdata[a]=0;
	}
}

	
void searchF(void)
{


	
	volatile unsigned int a=0,b=0,c=0,d=1,e,n=0,o_count=0,temp,tempa=0,tempb=0,tempc=0;//f是条件后几个不发
//	if(1==m)return;
//	if(1==i){i=0;return;}

/*	pthis=head;
	if(head==NULL)
	{
	return;
	}*/
	if (rdatacache[0][0]!=0)
	{
		return;
	}
	for (a=0;a<80;a++)
	DoWithArray[a]=0;
	for (a=0;a<8;a++)
	{DoWithS[a].howmany=0;DoWithS[a].what=0;}
	DoWithTiaoJian(rdata3);
while(o_count<CON2_LENGTH)
	{
	
		if(DEVIDE<o_count)break;//前45个条件
		if(find(rdata3,conditon2[o_count][0])&&find(rdata3,conditon2[o_count][1])&&find(rdata3,conditon2[o_count][2]))//上下行边上
		n=1;
		else n=0;   
		//头一个为不符合条件选项
		/*if(pthis->con[0]!=255)
		{
		b=0;
			for(a=0;a<DELAY;a++)
			{
			{b|=(rdata3[a]==pthis->con[0]);}
			}
 		if(b==1)n=0;
		}*/

		//////////////////////成功//1进来factor1=0通过
		if(n==1)
		{
		//4个方向的轨道成功
			for (a=0;a<8;a++)
			{
			d=0;
			tempa=0;
			if(factor[o_count].what)// 中间白色有了就不成功
				{d=1;}//轨道边
		  /*if (tempb==5&&0==d)//5的时候用来写两边的两个
			{
				//factor[o_count].howmany=tempb;
				//factor[o_count].what=tempc;
				Bcast[5][0]=0;
				Bcast[5][1]=0;
				Bcast[5][2]=0;
				bcastflag=1;
			}*/
			
			if(DoWithS[a].what!=0)//5 4 不成功  4  5 成功
			{for (c=0;c<20;c++)
				if(DoWithS[a].what==factor[c].what)
					if(DoWithS[a].howmany<=factor[c].howmany//4<5
					||(5==factor[c].howmany&&7==DoWithS[a].howmany))d=1;//轨道中报完5报7
			}
			else d==1;
			
			/*if (bcastflag==1&&bcastnum==a)
			{
				d=0;
				bcastflag=0;
			}*/			
				if(d==0&&DoWithS[a].howmany!=0)
 				{
				
				if (conditon2[o_count][3]==0&&DoWithS[a].howmany!=6)
				{
				//        不亮则通过                    //
			//	if(find(rdata3,signal[1])&&o_count==1&&(DoWithS[a].howmany!=5||find(rdata3,signal[3])))//非红灯//调车
			//  if(!find(rdata3,signal[3])||o_count!=3||(DoWithS[a].howmany==5&&!find(rdata3,signal[1])))//非红灯
				//	{
						tempb=DoWithS[a].howmany;
						tempc=DoWithS[a].what;
						bcastnum=a;
						uart_sendB(DoWithS[a].howmany);
						uart_sendB(DoWithS[a].what);
						uart_sendB(o_count);
						uart_sendB(temp);
						
						if (DoWithS[a].howmany==3||DoWithS[a].howmany==7)
						tempa+=100;
						else if(DoWithS[a].howmany==4)
						tempa+=20;
						else if(DoWithS[a].howmany==5)
							if(o_count<=CON2_DEVIDE)
							tempa+=40;
							else
							tempa+=140;
						
					    tempa+=DoWithS[a].what;
						
						//tempa+=50;
					
						if(tempa<=100/*&&o_count==1*/)
						add2Bcast(tempa,0,253);//女
						else
						add2Bcast(tempa,0,254);//男
						uart_sendB(tempa);
						uart_sendB(0xFF);
						factor[o_count]=DoWithS[a];
						
							for (e=0;e<CON2_LENGTH;e++)
							{
							if(find(rdata3,conditon2[e][0])&&find(rdata3,conditon2[e][1])
							&&find(rdata3,conditon2[e][2])&&conditon2[e][3]==1&&factor[e].what==0)
							factor[e]=factor[o_count];
							}
							for (e=0;e<CON2_LENGTH;e++)
							{
								if(factor[e].what==factor[o_count].what)
								factor[e].howmany=factor[o_count].howmany;
							}
				
					//}
				}
				if (conditon2[o_count][3]==1&&DoWithS[a].howmany!=6)
				{
				//		4 1 1	5 1 0	3 1 0
				//		4 2 0	5 2 1	3 2 1
				
				//if(!find(rdata3,signal[3])||o_count!=3||(DoWithS[a].howmany==5&&!find(rdata3,signal[1])))//非红灯
				//	{
					
						tempb=DoWithS[a].howmany;
						tempc=DoWithS[a].what;
						bcastnum=a;
					uart_sendB(DoWithS[a].howmany);
					uart_sendB(DoWithS[a].what);
					uart_sendB(o_count);
					uart_sendB(temp);
						if (DoWithS[a].howmany==3||DoWithS[a].howmany==7)
						tempa+=0;
						else if(DoWithS[a].howmany==4)
						tempa+=120;
						else if(DoWithS[a].howmany==5)
						if(o_count<=CON2_DEVIDE)
						tempa+=140;
						else						
						tempa+=40;
						
						tempa+=DoWithS[a].what;
					
						if(tempa<=100/*&&o_count==2*/)
						add2Bcast(tempa,0,253);//改成131
						else 
						add2Bcast(tempa,0,254);
						uart_sendB(tempa);
						uart_sendB(0xFF);
						factor[o_count]=DoWithS[a];
				
					for (e=0;e<CON2_LENGTH;e++)
					{
						if(find(rdata3,conditon2[e][0])&&find(rdata3,conditon2[e][1])
						 &&find(rdata3,conditon2[e][2])&&conditon2[e][3]==0&&factor[e].what==0)
						factor[e]=factor[o_count];
					}
					for (e=0;e<CON2_LENGTH;e++)
					{
						if(factor[e].what==factor[o_count].what)
						factor[e].howmany=factor[o_count].howmany;
					}
					//}
				}
				}	
			}						
		}
	if (factor[o_count].howmany==6)
	{
		factor[o_count].howmany=0;
		factor[o_count].what=0;
	}
	
	o_count++;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////


//////////////////////////////////////////
//                                      //
//                main                  //
//                                      //
//////////////////////////////////////////	
void get_mcusr(void)
{
	MCUSR = 0;
	wdt_disable();
}
unsigned char rxbuffer[32];
int main(void)
{ 
	
	
	volatile unsigned int a,b=0,c=0,d=0,e;
	volatile unsigned char temp;
	get_mcusr();
	Init_MCU( );
	Init_SPI( );
	Timer_Init();
//	EEPROM_write(0xcd,0x2e);
	USART0_Init(); 
	USART1_Init();
	L01_CE_LOW( );
	L01_Init();
	L01_SetTRMode(TX_MODE );
	L01_WriteHoppingPoint( 0 );

/*	LED_ON
	if (EEPROM_read(1)==0xFF)
	_delay_ms(1000);
	if(UCSR0A&(1<<RXC0))
	{b=UDR0;
	if(b==0xff)
	for (e=0;e<2000;e++)  
	EEPROM_write(e,0xff);
	}*/
  	LED_OFF

//	str_send(luxj);
	
	#if TEST==3
	while(1)
	rxdata();
	#elif TEST==2
	while(1)
	{LED_ON
		b=send_int(11,13,14);
		_delay_ms(1000);
		LED_OFF
	_delay_ms(1000);}
	#elif TEST==1
	while(1)
	{uart_sendB(0xaa);
	_delay_ms(100);}
	#elif TEST==3
	if (EEPROM_read(1)==0xFF)
	{
	input_usart();
	j=0x800;
	while(*j!=0xED)
	EEPROM_write(d++,*j++);
	uart_sendB(0x2e);
	LED_OFF//上一个在input_usart里
	}
	#endif
	/*if (EEPROM_read(1)!=0xFF)
	{
	EEPROM_write(0,0x3c);
	input_rom();
	LED_TWINKEL//init complete
	}
	else
	{
		LED_ON
		_delay_ms(2000);
		LED_OFF
		//while(1);
	}*/
UCSR0B |=(1<<RXCIE0);
UCSR1B |=(1<<RXCIE1);
LED_TWINKEL
hei[1]=head;
_PB0=1;
b=send_int(0,0,254);
_delay_ms(7000);
b=send_int(0,0,253);
_delay_ms(7000);


uart_sendB1(0x33);
uart_sendB1(0x33);
     while(1)
 {
	 if(rdata[1]==0x12)
	 rx0x12=0;
	 if(rdata[1]==0x11)
	 rx0x11=0;
	/*if (factor[1].what!=2)
	{
		factor[1].what=2;
	}*/
	if (hei[1]!=head)
	{
		head=hei[1];
	}
	if (sendcastflag==1)
	{
		sendcast();
		sendcastflag=0;
	}
	if (rdatacache[0][0]!=0&&rdata[0]==0)
	{
		for(a=0;a<cachelen1;a++)
		rdata[a]=rdatacache[0][a];
		for(b=0;b<cachelen;b++)
		for(a=0;a<cachelen1;a++)
		rdatacache[b][a]=rdatacache[b+1][a];
		rx0x12=0;
		/*
		for(a=0;a<15;a++)
		rdatacache[0][a]=rdatacache[1][a];
		for(a=0;a<15;a++)
		rdatacache[1][a]=rdatacache[2][a];
		for(a=0;a<15;a++)
		rdatacache[2][a]=rdatacache[3][a];
		for(a=0;a<15;a++)
		rdatacache[3][a]=rdatacache[4][a];
		for(a=0;a<15;a++)
		rdatacache[4][a]=rdatacache[5][a];
		for(a=0;a<15;a++)
		rdatacache[5][a]=rdatacache[6][a];
		for(a=0;a<15;a++)
		rdatacache[6][a]=rdatacache[7][a];
		for(a=0;a<15;a++)
		rdatacache[7][a]=rdatacache[8][a];*/
		rx0x12=0;
	}
	if (rdata[1]==0x11&&rx0x11==0)
	{

			Judge();
			rx0x11=1;
			searchF();
			searchL();
	}
	if (rdata3[10]==0)
	{
		hei[1]=rdata3[1];
	}
	if (rdata[1]==0x12&&rx0x12==0)
	{
	
	rx12();
	rx0x12=1;
	searchF();
	searchL();
	
//	sendcast();
	}
	
	
 }
	 return 0;
}


void searchL(void)
{
	volatile unsigned int a,b,c;
	for(c=0;c<CON_LENGTH;c++)
	{
		if (conditon[c][4]==0)
		{
			if (find(rdata3,conditon[c][0])&&(!find(rdata4,conditon[c][0]))&&find(rdata3,conditon[c][3]))
			{
				add2Bcast(conditon[c][1],0,conditon[c][2]);
				addto4(conditon[c][0]);
				//		uart_sendB(conditon[c][1]);
			}
		}
		else if (find(rdata3,conditon[c][0])&&(!find(rdata4,conditon[c][0])))//接近 轨判断||lqg
			{
				if(conditon[c][2]%2==0)a=160;else a=60;
				b=0;
				if (factor[conditon[c][4]].howmany==4||factor[conditon[c][4]].howmany==5)
				{
				b=factor[conditon[c][4]].what;
				if (factor[conditon[c][4]].howmany==5)a+=20;
				a+=b;}
				else a=0;
				
				add2Bcast(conditon[c][1],a,conditon[c][2]);
				addto4(conditon[c][0]);
				//	uart_sendB(101);
			}
		
	}
}


//322 321 330 312 4fa
/*	TIMSK2&=~((1<<TOIE2)|(1<<OCIE2A)|(1<<OCIE2B));
	ASSR |= (1<<AS2); //set Timer/Counter0 to be asynchronous
	TIMSK2 |= (1<<TOIE2); 
//	MCUCR = 0x70;//16有区别 //entering sleeping mode: power savSM 2 51e mode
	TCCR2B=0x05; // Write dummy value to Control register//分频
	TCNT2=0x00;		*/
		

//	Timer_Init();