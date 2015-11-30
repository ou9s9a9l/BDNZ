/*
 * main.c
 *
 * Created: 2015/11/21 10:47:30
 *  Author: xiao
 */ 
#define SELECT 2010

#define size_array 470

#include "voice.h"
#include "define.h"

 
 short signalflag;
 unsigned char rdatacache[cachelen+1][cachelen1];
 char rdata[size_array];

 //unsigned char rdatacache[cachelen+1][cachelen1];
  int m_freedelay;	
 unsigned short rdata3[300]={0};
 unsigned short factor[5][4];
 void get_mcusr(void)
 {
	 MCUSR = 0;
	 wdt_disable();
 }
 void test(void)
 {
	 short t,a;
	 searchL();
	 cache_clear();
	 search_single(0);
	 search_single(37);
	 for(a=0;a<=80;a++)
	 if(a!=0 && a!=37)
	 search_single(a);
	 
 }
 #define TEST 0
 
 
int main(void)
{ 

	short f = 0;
	volatile unsigned int a,b=0,c=0,d=0,e;
	volatile unsigned char temp;

	/*RamVar[1][0]=s[3][0];
	RamVar[1][1]=s[3][1];
	RamVar[1][2]=s[3][2];*/
	factor[1][2] = 1084;
	factor[2][2] = 1034;
	factor[3][2] = 986;
	factor[4][2] = 1038;

		get_mcusr();
	Init_MCU( );
	_PC6=0;
	Init_SPI( );
	Timer_Init();
//	EEPROM_write(0xcd,0x2e);
	USART0_Init(); 
	USART1_Init();
	L01_CE_LOW( );
	L01_Init();
	L01_SetTRMode(RX_MODE );
	L01_WriteHoppingPoint( 0 );
	L01_FlushRX( );
	L01_FlushTX( );

	#if TEST==2//���Ʋ���
	

	// strcpy(rdata,"837246281973469182734613987461923874");
	
	
	while(1)
	{
		_PB1 = !_PB1;//red
		_PB0 = !_PB0;//green
		_delay_ms(200);
	}
	#elif TEST==5
	while(1){
		unsigned char a = 0;
		uart_sendB1(0xff);
		uart_sendB1(0xDD);
		uart_sendB1(0x00);
		uart_sendB1(0xfe);
		uart_sendB1(0xff);
		//while(a++<1)
		_delay_ms(3000);
	//	_delay_ms(5000);
	//	_delay_ms(5000);
	}
	#elif TEST==3
	
	while(1)
	{
		send_int("789");
		_delay_ms(1000);
		if(_PB1==1)
		_PB1 = 0;//red
		else
		_PB1 = 1;
	}
	//L01_CE_HIGH( );
	rxdata();
	#elif TEST==4
	while(1)
	{
		unsigned char buffer[5]={"123"};
		L01_CE_HIGH( );
		//L01_FlushRX( );
		//L01_FlushTX( );	
		//L01_WriteRXPayload_InAck(buffer,3);
		rxdata();
		if(_PB1==1)
		_PB1 = 0;//red
		else
		_PB1 = 1;
	}
	#elif TEST==1
	unsigned char count = 0;
	while(1)
	{
	if(count==255)count=0;
	//send_moni(254,0,count);
	_delay_ms(100);
	send_moni(254,0,0);
	count++;
	if(_PB1==1)
	_PB1 = 0;//red
	else
	_PB1 = 1;
	
	
	
	
	_delay_ms(5000);
	}
	
	#endif

 // send_moni(254,0,0);

_PB1 = 0;
	_PB0 = 0;
	//send_moni(142,0);
     while(1)
 {
	 
	
		if(rdata[0]!=0)
		{
			_PB0 = !_PB0;//green
			m_freedelay++;
			Judge();
			test();

		}
		if(rdatacache[0][0]!=0)
		{
			//_delay_ms(10);
			_PB0 = !_PB0;//green
			while(rx12()!=0&&rdatacache[0][10]==3);
			test();
		}
		if(m_freedelay>=2)
		{
			send_moni(0,0);
			m_freedelay=0;
		}
	
 
	//sendcast();

	
 }
	 return 0;
}