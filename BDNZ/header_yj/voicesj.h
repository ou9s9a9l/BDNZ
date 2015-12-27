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
#define Startcharlen 8
#define SELECT 2010

#define collectlen  3
const unsigned int start12[collectlen]={0,2000/*,625,770*/};
const unsigned int last12[collectlen]={240,2300/*,640,820*/};
const unsigned int start1[collectlen]={0,250/*,78,96*/};
const unsigned int last1[collectlen]={30,288/*,80,103*/};

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
								{2168,205,253},//x1lq
								{2171,206,253},//x2lq
								{2174,207,253},//x3lq
								{2189,215,254},//s1lq
								{2192,216,254},//s2lq
								{2195,217,254},//s3lq
								{2177,231,254},//2490
								{2180,211,254,0,1},//s2jg
								{2183,212,254,0,1},//s3jg
								{2186,213,254,0,1},//s3jg
								{2156,221,253},//2653
								{2159,201,253,0,2},//x2jg
								{2162,202,253,0,2},//x3jg
								{2165,203,253,0,2},//x3jg
								{66,214,254,0},//下进站
								{158,204,253,57},//上进站
									//21
};
#define CON2_DEVIDE 2
#define CON2_LENGTH 7
const unsigned int	conditon2[CON2_LENGTH][4]={{65535,0},
								{68,57,0,1},//IIBG
								{160},//3DG
								{112,1,0,1},//4DG 
								{108},//IIAG
								{65535,0},//12AG 
								{65535,0}};//IBG}
unsigned char bcastflag=0,bcastnum=0,sendcastflag=0;	
//const unsigned char PROGMEM  s[5] =  { 1, 2, 3, 4, 5 };  //定义uchar型的常量n定义在flash里(flash常量)
									
#define  LENGTH 15							

				
const unsigned int x_left[LENGTH][8]= {
		  {0,0},{17,5},//1	
			    {21,53},//2
				{18,5},//3
				{22,53},//4
				{26,6},//5
				{0},//6
				{25,6},//7
				{0},//8
				{0},//9
				{0},//10
				{0},//11
				{0},//12
				{0},//13
				{0},//14								
};
const unsigned int x_right[LENGTH][8]={
		 {0,0},{37,41},//1
			   {29,61},//2
			   {38,41},//3
			   {30,61},//4
			   {46,42},//5
			   {0},//6
			   {46,42},//7
			   {0},//8
			   {0},//9
			   {0},//10
			   {0},//11
			   {0},//12
			   {0},//13
			   {0},//14
};
const unsigned int x_middle[LENGTH][7]={
		{0},{120,144,86,86,88,88,88},//1
			{128,136,82,82,84,84,84},//2
			{120,144,90,90,92,92,92},//3
			{128,136,78,78,80,80,80},//4
			{132,152,94,94,96,96,96},//5
			{0},//6
			{132,152,98,98,100,100,100},//7
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