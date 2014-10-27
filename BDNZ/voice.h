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

//#include <avr/pgmspace.h>
#define size 470
#define N  8
#define DELAY 50
#define DEVIDE 9
#define ConSize 7
#define SentSize 2

#define collectlen  3
const unsigned int start12[collectlen]={0,975,2176/*,625,770*/};
const unsigned int last12[collectlen]={100,1515,2200/*,640,820*/};
const unsigned int start1[collectlen]={0,118,272/*,78,96*/};
const unsigned int last1[collectlen]={10,206,275/*,80,103*/};

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
}DoWithS[20],factor[20];




#define CON_LENGTH 10
const unsigned int	conditon[CON_LENGTH][5]={//轨道位，语音位，男女平南上下行位（1下2上），后续factor位
								{2187,205,253},//x1lq
								{2188,206,253},//x2lq
								{2189,207,253},//x3lq
								{1159,215,254},//s1lq
								{2194,211,254,0,2},//s1jg
								{2193,212,254,0,2},//s2jg
								{2192,213,254,0,2},//s3jg
								{1157,202,253,0,1},//x2jg
								{1083,204,253},//下进站
								{1033,214,254,1365},//上进站
									//21
};
#define CON2_LENGTH 5
const unsigned int	conditon2[CON2_LENGTH][3]={{65535,0},
								{1084,0},//IAG
								{1034,1365},//4dg
								{986,1225,1229},//7-11
								{1038,1373}};//8dg}
unsigned char bcastflag=0,bcastnum=0,sendcastflag=0;	
//const unsigned char PROGMEM  s[5] =  { 1, 2, 3, 4, 5 };  //定义uchar型的常量n定义在flash里(flash常量)
									
#define  LENGTH 15							
/*const unsigned int x_reserve[LENGTH][11]=//1、3左 2、4右 5左第一个道6、7正道8右边第一个道9、10、11轨道红
{ {0,0,0,0,0},	{1257,1425,0000,0000,996,1129,1129,1052,1130,1130,1130},//1
				{1313,1449,0000,0000,1014,1131,1131,1062,1132,1132,1132},//2
				{1269,1493,1258,1426,996,1133,1133,1068,1134,1134,1134},//3
				{1277,1497,1314,1450,1002,1135,1135,1078,1136,1136,1136},//4
				{1273,0000,1270,1494,1000,1137,1137,1068,1138,1138,1138},//5
				{1278,1510,0000,1498,1002,1139,1139,1078,1140,1140,1140},//6
				{1281,1466,1274,0000,1004,1141,1141,1072,1142,1142,1142},//7
				{1265,1509,1322,1498,998,1143,1143,1078,1144,1144,1144}, //8 
				{0,0,0,0,0},
				//{1293,1398,1282,1434,1012,1145,1145,1070,1146,1146,1146},//9 第二个
				{1266,1501,0000,1490,998,1147,1147,1082,1148,1148,1148},//10
				{0,0,0,0,0},
				//{1294,1458,1305,0000,1010,1149,1149},	//11
				{1254,1505,1261,1502,994,1151,1151,1082,1152,1152,1152},//12
				{0,0,0,0,0},
				{1262,1506,1261,1502,994,1153,1153,1082,1154,1154,1154}};//14*/
const unsigned int x_left[LENGTH][7]= {
		  {0,0},{996,1257},//1	
			    {1225,1014,1317},//2
				{996,1258,1269,992},//3
				{990,1016,1277},//4
				{996,1258,1270,1273,992},//5
				{990,1016,1278},//6
				{996,1258,1270,1274,1281,992},//7
				{1242,998,1322,1265},//8
				{996,1258,1270,1274,1282,1297,992},//9
				{1242,998,1322,1266},//10
				{996,1258,1270,1274,1282,1298,992},//11
				{1242,994,1254,1261},//12
				{0000,0000},//13
				{1242,994,1254,1262},//14								
};
const unsigned int x_right[LENGTH][6]={
		  {0,0},{1052,1417,1429},//1	
			    {1062,1453},//2
				{1068,1465,1493},//3
				{1062,1454,1489,1497},//4
				{1068,1465,1494},//5
				{1062,1454,1489,1498,1510},//6
				{1068,1466},//7
				{1062,1454,1489,1498,1509},//8
				{1402,1048,1058,1457},//9
				{1062,1454,1490,1501},//10
				{1402,1048,1058,1458},//11
				{1062,1454,1490,1502,1505},//12
				{0000,0000},//13
				{1062,1454,1490,1502,1506},//14
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
			{1006,1070,1145,1145,1146,1146,1146},//9
			{998,1082,1147,1147,1148,1148,1148},//10
			{1010,1058,1149,1149,1150,1150,1150},//11
			{994,1082,1151,1151,1152,1152,1152},//12
			{0},//13
			{994,1082,1153,1153,1154,1154,1154},//14					
};

 unsigned int signal[4]={0,2,0,62};

#define cachelen 25										  
volatile char rdatacache[cachelen+1][15]={0};