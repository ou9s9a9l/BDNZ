#include <avr/pgmspace.h>
//����***
const unsigned short PROGMEM dat0[][11]={
{345,361,373,365},
{361,346},
{353,345,299},             //IIG_R  ��������3������Ϊ102,IIG�ķ���????
{362,346},
{354,345},
{345,361},
{345,362},
{365,381,353,345},
{373,365,297},            //IG_R  ��������16������Ϊ1 ��IG�ķ���????
{374,365},
{366,373},
{365,381},
{366,374},
{365,382},
};
//���***
const unsigned short PROGMEM dat2[][13]={
{276,280,298,286,284},
{276,280,298,286,284},
{274,292},
{280,276,274,292},
{278,274,292},
{276,280,298},
{276,280,302},
{294,282,300,274,292},
{286,284},
{288,286,284},
{294,282,284,286,298},
{294,282,300},
{294,282,284,286,288,302},
{294,282,290,304},
};

//�źŻ�X-L X-LU/XI-L XI-LU XI-U   ***
unsigned short dat5[][2][3]={
{{1,5},{135,140,138}},    //{X-L,X-LU},{XI-L,XI-LU,XI-U},//XI-L
{{71,76,74}},             //{{SI-L,SI-LU,SI-U}},
{{87,92,90}},          //{{SII-L,SII-LU,SII-U}},
{{103,108,106}},             //{{SIII-L,SIII-LU,SIII-U}},
{{119,124,122}},       //{{SIV-L,SIV-LU,SIV-U}},
{{3}},                 //{{X-U}},
{{6,7}},                 //{{X-UU,X-USU}},                           X_YFY??????
{{43,47},{87,92,90}},    //{{S-L,S-LU},{SII-L,SII-LU,SII-U}},
{{135,140,138}},            //{{XI-L,XI-LU,XI-U}},
{{167,172,170}},           //{{XIII-L,XIII-LU,XIII-U}},
{{48}},                   //{{S-UU}},
{{45}},                //{{S-U}},
{{48}},                //{{S-UU}},
{{48}},                //{{S-UU}},
};


//�����ӳ�1 ����ӳ�2 ��������3  ���𷢳�4 ���ݽӳ�5 ʯ��ׯ�ӳ�6 ���ݷ���7 ʯ��ׯ����8   //***
unsigned short dat4[][2]={
{1,4},                //��·��9/27
{3},
{3},
{3},
{3},
{1},
{1},
{2,3},              //��·��30/6
{4},
{4},
{2},
{2},
{2},
{2}
};
//�������� txt ����   ***
unsigned short dat3[]={
41,               //����һ��ͨ���źſ���
101,              //����һ�������źſ���
102,              //���ж��������źſ���
103,              //3G
104,              //4G
21,               //����һ���ӳ��źſ���
23,               //����3���ӳ��źſ���
142,              //����2��ͨ���źſ���
1,                //����һ�������źſ���
3,                //����3�������źſ���  
121,               //����һ���ӳ��źſ��� 
122,               //2G
123,               //3G 
124                //4G
};

//***
#define CON_LENGTH 14             //[3]counter 4[daocha]  LENGTH�޸ģ�һ�㲻��
unsigned short	conditon[CON_LENGTH][5]={
	{305,201,1},//x1jg-h
	{307,202,1},//x2jg
	{309,203,1},//x3jg
	{275,204,1},//xjz-H          X��վ��һ������ 3DG
	{325,205},//x1lq-H
	{321,206},//x2lq
	{323,207},//x3lq
	{327,211,2},//{1171,211,254,0,2},//s1jg
	{329,212,2},//{1173,212,254,0,2},//s2jg
	{319,213,2},//{1167,213,254,0,2},//s3jg
	{293,214,2},//sjz-H       S��վ��һ������  IIBG
	{315,215},//s1lq
	{313,216},//s2lq
	{311,217}//s3lq


	
	//{2455,208}//1419       //�����źŵ�1419
	
};
 
//***
unsigned short factor[5][4]={
	 {0},
	 {0,0,276},//xjz-b  X��վ��һ������3DG-B
	 {0,0,294},//sjz-b  S��վ��һ������IIBG-B
	 {0,0,292},//scz-b  S��վ���һ�����Σ�XFǰһ�����Σ� IIAG_B
	 {0,0,284}//xcz-b   X��վ���һ�����Σ�SFǰһ�����Σ� 4DG-B
	 };