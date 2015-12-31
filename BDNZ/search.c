/*
 * search.c
 *
 * Created: 2015/11/21 10:39:54
 *  Author: xiao
 */ 
//#include "bdn.h"
//#include "ryz.h"
#include "mtz.h"

//#include "bdn1.h"
/*
unsigned short dat5[][12];
unsigned short dat3[][12];
unsigned short dat4[][12];
unsigned short dat2[][12];
unsigned short dat1[][8];	
unsigned short dat0[][10];*/
//#include "bdn_txt.h"

unsigned char err[50];
extern unsigned short rdata3[300];
extern unsigned char find(unsigned short *rdat,unsigned short source);
unsigned char flag_8 = 0;
unsigned char flag_9 = 0;
unsigned short flag1 = 0;
unsigned char Quest_len_int(unsigned short *Par);
unsigned char search(unsigned short *condition,unsigned char flag);
unsigned char temp = 0;
//unsigned short hei=0;
void show_str(unsigned char *str);
void cache_plus(unsigned char num);
void board_num(unsigned char num);



void searchL(void)
{
	unsigned short a,b,temp,c;
	for(c=0;c<CON_LENGTH;c++)
	{
		if (find(rdata3,conditon[c][0])&&find(rdata3,conditon[c][4]))
		{
			if(conditon[c][3] == 0)
			{
				//show_str(txt[conditon[c][1]]);//??¡À¡§
				if(conditon[c][2] != 0)
				{temp = factor[conditon[c][2]][0]+40;
				if(temp != 40 )
				send_moni(conditon[c][1],temp,0);
				else
				{
					
					if(c!=0&&c!=1)//jinzhan  yidingyao you shuzi 
						//send_moni(conditon[c][1],0,0);
					if(c==2)
						if(find(rdata3,821))//IIAG-H
						send_moni(219,0,0);
						else
						send_moni(208,0,0);
					if(c==3)
						if(find(rdata3,829))//IIBG-H
						send_moni(209,0,0);
						else
						send_moni(218,0,0);
					
				}
				
				}
				else
				send_moni(conditon[c][1],0,0);
				
				
				conditon[c][3]+=2;
			}
			
				
			conditon[c][3]++;
		}
		if(conditon[c][3] == 0)
		conditon[c][3] = 0;
		if(conditon[c][3]>0)
		conditon[c][3]--;
	}
	
	
}
void read_dat0(unsigned short *RamVar,unsigned char num)
{
	for(char a = 0;a<15;a++)
	RamVar[a]=0;
	unsigned short b;
	for(char a = 0;a<15;a++)
	{
		b=pgm_read_word(&dat0[num][a]) ;
		if(b!=0)
		RamVar[a]= b ;
		else
		break;
	}
}
/*void read_dat1(unsigned short *RamVar,unsigned char num)
{
	for(char a = 0;a<15;a++)
	RamVar[a]=0;
	unsigned short b;
	for(char a = 0;a<15;a++)
	{
		b=pgm_read_word(&dat1[num][a]) ;
		if(b!=0)
		RamVar[a]= b ;
		else
		break;
	}
}*/
void read_dat2(unsigned short *RamVar,unsigned char num)
{
	for(char a = 0;a<15;a++)
	RamVar[a]=0;
	unsigned short b;
	for(char a = 0;a<15;a++)
	{
		b=pgm_read_word(&dat2[num][a]) ;
		if(b!=0)
		RamVar[a]= b ;
		else
		break;
	}
}
unsigned short get_len()
{
	unsigned short t = 0;
	t=sizeof(dat3)/2;
	return t;
}
volatile unsigned char result=1,result1 = 1;
///////////////////////////////////////ÐÅºÅ¿ª·Å
unsigned short search_single(unsigned char num)
{
	unsigned short dat[15]={0};
	unsigned short a;
	result=1;result1=1;
	result1 &= ( search(dat5[num][0],2)&&search(dat5[num][1],2) );
	if(result1==0){err[num]=1;return 0;}
	read_dat0(dat,num);
	result &= search(dat,1);//???¨ª
	if(result==0){err[num]=2;return 0;}
	//read_dat1(dat,num);
	//result &= search(dat,0);//????????
	//if(result==0)return 0;
	read_dat2(dat,num);
	result &= search(dat,1);//???¨¬
	if(result==0){err[num]=3;return 0;}
	
	if(result==1&&result1==1)//success ???¨ª
	{
		if(dat3[num]>factor[dat4[num][0]][0])
		{
			factor[dat4[num][0]][0] = dat3[num];
			if(dat4[num][1]!=0)
			factor[dat4[num][1]][0] = dat3[num];
			//if(a==0 || a==37)
			//for(a = 0;a<30;a++);
			//cache_plus(num);//
			//factor[dat4[num][1]][3] = 1;
			
			if(dat4[num][0]>=4)
			send_moni(dat3[num],0,1);
			else
			send_moni(dat3[num],0,0);
			board_num(num);//
		}
		if(dat3[num] == factor[dat4[num][0]][0])
		cache_plus(num);
		{err[num]=0xff;return 1;}
	}
}
void board_num(unsigned char num){
	//show_str(txt[dat3[num]]);//??¡À¡§
}
void cache_plus(unsigned char num)
{
	factor[dat4[num][0]][1]++;	//success ?¨¢??
	if(dat4[num][1]!=0)
	factor[dat4[num][1]][1]++;
}
void cache_clear(void)
{
	unsigned char a;
	for(a=0;a<5;a++)
	if(factor[a][1] == 0 && !find(rdata3,factor[a][2]))
	factor[a][0] = 0;
	for(a=0;a<5;a++)
	if(factor[a][1]>0)
	factor[a][1]--;
}
///////////////////////////////////api/////////////////////////////////
unsigned short point = 0;
void show_str(unsigned char *str)
{
	if(point == 270) {point=0;}
	//LCD_ShowString(30,point+30,200,16,16,"                         ");		//??LCD ID
	//LCD_ShowString(30,point,200,16,16,str);		//??LCD ID
	point+=30;
}
// flag :1???????? 0 ?????????? 2???¨°??
unsigned char search(unsigned short *condition,unsigned char flag)
{
	unsigned short len=0,a;
	unsigned char result;
	len = Quest_len_int(condition);
	if(flag == 1)
	{
		result = 1;
		for(a=0;a<len;a++)
		result&=find(rdata3,condition[a]);
	}
	
	if(flag == 0)
	{result = 0;
		for(a=0;a<len;a++)
		result|=find(rdata3,condition[a]);
		if(result == 1)result=0;else result = 1;
	}
	
	if(flag == 2)
	{result = 0;
		if(len==0)len = 1;
		for(a=0;a<len;a++)
		result|=find(rdata3,condition[a]);
	}
	return result;
	//
	//search(dat1[0]);
	//len++;
	//	 len = find(rdata3,0);
}