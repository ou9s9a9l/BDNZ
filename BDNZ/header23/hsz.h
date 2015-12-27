#include <avr/pgmspace.h>
//道岔？？？***
const unsigned short PROGMEM dat0[][15]={
//IIG_R  语音表第3行内容为102,IIG的发车????
//IG_R  语音表第16行内容为1 ，IG的发车????
//衡水西方面通过
{608,604,612,624,632,638,726,702,692,696,688},//北京至德州???????????
{668,604,630,626,636,742,722,734,702,688,676},
//衡水西方面SL4发车
{651,620,616},
{651,619,612,624,615},           //14/16,18/20为联锁道岔，都是定位都写；有一个是反位，另一个为防护道岔？？？？？？？？？？
{648,652,620,616,538},               //IIG-R
{648,652,619,612,624,615},
{656,620,612,624,615},
{655,620,612,624,615},
{656,644,637,632,623,615},
{643,637,632,623,615,},
{638,632,623,615},
{630,626,631,623,615},
{636,625,631,623,615},
{664,635,625,631,623,615},
//衡水西方面SL3发车
{651,619,612,624,616,608},
{648,652,619,612,624,616,608},
{656,620,612,624,616,608,552},           //IIIG-R
{655,620,612,624,616,608},
{656,644,637,632,623,616,608},
{643,637,632,623,616,608},
{638,632,623,616,608},
{630,626,631,623,616,608},
{636,625,631,623,616,608},
{664,635,625,631,623,616,608},
//衡水西方面SL2接车
{607,616,624,612,619,651},
{608,604,611,619,651},
{607,616,624,612,619,652,648},
{608,604,611,619,652,648},
{607,616,624,612,620,656},
{608,604,611,620,656},
{608,604,612,624,632,637,644,656},
{608,604,611,620,655},
{608,604,612,624,632,637,643},
{607,616,623,632,637,643},
{608,604,612,624,632,638},
{607,616,623,632,638},
{608,604,612,624,631,626,630},
{607,616,623,631,626,630},
{608,604,612,624,631,625,636},
{607,616,623,631,625,636},
{608,604,612,624,631,625,635,664},
{607,616,623,631,625,635,664},
//衡水西方面SL1接车
{668,603,611,619,651},
{668,603,611,619,652,648},
{668,603,611,620,656},
{668,603,612,624,632,637,644,656},
{668,603,611,620,655},
{668,603,612,624,632,637,643},
{668,603,612,624,632,638},
{668,604,629},
{668,603,612,624,631,626,630},
{668,604,630,626,636},
{668,603,612,624,631,625,636},
{668,604,630,626,635,664},
{668,603,612,624,631,625,635,664},
//商丘方面通过
{684,692,696,698,706,718,656,620,612,624,616,608},
{680,684,698,706,714,648,652,620,616},
//商丘方面发车
{713,705,698,695,687,676},
{714,705,698,695,687,676},
{718,706,698,695,687,676
{727,717,706,698,695,687,676},
{725,702,692,696,687,676},
{726,728,717,706,698,695,687,676},
{726,702,692,696,687,676},
{741,722,734,702,688,676},
{741,722,734,701,692,696,687,676},
{742,722,734,702,688,676,548},              //VIIIG-R
{742,722,734,701,692,696,687,676},
{740,730,733,702,688,676},
{740,730,733,701,692,696,687,676},
//德州方面发车
{713,705,698,695,688},
{714,705,698,695,688},
{714,706,698,695,688},
{727,717,706,698,695,688},
{725,702,692,696,688},
{726,728,717,706,698,695,688},
{726,702,692,696,688,546},                  //VIG-R
{741,722,734,701,692,696,688},
{742,722,734,701,692,696,688},
{740,730,733,701,692,696,688},
//德州方面接车
{684,692,696,698,705,713},
{684,692,696,698,705,714},
{684,692,696,698,706,718},
{684,692,696,698,706,717,727},
{684,692,696,698,706,717,728,726},
{684,691,702,725},
{684,691,702,726},
{684,691,701,734,722,741},
{684,691,701,734,722,742},
{684,691,701,733,730,740},
//商丘方面接车
{680,684,698,706,713},
{680,683,692,696,698,705,713},
{680,684,698,706,714},
{680,683,692,696,698,705,714},
{680,684,697,706,718},
{680,683,692,696,698,706,718},
{680,684,697,706,717,727},
{680,683,692,696,698,706,717,727},
{680,684,697,706,717,728,726},
{680,683,692,696,698,706,717,728,726},
{680,683,691,702,726},
{680,683,691,701,734,722,741},
{680,683,691,701,734,722,742},
{680,683,691,701,733,730,740},
};
//轨道？？？***---------------------------------------------------------------------------------------
const unsigned short PROGMEM dat2[][15]={
//{276,280,298,286,284},例子
//衡水西方面通过  //衡水西方面SL4发车//衡水西方面SL3发车//衡水西方面SL2接车  //衡水西方面SL1接车
//商丘方面通过    //商丘方面发车    //德州方面发车      //德州方面接车       //商丘方面接车
//----------------------------------------------------------------------------------------------------
//衡水西方面通过
{391,385,397,405,509,415,545,477,517,463,453,443},
{439,387,497,403,413,547,487,515,461,445,447},
//衡水西方面SL4发车
{409,423,407,399,499},                       //4LG,3LG,2LG,1LG用不用写?已写
{409,423,407,393,395,389,399,499},
{423,407,399,499},
{423,407,393,395,389,399,499},
{419,511,393,395,389,399,499},
{417,419,511,393,395,389,399,499},
{417,415,509,405,397,395,389,399,499},
{415,509,405,397,395,389,399,499},
{415,509,405,397,395,389,399,499},
{401,405,397,395,389,399,499},
{413,403,401,405,397,395,389,399,499},
{411,413,403,401,405,397,395,389,399,499},
//衡水西方面SL3发车
{409,423,407,393,395,389,501},
{423,407,393,395,389,501},
{419,511,393,395,389,501},
{417,419,511,393,395,389,501},
{417,415,509,405,397,395,389,501},
{415,509,405,397,395,389,501},
{415,509,405,397,395,389,501},
{401,405,397,395,389,501},
{413,403,401,405,397,395,389,501},
{411,413,403,401,405,397,395,389,501},
//衡水西方面SL2接车
{391,389,395,393,407,423,409,539},    //防护道岔6/8和防护区段8DG?都已去掉
{391,385,389,395,393,407,423,409,539},
{391,389,395,393,407,423,537},
{391,385,389,395,393,407,423,537},
{391,389,395,393,511,419,551},
{391,385,389,395,393,511,419,551},
{391,385,397,405,509,415,417,549},
{391,385,389,395,393,511,419,417,549},
{391,385,397,405,509,415,559},
{391,389,395,397,405,509,415,559},
{391,385,397,405,509,415,545},
{391,389,395,397,405,509,415,545},
{391,385,397,405,401,557},
{391,389,395,397,405,401,557},
{391,385,397,405,401,403,413,547},
{391,389,395,397,405,401,403,413,547},
{391,385,397,405,401,403,413,411,555},
{391,389,395,397,405,401,403,413,411,555},
//衡水西方面SL1接车
{439,387,385,397,395,393,407,423,409,539},
{439,387,385,397,395,393,407,423,537},
{439,387,385,397,395,393,511,419,551},
{439,387,385,397,405,509,415,417,549},
{439,387,385,397,395,393,511,419,417,549},
{439,387,385,397,405,509,415,559},
{439,387,385,397,405,509,415,545},
{439,387,497,403,401,557},
{439,387,385,397,405,401,557},
{439,387,497,403,413,547},
{439,387,385,397,405,401,403,413,547},
{439,387,497,403,413,411,555},
{439,387,385,397,405,401,403,413,411,555},
//商丘方面通过
{455,451,457,469,551,419,511,393,395,389,501},
{435,441,519,459,467,479,537,423,407,399,499},
//商丘方面发车
{479,467,469,457,451,453,443,445,447},
{479,467,469,457,451,453,443,445,447},
{469,457,451,453,443,445,447},
{469,457,451,453,443,445,447},
{475,477,517,463,453,443,445,447},
{475,469,457,451,453,443,445,447},
{477,517,463,453,443,445,447},
{487,515,461,445,447},
{487,515,461,463,453,443,445,447},
{487,515,461,445,447},
{487,515,461,463,453,443,445,447},
{481,485,473,487,515,461,445,447},
{481,485,473,487,515,461,463,453,443,445,447},
//德州方面发车
{479,467,469,457,451,453,443},
{479,467,469,457,451,453,443},
{469,457,451,453,443},
{469,457,451,453,443},
{475,477,517,463,453,443},
{475,469,457,451,453,443},
{477,517,463,453,443},
{487,515,461,463,453,443},
{487,515,461,463,453,443},
{481,485,473,487,515,461,463,453,443},
//德州方面接车
{455,451,457,469,467,479,539},
{455,451,457,469,467,479,537},
{455,451,457,469,551},
{455,451,457,469,549},
{455,451,457,469,475,559},
{455,451,453,463,517,477,475,559},
{455,451,453,463,517,477,545},
{455,451,453,463,461,515,487,557},
{455,451,453,463,461,515,487,547},
{455,451,453,463,461,515,487,473,485,481,555},
//商丘方面接车
{435,441,519,459,467,479,539},
{435,441,455,451,457,469,467,479,539},
{435,441,519,459,467,479,537},
{435,441,455,451,457,469,467,479,537},
{435,441,519,459,457,469,551},
{435,441,455,451,457,469,551},
{435,441,519,459,457,469,549},
{435,441,455,451,457,469,549},
{435,441,519,459,457,469,475,559},
{435,441,455,451,457,469,475,559},
{435,441,455,451,453,463,517,477,545},
{435,441,455,451,453,463,461,515,487,557},
{435,441,455,451,453,463,461,515,487,547},
{435,441,455,451,453,463,461,515,487,473,485,481,555},
};

//===============================================================================================
//信号机X-L X-LU/XI-L XI-LU XI-U   ***
unsigned short dat5[][2][3]={
//衡水西方面通过  //衡水西方面SL4发车//衡水西方面SL3发车//衡水西方面SL2接车  //衡水西方面SL1接车
//商丘方面通过    //商丘方面发车    //德州方面发车      //德州方面接车       //商丘方面接车
//{{1,5},{135,140,138}},    //{X-L,X-LU},{XI-L,XI-LU,XI-U},//XI-L    例子
//{{71,76,74}},             //{{SI-L,SI-LU,SI-U}}, 例子
//===============================================================================================
    //衡水西方面通过
{{116,113},{88,85,85}},   //LU?UU? 
{{106,113},{82,95,95}},
//衡水西方面SL4发车
{{20,17,17}},
{{20,95,95}},
{{130,143,143}},
{{143},
{{137}},
{{40,37,37}},
{{40,37,37}},
{{34,47,47}},
{{27}},
{{44,41,41}},
{{147}},
{{54,51,51}},
//衡水西方面SL3发车
{{20,95,95}},
{{143}},
{{140,137,137}},
{{40,37,37}},
{{40,37,37}},
{{34,47,47}},
{{27}},
{{44,41,41}},
{{147}},
{{54,51,51}},
//衡水西方面SL2接车 
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
{{113}},
//衡水西方面SL1接车
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
{{119}},
//商丘方面通过 
{{3,16},{140,137,137}},
{{8,5},{130,143,143}},
//商丘方面发车 
{{64,61,61}},
{{58,71,71}},
{{68,65,65}},
{{78,75,75}},
{{92,89,89}},
{{92,89,89}},
{{88,85,85}},
{{102,99,99}},
{{102,99,99}},
{{82,95,95}},
{{82,95,95}},
{{112,109,109}},
{{112,109,109}},
//德州方面发车 
{{64,61,61}},
{{58,71,71}},
{{68,65,65}},
{{78,72,75}},
{{92,89,89},
{{92,89,89}},
{{88,85,85}},
{{102,99,99}},
{{82,95,95}},
{{112,709,109}},
//德州方面接车  
{{16}},
{{16}},
{{16}},
{{16}},
{{16}},
{{16}},
{{16}},
{{16}},
{{16}},
{{16}},
//商丘方面接车
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
{{5}},
};

//---------------------------------------------------------------------------------------------------------------------------------------
//北京接车1 九龙接车2 北京发车3 九龙发车4   //***
//衡水西方面通过  //衡水西方面SL4（北京）发车 //衡水西方面SL3（石家庄）发车//衡水西方面SL2（北京）接车  //衡水西方面SL1（石家庄）接车
//商丘方面通过    //商丘方面发车    //德州方面发车      //德州方面接车       //商丘方面接车
//衡水西方面SL2（北京）接车 1,商丘方面接车2,//衡水西方面SL4（北京）发车3,//商丘方面发车4
//德州方面接车 5,衡水西方面SL1（石家庄）接车6,德州方面发车7,衡水西方面SL3（石家庄）发车8   //北京接车，商丘发车的通过？？？???
//----------------------------------------------------------------------------------------------------------------------------------------
unsigned short dat4[][2]={
//衡水西方面通过  
{1,7},                //进路号55/244    北京方面接车55/德州方面发车244
{6,4},                //进路号90/224    石家庄方面接车90/商丘方面发车224
//衡水西方面SL4（北京）发车
{3},
{3},
{3},
{3},
{3},
{3},
{3},
{3},
{3},
{3},
{3},
{3},
//衡水西方面SL3（石家庄）发车
{8},
{8},
{8},
{8},
{8},
{8},
{8},
{8},
{8},
{8},
//衡水西方面SL2（北京）接车 
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1},
{1}, 
//衡水西方面SL1（石家庄）接车
{6},
{6},
{6},
{6},
{6},
{6},
{6},
{6},
{6},
{6},
{6},
{6},
{6},
//商丘方面通过    
{5,8},              //进路号250/37  德州方面接车250/石家庄方面发车37
{2,3},              //进路号270/15  商丘方面接车270/北京方面发车15
//商丘方面发车    
{4},
{4},
{4},
{4},
{4},
{4},
{4},
{4},
{4},
{4},
{4},
{4},
{4},
//德州方面发车     
{7},
{7},
{7},
{7},
{7},
{7},
{7},
{7},
{7},
{7},
//德州方面接车    
{5},
{5},
{5},
{5},
{5},
{5},
{5},
{5},
{5},
{5}, 
//商丘方面接车
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
{2},
};
//语音播报 txt 行数   ***
//衡水西方面通过  //衡水西方面SL4（北京）发车 //衡水西方面SL3（石家庄）发车//衡水西方面SL2（北京）接车  //衡水西方面SL1（石家庄）接车
//商丘方面通过    //商丘方面发车    //德州方面发车      //德州方面接车       //商丘方面接车
unsigned short dat3[]={
//衡水西方面通过
146,        //上行六道通过信号开放
48,        //下行8道通过信号开放
//衡水西方面SL4（北京）发车 
101,       //上行1道发车信号开放
101,        //上行1道发车信号开放
102,        //上行2道发车信号开放
102,        //上行2道发车信号开放
103,        //上行3道发车信号开放
104,        //上行4道发车信号开放
104,        //上行4道发车信号开放
105,        //上行5道发车信号开放
106,        //上行6道发车信号开放
107,        //上行7道发车信号开放
108,        //上行8道发车信号开放
109,        //上行9道发车信号开放
//衡水西方面SL3（石家庄）发车              ??????????????????????????下行
101,        //上行1道发车信号开放
102,        //上行2道发车信号开放
103,        //上行3道发车信号开放
104,        //上行4道发车信号开放
104,        //上行4道发车信号开放
105,       //上行5道发车信号开放
106,        //上行6道发车信号开放
107,        //上行7道发车信号开放
108,        //上行8道发车信号开放
109,       //上行9道发车信号开放
//衡水西方面SL2（北京）接车             ？？？？？？？？？？上行
21,        //下行1道接车信号开放
21,        //下行1道接车信号开放
22,        //下行2道接车信号开放
22,        //下行2道接车信号开放
23,        //下行3道接车信号开放
23,        //下行3道接车信号开放
24,        //下行4道接车信号开放
24,        //下行4道接车信号开放
25,        //下行5道接车信号开放
25,        //下行5道接车信号开放
26,        //下行6道接车信号开放
26,        //下行6道接车信号开放
27,        //下行7道接车信号开放
27,        //下行7道接车信号开放
28,        //下行8道接车信号开放
28,        //下行8道接车信号开放
29,        //下行9道接车信号开放
29,        //下行9道接车信号开放
//衡水西方面SL1（石家庄）接车
21,        //下行1道接车信号开放
22,        //下行2道接车信号开放
23,        //下行3道接车信号开放
24,        //下行4道接车信号开放
24,        //下行4道接车信号开放
25,        //下行5道接车信号开放
26,        //下行6道接车信号开放
27,        //下行7道接车信号开放
27,        //下行7道接车信号开放
28,        //下行8道接车信号开放
28,        //下行8道接车信号开放
29,        //下行9道接车信号开放
29,        //下行9道接车信号开放
//商丘方面通过  
43,        //下行3道通过信号开放
142,        //上行2道通过信号开放
//商丘方面发车  
1,        //下行1道发车信号开放
2,        //下行2道发车信号开放
3,        //下行3道发车信号开放
4,        //下行4道发车信号开放
5,        //下行5道发车信号开放
5,        //下行5道发车信号开放
6,       //下行6道发车信号开放
7,        //下行7道发车信号开放
7,        //下行7道发车信号开放
8,        //下行8道发车信号开放
8,        //下行8道发车信号开放
9,        //下行9道发车信号开放
9,        //下行9道发车信号开放
//德州方面发车  
101,        //上行1道发车信号开放
102,        //上行2道发车信号开放
103,        //上行3道发车信号开放
104,        //上行4道发车信号开放
105,        //上行5道发车信号开放
105,        //上行5道发车信号开放
106,        //上行6道发车信号开放
107,        //上行7道发车信号开放
108,        //上行8道发车信号开放
109,        //上行9道发车信号开放
//德州方面接车  
121,        //上行1道接车信号开放
122,        //上行2道接车信号开放
123,        //上行3道接车信号开放
124,        //上行4道接车信号开放  
125,        //上行5道接车信号开放
125,        //上行5道接车信号开放  
126,        //上行6道接车信号开放
127,        //上行7道接车信号开放  
128,       //上行8道接车信号开放
129,        //上行9道接车信号开放  
//商丘方面接车
121,        //上行1道接车信号开放
121,        //上行1道接车信号开放
122,        //上行2道接车信号开放
122,        //上行2道接车信号开放  
123,        //上行3道接车信号开放
123,        //上行3道接车信号开放  
124,        //上行4道接车信号开放
124,        //上行4道接车信号开放  
125,        //上行5道接车信号开放
125,        //上行5道接车信号开放  
126,        //上行6道接车信号开放
127,        //上行7道接车信号开放
128,        //上行8道接车信号开放
129,        //上行9道接车信号开放
};

//***
#define CON_LENGTH 14             //[3]counter 4[daocha]  LENGTH修改，一般不变
unsigned short	conditon[CON_LENGTH][5]={
//北京至商丘??????
	{305,201,1},//x1jg-h 不写            
	{307,202,1},//x2jg不写
	{309,203,1},//x3jg不写
	{392,204,1},//xjz-H          X进站第一个区段2DG   商丘进站方向
	{588,205},//xs1lq-H                 下行商丘方向1离去
	{592,206},//xs2lq
	{580,207},//xs3lq
	{562,211,2}, //ss1jg     上行商丘方向1接近
	{574,212,2},//ss2jg
	{570,213,2},//ss3jg
	{436,214,2},//sjz-H       S进站第一个区段3DG      
	{315,215},//s1lq不写
	{313,216},//s2lq不写
	{311,217}//s3lq不写

	//{2455,208}//1419       //区间信号点1419
//-----------------------------------------
 //石家庄至德州??????
	{576,201,5},//xd1jg-h             
	{572,202,5},//xd2jg
	{584,203,5},//xd3jg
	{456,204,5},//xjz-H          X进站第一个区段 15DG   德州方向
	{325,205},//x1lq-H不写                 
	{321,206},//x2lq不写
	{323,207},//x3lq不写
	{327,211,6},//{1171,211,254,0,2},//s1jg不写
	{329,212,6},//{1173,212,254,0,2},//s2jg不写
	{319,213,6},//{1167,213,254,0,2},//s3jg不写
	{440,214,6},//sjz-H       S进站第一个区段74DG   
	{590,215},//sd1lq
	{578,216},//sd2lq
	{582,217}//sd3lq

	
	//{2455,208}//1419       //区间信号点1419
	
};
 
//***
unsigned short factor[9][4]={
	 {0},//北京至商丘??????
	 {0,0,391},//xjz-b  X进站第一个区段2DG-B
	 {0,0,435},//sjz-b  S进站第一个区段3DG-B
	 {0,0,499},//scz-b  S出站最后一个区段（XF前一个区段） 4LG_B
	 {0,0,447}//xcz-b   X出站最后一个区段（SF前一个区段） 7DG-B
//------------------------------------------------------------------------------------------------
         //石家庄至德州??????
	 {0,0,455},//xjz-b  X进站第一个区段15DG-B
	 {0,0,439},//sjz-b  S进站第一个区段74DG-B
	 {0,0,443},//scz-b  S出站最后一个区段（XF前一个区段） 11DG_B
	 {0,0,501}//xcz-b   X出站最后一个区段（SF前一个区段） 3LG-B
	 };