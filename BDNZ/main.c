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
extern unsigned char remote_sendflag ;
 //unsigned char rdatacache[cachelen+1][cachelen1];
  int m_freedelay;	
 unsigned short rdata3[300]={0};
 extern unsigned short factor[5][4];
 void get_mcusr(void)
 {
	 MCUSR = 0;
	 wdt_disable();
 }
 void test(void)
 {
	 short t=0,a;
	 searchL();
	 cache_clear();
	 t = get_len();
	// search_single(0);
	// search_single(11);
	 for(a=0;a<t;a++)
	// if(a!=0 && a!=11)
	 search_single(a);
	 
 }
  short Change(char s[],char bits[]);
  char str[] = "0112140009003F006A806E00438252828D82BF02C7021F8363C003";
  char str1[]= "0111cd006595596aa922222111417032a9e064420400824056ffc000021900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000084000100000000000000000000006a5610541044410120a20a0000080000080000080000080000080000080000080000080000080000082011802a030104000000000000000000eff51802f1730300006a56001c000000000000000000000000000000000000000050a002000000000080000000000000000000c1c703";
 void chan(void)
 {
	 Change(str,rdatacache[0]);
 }
  void chan1(void)
  {
	  Change(str1,rdata);
  }

 short Change(char s[],char bits[]) {
	 short i,n = 0;
	 for(i = 0; s[i]; i += 2) {
		 if(s[i] >= 'A' && s[i] <= 'F')
		 bits[n] = s[i] - 'A' + 10;
		 else bits[n] = s[i] - '0';
		 if(s[i + 1] >= 'A' && s[i + 1] <= 'F')
		 bits[n] = (bits[n] << 4) | (s[i + 1] - 'A' + 10);
		 else bits[n] = (bits[n] << 4) | (s[i + 1] - '0');
		 ++n;
	 }
	 return n;
 }
 #define TEST 0
 
 
int main(void)
{ 
	
	short f = 0;
	volatile unsigned int a,b=0,c=0,d=0,e;
	volatile unsigned char temp;
//	chan1();
//	chan();
	/*RamVar[1][0]=s[3][0];
	RamVar[1][1]=s[3][1];
	RamVar[1][2]=s[3][2];
	factor[1][2] = 356;//xjg
	factor[2][2] = 324;//sjg
	factor[3][2] = 368;//slg
	factor[4][2] = 352;//xlq*/
get_len();
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
	//send_moni(0,0,0);
	#if TEST==2//ÁÁµÆ²âÊÔ
	

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
	if(count==200)count=0;
	//send_moni(254,0,count);
	_delay_ms(100);
	send_moni(count,0);
	count++;
	
	
	
	
	_delay_ms(6000);
	_delay_ms(6000);
	}
	
	#endif

 // send_moni(0,0,1);

_PB1 = 0;
	_PB0 = 0;
	//send_moni(142,0);
	//send_moni(254,0);
     while(1)
 {
	 
	
		if(rdata[0]!=0)
		{
			if(remote_sendflag == 1)
			send_to_server(rdata,212);
			_PB0 = !_PB0;//green
			m_freedelay++;
			Judge();
			test();

		}
		if(rdatacache[0][0]!=0)
		{
			//_delay_ms(10);
			_PB0 = !_PB0;//green
			if(remote_sendflag == 1)
			send_to_server(rdatacache[0],cachelen1);
			while(rx12()!=0&&rdatacache[0][10]==3);
			test();
		}
		if(m_freedelay>=2)
		{
			send_moni(0,0,0);
			m_freedelay=0;
		}
	
 
	//sendcast();

	
 }
	 return 0;
}