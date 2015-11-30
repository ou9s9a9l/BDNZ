/*
 * voice.h
 *
 * Created: 2015/9/8 11:14:57
 *  Author: xiao
 */ 


#ifndef VOICE_H_
#define VOICE_H_
#endif /* VOICE_H_ */
#include <avr/pgmspace.h>
//const unsigned char PROGMEM  s1[5] =  { 1, 2, 3, 4, 5 };  //定义uchar型的常量n定义在flash里(flash常量)
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <AVR/sleep.h>
#include <avr/wdt.h>
#include "nRF24L01.h"

//#include "nRF24L01_Reg.h"
#include "macr.h"
//#include "nRF24L01.h"
#define __DELAY_BACKWARD_COMPATIBLE__ 

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
//#define LED_OFF  _PA1=1;//pa0 green pa1 blue
//#define LED_ON  _PA1=0;
#define LED_TWINKEL {LED_ON;_delay_ms(1000);LED_OFF;_delay_ms(1000);}

#define count_times 6

#define size 470//470

#define size_array 470//470

