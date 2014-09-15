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
#define size 470
#define N  8
#define DELAY 50
#define DEVIDE 9
#define ConSize 7
#define SentSize 2
#define start 122//judge����
#define last  210
#define start12 975
#define last12  1515
#define TEST   0//test 2 3������  test1 ���ʹ���0xff test3 �������� 0����
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
}DoWithS[20],factor[20];




#define CON_LENGTH 10
const unsigned int	conditon[CON_LENGTH][5]={//���λ������λ����Ůƽ��������λ��1��2�ϣ�������factorλ
								{1169,205,253},//x1lq
								{1165,206,253},//x2lq
								{1163,207,253},//x3lq
								{1159,215,254},//s1lq
								{1171,211,254,0,2},//s1jg
								{1173,212,254,0,2},//s2jg
								{1167,213,254,0,2},//s3jg
								{1157,202,253,0,1},//x2jg
								{1083,204,253},//�½�վ
								{1033,214,254,1365},//�Ͻ�վ
									//21
};
#define CON2_LENGTH 5
const unsigned int	conditon2[CON2_LENGTH][3]={{65535,0},
								{1084,0},//IAG
								{1034,1365},//4dg
								{986,1225},//7-11
								{1038,1373}};//8dg}
unsigned char bcastflag=0,bcastnum=0,sendcastflag=0;	
const unsigned char PROGMEM  s[5] =  { 1, 2, 3, 4, 5 };  //����uchar�͵ĳ���n������flash��(flash����)
									
#define  LENGTH 15							
/*const unsigned int x_reserve[LENGTH][11]=//1��3�� 2��4�� 5���һ����6��7����8�ұߵ�һ����9��10��11�����
{ {0,0,0,0,0},	{1257,1425,0000,0000,996,1129,1129,1052,1130,1130,1130},//1
				{1313,1449,0000,0000,1014,1131,1131,1062,1132,1132,1132},//2
				{1269,1493,1258,1426,996,1133,1133,1068,1134,1134,1134},//3
				{1277,1497,1314,1450,1002,1135,1135,1078,1136,1136,1136},//4
				{1273,0000,1270,1494,1000,1137,1137,1068,1138,1138,1138},//5
				{1278,1510,0000,1498,1002,1139,1139,1078,1140,1140,1140},//6
				{1281,1466,1274,0000,1004,1141,1141,1072,1142,1142,1142},//7
				{1265,1509,1322,1498,998,1143,1143,1078,1144,1144,1144}, //8 
				{0,0,0,0,0},
				//{1293,1398,1282,1434,1012,1145,1145,1070,1146,1146,1146},//9 �ڶ���
				{1266,1501,0000,1490,998,1147,1147,1082,1148,1148,1148},//10
				{0,0,0,0,0},
				//{1294,1458,1305,0000,1010,1149,1149},	//11
				{1254,1505,1261,1502,994,1151,1151,1082,1152,1152,1152},//12
				{0,0,0,0,0},
				{1262,1506,1261,1502,994,1153,1153,1082,1154,1154,1154}};//14*/
const unsigned int x_left[LENGTH][3]= {
		  {0,0},{1257,0000},//1	
			    {1313,0000},//2
				{1269,1258},//3
				{1277,1314},//4
				{1273,1270},//5
				{1278,0000},//6
				{1281,1274},//7
				{1265,1322},//8
				{0000,0000},//9
				{1266,1322},//10
				{0000,0000},//11
				{1254,1261},//12
				{0000,0000},//13
				{1254,1262},//14								
};
const unsigned int x_right[LENGTH][3]={
		  {0,0},{1425,0000},//1	
			    {1449,0000},//2
				{1493,1426},//3
				{1497,1450},//4
				{1494,0000},//5
				{1498,1510},//6
				{1466,0000},//7
				{1509,1498,1485},//8
				{0000,0000},//9
				{1501,1490},//10
				{0000,0000},//11
				{1505,1502,1490},//12
				{0000,0000},//13
				{1506,1502,1490},//14
};
const unsigned int x_middle[LENGTH][7]={
		{0},{996,1052,1129,1129,1130,1130,1130},//1
			{1014,1062,1131,1131,1132,1132,1132},//2
			{996,1068,1133,1133,1134,1134,1134},//3
			{1002,1078,1135,1135,1136,1136,1136},//4
			{1000,1068,1137,1137,1138,1138,1138},//5
			{1002,1078,1139,1139,1140,1140,1140},//6
			{1004,1072,1141,1141,1142,1142,1142},//7
			{998,1078,1143,1143,1144,1144,1144},//8
			{0},//9
			{998,1082,1147,1147,1148,1148,1148},//10
			{0},//11
			{994,1082,1151,1151,1152,1152,1152},//12
			{0},//13
			{994,1082,1153,1153,1154,1154,1154},//14					
};

#define cachelen 25										  
volatile char rdatacache[cachelen+1][15]={0};