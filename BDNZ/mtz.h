#include <avr/pgmspace.h>
//道岔**
const unsigned short PROGMEM dat0[][11]={
//IIG_R  语音表第3行内容为102,上行IIG的发车
//IIG_R  语音表第16行内容为1 ，下行IIG的发车
{778,779,789,783,785},               //道岔-L-U
{778},
{778,779},
{778,780,781},
{778,780,782},
{778},
{779,778,811},          //上行IIG_R
{780,781,778},
{782,780,778},
{785,783,789,779,778},
{783,785,790,791},
{783,785,789},
{786,783,787},                   //是有2/6
{786,783,788},                 //是否有2/6
{790,783,785,791},
{789,783,785,811},                 //下行IIG_R
{787,786,783},                  //是否有2/6
{788,786,783},                //是否有2/6
};



//轨道???**       
const unsigned short PROGMEM dat2[][13]={
{822,794,812,800,830},       //轨道项目多，不知道选哪个？？？？？-B-H????1-3,4-14_QH_QB?无-B
{822,794,810,806,832},       
{822,794,812},
{822,794,796,814},
{822,794,796,816},
{794,822},
{794,822},
{796,794,822},
{796,794,822},
{830,800,812,794,822},
{830,800,804,832,806,810},
{830,800,812},
{830,800,802,814},
{830,800,802,816},
{804,800,830},      
{800,830},
{802,800,830},
{802,800,830},
};

//信号机X-L X-LU/XI-L XI-LU XI-U  //***
unsigned short dat5[][2][3]={
{{1057},{985}},          //{X-L},{XII-L},
{{1068}},            //{{X-UU}},
{{1058}},            //{{X-U}},
{{1068}},            //{{X-UU}},
{{1068}},            //{{X-UU}},
{{865}},            //{{S1-L}},
{{889}},            //{{SII-L}},
{{913}},            //{{S3-L}},
{{937}},            //{{S4-L}},
{{1081},{889}},         //{{S-L},{SII-L}},
{{1092}},                   //{{S-UU}},
{{1082}},                   //{{S-U}},
{{1092}},                   //{{S-UU}},
{{1092}},                   //{{S-UU}},
{{961}},                   //{{XI-L}},
{{985}},    		 //{{XII-L}},
{{1009}},    		 //{{X3-L}},
{{1033}},     		 //{{X4-L}},
};


//北京接车1 九龙接车2 北京发车3 九龙发车4   //***
//阳泉接车1 涉县接车2 阳泉发车3 涉县发车4   //******
unsigned short dat4[][2]={
{1,4},                
{1},
{1},
{1},
{1},
{3},
{3},
{3},
{3},
{2,3},
{2},
{2},
{2},
{2},
{4},
{4},              
{4},
{4},
};
//语音播报 txt 行数   //***
unsigned short dat3[]={
42,               //下行二道通过信号开放
21,              //下行一道接车信号开放
22,              //下行二道接车信号开放
23,              //3G接车
24,              //4G接车
101,              //上行一道发车信号开放
102,              //2G发车
103,              //3G发车
104,              //4G发车
142,               //上行二道通过信号开放
121,               //上行1道接车信号开放
122,              //2G接车
123,                //3G接车
124,                //4G接车
1,               //下行1道发车信号开放
2,               //下行2道发车信号开放
3,                //3G发车
4,                //4G发车
};

//***
#define CON_LENGTH 2             //[3]counter 4[daocha]  LENGTH修改，一般不变
unsigned short	conditon[CON_LENGTH][5]={
	
	{821,204,1},//xjz-H          X进站第一个区段 IIAG-H
	
	{829,214,2},//sjz-H       S进站第一个区段  IIBG-H
	

	
	//{2455,208}//1419       //区间信号点1419
	
};
 
//***
unsigned short factor[5][4]={
	 {0},
	 {0,0,822},    //xjz-b  X进站第一个区段IIAG-B
	 {0,0,830},    //sjz-b  S进站第一个区段IIBG-B
	 {0,0,822},    //scz-b  S出站最后一个区段（XF前一个区段） IIAG_B
	 {0,0,830}     //xcz-b   X出站最后一个区段（SF前一个区段） IIBG-B
	 };