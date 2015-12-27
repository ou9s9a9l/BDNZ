/*
 * ISR.c
 *
 * Created: 2015/9/8 11:07:55
 *  Author: xiao
 */ 

#define SELECT 2010
#include "voice.h"
#include "define.h"
unsigned short CRC1(char* pBuf,short Len);
unsigned int m_save,m_crc;
//#define count_times 6

short count_oyx = 0;


unsigned char rdatatemp[size_array];

extern char rdatacache[cachelen+1][cachelen1];
extern char rdata[size_array];
extern unsigned char rxbuffer[32];
extern unsigned char trx;//0 rx 1 tx
extern int six_second ;
int rxflag=0,succflag=0,count=0,resetflag=0,flag_oyx = 0;

ISR(USART0_RX_vect)
{	
	unsigned char temp;
	six_second = count_times;
	if (READ_PA1==0)
	_PA1=1;
	else
	_PA1=0;
	if(UCSR0A & (1<<RXC0))
	temp=UDR0;
	count_oyx++;
	handle_data(temp);
}
ISR(PCINT1_vect)
{
	unsigned char width;
	if(READ_PB3==0&&trx == 0)
	
	{
	width = rxdata();
	//uart_sendB(0x00);
	L01_CE_HIGH( );
	PCIFR = 0x0f;
	for(unsigned int a = 0;a<width;a++)
	{//uart_sendB(rxbuffer[a]);
	handle_data(rxbuffer[a]);}
	L01_CE_HIGH( );
	}


	/*int a=0,b=0;
	while(rxbuffer[a])
	*/
}
void handle_data(unsigned char temp)
{
	short a=0,b=0;
	if(temp==0x01)succflag=1;

	
	//if(1==count&&temp==0x14)
	//{sendcastflag=1;}
	if(1==count&&(temp==0x14||temp==0x15))
	{
		succflag=0;count=0;return;
	}
	#if SELECT==2009						   //????zyz
	if(1==count&&(temp==0x14||temp==0x11))
	{
		succflag=0;count=0;return;
	}
	#endif
	//if(1==count&&(temp==0x11||temp==0x12))LED_ON
	if (count>(size_array-10))
	{
		for (a=0;a<size_array;a++)
		rdatatemp[a]=0;
		succflag=0;
		count=0;
	}
	

	if(succflag)
	{
		rdatatemp[count]=temp;
		
		
		if (rdatatemp[count]==0x03)
		{

			
		
			
			
			m_save=CRC1(rdatatemp,count-2);
			m_crc=rdatatemp[count-1];////////////12 27¸Ä
			m_crc<<=8;
			m_crc|=rdatatemp[count-2];
			if(m_save!=m_crc||m_crc==0)
			{
				for (a=0;a<=count;a++)
				rdatatemp[a]=0;
			}
			
			#if SELECT==2006||SELECT==2010						   //????zyz
			
			if(rdatatemp[0]==0x01)
			for ( a=0;a<=count;a++)
			rdata[a]=rdatatemp[a];

			
			#endif
			#if SELECT==2009				   //????zyz
			
			if(rdatatemp[1]==0x22)
			{
				if(rdata[0]==0)
				{for ( a=0;a<=count;a++)
					{
						rdata[a]=rdatatemp[a];
					}
				rx0x11=0;}
			}
			#endif
			
			if(rdatatemp[1]==0x12)
			{
				b=0;
				if(rdatacache[0][0]!=0)
				for (b=0;b<cachelen;b++)
				{
					if(rdatacache[b][0]==0)
					break;
				}
				if(b>=flag_oyx)
				flag_oyx=b;
				for ( a=0;a<=count;a++)
				rdatacache[b][a]=rdatatemp[a];
				
			}
			
			

			
			
			
			count=-1;
			succflag=0;

			for (a=0;a<=count;a++)
			rdatatemp[a]=0;
		}
		if (rxflag==1)      				          //????
		switch(rdatatemp[count])
		{
			case 0x81: rdatatemp[count-1]=0x01;count--;rxflag=0;break;
			case 0x83: rdatatemp[count-1]=0x03;count--;rxflag=0;break;
			case 0x90: rdatatemp[count-1]=0x10;count--;rxflag=3;break;
			default:rxflag=0;break;
		}
		if (rdatatemp[count]==0x10&&rxflag!=3)
		rxflag=1;     //??????
		else rxflag=0;
		count++;
		//?????
	}
	// LED_OFF
}


unsigned short CRC1(char* pBuf,short Len)
{
	unsigned short CRC1 = 0;
	unsigned char R;
	short i,j,k,m;
	CRC1=0;
	if(Len<=0) return 0;
	for(i=1;i<Len;i++)    {
		R=pBuf[i];
		for(j=0;j<8;j++)
		{
			if (R>127) k=1;else k=0;
			R<<=1;
			if(CRC1>0x7fff) m=1;	else m=0;
			if (k+m==1) k=1; 	else k=0;
			CRC1<<=1;
			if (k==1) CRC1^=0x1021;
		}
	}
	return CRC1;
}