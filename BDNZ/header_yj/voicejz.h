/*
 * voice.h
 *
 * Created: 2014/7/19 13:07:41
 *  Author: oyx
 */ 

//双数白 单数红
#ifndef VOICE_H_
#define VOICE_H_





#endif /* VOICE_H_ */

void send_char(unsigned char *testbuffer);
unsigned char DoWithTiaoJian(unsigned int *rdat);
void searchL(void);

//#include <avr/pgmspace.h>
#define size 470
#define N  8
#define DELAY 50
#define DEVIDE 9
#define ConSize 7
#define SentSize 2
#define Startcharlen 4
#define SELECT 2010
#define USART0_SPEED 143//9600
#define collectlen  3
const unsigned int start12[collectlen]={354,1984/*,625,770*/};
const unsigned int last12[collectlen]={504,2040/*,640,820*/};
const unsigned int start1[collectlen]={44,248/*,78,96*/};
const unsigned int last1[collectlen]={63,255/*,80,103*/};

#define TEST   0//test 2 3个语音  test1 发送串口0xff test3 输入数据 0正常
struct word
{
	unsigned int con[ConSize];
	unsigned char sent[SentSize];
	struct word *next;
}*head,*pthis;
struct DoWith
{
	unsigned char howmany;
	unsigned int  what;
}DoWithS[8],factor[20];




#define CON_LENGTH 20
const unsigned int	conditon[CON_LENGTH][5]={//轨道位，语音位，男女平南上下行位（1下2上），后续factor位
								{1999,205,253},//x1lq
								{2003,206,253},//x2lq 257g
								{2007,207,253},//x3lq 271g
								{2020,215,254},//s1lq
								{2024,216,254},//s2lq 224g
								{2028,217,254},//s3lq 212g
								{2032,231,254},//198bg
								{2011,211,254,0,2},//s1jg 290g
								{2015,212,254,0,2},//s2jg 276g
								{2019,213,254,0,2},//s3jg 262g
							//	{2156,221,253},//2653
								{1988,201,253,0,1},//x1jg 187b
								{1993,202,253,0,1},//x2jg 203b
								{1998,203,253,0,1},//x3jg 219g
								{474,214,254,0,2},//上进站 IIBG
								{462,204,253,0,1}//下进站 IAG
								
								
									//21
};
#define CON2_DEVIDE 2
#define CON2_LENGTH 7
const unsigned int	conditon2[CON2_LENGTH][4]={{65535,0},
								{463,/*356*/},//IAG
								{475,0/*376,*/,0,1},//IIBG
								{467},//IIAG 
								{471,0,0,1},//IBG
								{65535,0},//12AG 
								{65535,0}};//IBG}
unsigned char bcastflag=0,bcastnum=0,sendcastflag=0;	
//const unsigned char PROGMEM  s[5] =  { 1, 2, 3, 4, 5 };  //定义uchar型的常量n定义在flash里(flash常量)
									
#define  LENGTH 15							

				
const unsigned int x_left[LENGTH][8]= {
		  {0,0},{364},//1	
			    {368},//2
				{365},//3
				{369,372},//4
				{0},//5
				{0},//6
				{0},//7
				{0},//8
				{0},//9
				{0},//10
				{0},//11
				{0},//12
				{0},//13
				{0},//14								
};
const unsigned int x_right[LENGTH][8]={
		 {0,0},{392,388},//1
			   {380},//2
			   {393,388},//3
			   {381,396},//4
			   {0},//5
			   {0},//6
			   {0},//7
			   {0},//8
			   {0},//9
			   {0},//10
			   {0},//11
			   {0},//12
			   {0},//13
			   {0},//14
};
const unsigned int x_middle[LENGTH][7]={
		{0},{411,447,486,486,487,487,487},//1 5-9DG-QB,12-16DG-QB , 4DG-QB	
			{483,435,489,489,490,490,490},//2 11DG-QB, 4DG-QB
			{411,447,492,492,493,493,493},//3
			{483,435,495,495,496,496,496},//4
			{0},//5
			{0},//6
			{0},//7
			{0},//8
			{0},//9
			{0},//10
			{0},//11
			{0},//12
			{0},//13
			{0},//14					
};

 unsigned int signal[4]={0,2,0,62};

#define cachelen 15	
#define cachelen1 15								  
volatile char rdatacache[cachelen+1][cachelen1]={0};