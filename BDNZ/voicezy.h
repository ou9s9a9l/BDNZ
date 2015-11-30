/*
 * voice.h
 *
 * Created: 2014/7/19 13:07:41
 *  Author: oyx
 */ 


#ifndef VOICE_H_
#define VOICE_H_





#endif /* VOICE_H_ */

void send_char(unsigned char *testbuffer);
unsigned char DoWithTiaoJian(unsigned int *rdat);
void searchL(void);
    
#include <avr/pgmspace.h>

#define N  8
#define DELAY 50
#define DEVIDE 9
#define ConSize 7
#define SentSize 2
/*
#define start 122//judge接收
#define last  210
#define start12 975
#define last12  1515*/
#define Startcharlen 4
#define SELECT 2009
#define collectlen  4
const unsigned int start1[collectlen]={0,95,137,380/*,625,770*/};
const unsigned int last1[collectlen]={35,110,150,393/*,640,820*/};
const unsigned int start12[collectlen]={8/*,78,96*/};
const unsigned int last12[collectlen]={640/*,80,103*/};

#define TEST  0//test 2 3个语音  test1 发送串口0xff test3 输入数据 0正常
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



const unsigned int x_jinzhan[2][2]= {
	{170,174},{188,204}//1
};
#define CON_LENGTH 18
const unsigned int	conditon[CON_LENGTH][5]={//轨道位，语音位，男女平南上下行位（1下2上），后续factor位
								{266,205,253},//x1lq
								{267,206,253},//x2lq
								{268,207,253},//x3lq
								{260,215,254},//s1lq
								{261,216,254},//s2lq
								{262,217,254},//s3lq
								{263,211,254,0,2},//{1171,211,254,0,2},//s1jg
								{264,212,254,0,2},//{1173,212,254,0,2},//s2jg
								{265,213,254,0,2},//{1167,213,254,0,2},//s3jg
								{257,201,253,0,1},//x1jg
								{258,202,253,0,1},//x2jg
								{259,203,253,0,1},//x3jg
								{2,204,253,39,1},//下进站3-7
								{15,214,254,55,2},//上进站4-8
								{1125,222,254},//2382
				
								{1161,223,254},//2488

								{1119,224,254},//2473

								{1177,225,254}//2365
								//{222,226,254},//2379
								//{2455,208,254}//1419
									//21
};
#define CON2_DEVIDE 2
#define CON2_LENGTH 5//0左1右
const unsigned int	conditon2[CON2_LENGTH][5]={{65535,0},
								{786,39,41,0},//3-7
								{795,55,57,1},//4-8
								{810,0,0,0},//IIAG
								{823,0,0,1}};//IBG
unsigned char bcastflag=0,bcastnum=0,sendcastflag=0;	
 //定义uchar型的常量n定义在flash里(flash常量)
									
#define  LENGTH 6
#define  LENGTH1 6
const unsigned int x_left[LENGTH][8]= {
		  {0,0},{39,41,43,45},//1	
			    {39,41,43,46,51},//2
				{39,41,44,49},//3
				{39,41,43,46,52},//4//
				{39,41,44,50},//5
										
};
const unsigned int x_right[LENGTH][8]={
		  {0,0},{55,57,60,61},//1	
			    {55,57,59,63},//2
				{55,57,60,62,65},//3
				{55,57,59,64},//4
				{55,57,60,62,66},//5
		
};
const unsigned int x_left1[LENGTH1][8]= {
		  {0,0},{40,41,43,45,00,0,170,174},//1	d9 d11
			    {39,45,51,00,00,0,170,164},//2	d3 d9
				{40,41,44,49,00,0,170,174},//3
				{39,45,52,45,52,0,170,164},//4
				{40,41,44,50,00,0,170,174},//5
										
};
const unsigned int x_right1[LENGTH1][8]={
		  {0,0},{55,59,61,0,0,0,202,206},//1  d24 d28
			    {56,57,59,63,0,0,188,204},//2 d10 d26
				{55,59,62,65,0,0,202,206},//3
				{56,57,59,64,0,0,188,204},//4
				{55,59,62,66,0,0,202,206},//5
		
};
const unsigned int x_left_no[LENGTH1][8]= {
	{0,0},{109,0,0},//1	d9 d11
	{115,0,0},//2	d3 d9
	{121,0,0},//3
	{126,0,0},//4
	{131,0,0},//5
	
};
const unsigned int x_right_no[LENGTH1][8]={
	{0,0},{136,0,0},//1  d24 d28
		  {142,0,0},//2 d10 d26
		  {148,0,0},//3
		  {153,0,0},//4
		  {158,0,0},//5
	
};
const unsigned int x_left1_no[LENGTH1][8]= {
	{0,0},{109,0,0},//1	d9 d11
	{115,0,0},//2	d3 d9
	{121,0,0},//3
	{126,0,0},//4
	{131,0,0},//5
	
};
const unsigned int x_right1_no[LENGTH1][8]={
		{0,0},{136,0,0},//1  d24 d28
		{142,0,0},//2 d10 d26
		{148,0,0},//3
		{153,0,0},//4
		{158,0,0},//5
		
};
const unsigned int x_middle[LENGTH][7]={
		{0},{788,799,34,34,830,830,830},//1 red w
			{792,801,35,35,831,831,831},//2
			{789,803,36,36,832,832,832},//3
			{793,802,37,37,833,833,833},//4
			{789,803,38,38,834,834,834},//5
						
};

#define cachelen 1
#define cachelen1 60
volatile char rdatacache[cachelen+1][cachelen1]={0};

