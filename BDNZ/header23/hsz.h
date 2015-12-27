#include <avr/pgmspace.h>
//����������***
const unsigned short PROGMEM dat0[][15]={
//IIG_R  ��������3������Ϊ102,IIG�ķ���????
//IG_R  ��������16������Ϊ1 ��IG�ķ���????
//��ˮ������ͨ��
{608,604,612,624,632,638,726,702,692,696,688},//����������???????????
{668,604,630,626,636,742,722,734,702,688,676},
//��ˮ������SL4����
{651,620,616},
{651,619,612,624,615},           //14/16,18/20Ϊ�������������Ƕ�λ��д����һ���Ƿ�λ����һ��Ϊ����������������������������
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
//��ˮ������SL3����
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
//��ˮ������SL2�ӳ�
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
//��ˮ������SL1�ӳ�
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
//������ͨ��
{684,692,696,698,706,718,656,620,612,624,616,608},
{680,684,698,706,714,648,652,620,616},
//�����淢��
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
//���ݷ��淢��
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
//���ݷ���ӳ�
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
//������ӳ�
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
//���������***---------------------------------------------------------------------------------------
const unsigned short PROGMEM dat2[][15]={
//{276,280,298,286,284},����
//��ˮ������ͨ��  //��ˮ������SL4����//��ˮ������SL3����//��ˮ������SL2�ӳ�  //��ˮ������SL1�ӳ�
//������ͨ��    //�����淢��    //���ݷ��淢��      //���ݷ���ӳ�       //������ӳ�
//----------------------------------------------------------------------------------------------------
//��ˮ������ͨ��
{391,385,397,405,509,415,545,477,517,463,453,443},
{439,387,497,403,413,547,487,515,461,445,447},
//��ˮ������SL4����
{409,423,407,399,499},                       //4LG,3LG,2LG,1LG�ò���д?��д
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
//��ˮ������SL3����
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
//��ˮ������SL2�ӳ�
{391,389,395,393,407,423,409,539},    //��������6/8�ͷ�������8DG?����ȥ��
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
//��ˮ������SL1�ӳ�
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
//������ͨ��
{455,451,457,469,551,419,511,393,395,389,501},
{435,441,519,459,467,479,537,423,407,399,499},
//�����淢��
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
//���ݷ��淢��
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
//���ݷ���ӳ�
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
//������ӳ�
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
//�źŻ�X-L X-LU/XI-L XI-LU XI-U   ***
unsigned short dat5[][2][3]={
//��ˮ������ͨ��  //��ˮ������SL4����//��ˮ������SL3����//��ˮ������SL2�ӳ�  //��ˮ������SL1�ӳ�
//������ͨ��    //�����淢��    //���ݷ��淢��      //���ݷ���ӳ�       //������ӳ�
//{{1,5},{135,140,138}},    //{X-L,X-LU},{XI-L,XI-LU,XI-U},//XI-L    ����
//{{71,76,74}},             //{{SI-L,SI-LU,SI-U}}, ����
//===============================================================================================
    //��ˮ������ͨ��
{{116,113},{88,85,85}},   //LU?UU? 
{{106,113},{82,95,95}},
//��ˮ������SL4����
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
//��ˮ������SL3����
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
//��ˮ������SL2�ӳ� 
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
//��ˮ������SL1�ӳ�
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
//������ͨ�� 
{{3,16},{140,137,137}},
{{8,5},{130,143,143}},
//�����淢�� 
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
//���ݷ��淢�� 
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
//���ݷ���ӳ�  
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
//������ӳ�
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
//�����ӳ�1 �����ӳ�2 ��������3 ��������4   //***
//��ˮ������ͨ��  //��ˮ������SL4������������ //��ˮ������SL3��ʯ��ׯ������//��ˮ������SL2���������ӳ�  //��ˮ������SL1��ʯ��ׯ���ӳ�
//������ͨ��    //�����淢��    //���ݷ��淢��      //���ݷ���ӳ�       //������ӳ�
//��ˮ������SL2���������ӳ� 1,������ӳ�2,//��ˮ������SL4������������3,//�����淢��4
//���ݷ���ӳ� 5,��ˮ������SL1��ʯ��ׯ���ӳ�6,���ݷ��淢��7,��ˮ������SL3��ʯ��ׯ������8   //�����ӳ������𷢳���ͨ��������???
//----------------------------------------------------------------------------------------------------------------------------------------
unsigned short dat4[][2]={
//��ˮ������ͨ��  
{1,7},                //��·��55/244    ��������ӳ�55/���ݷ��淢��244
{6,4},                //��·��90/224    ʯ��ׯ����ӳ�90/�����淢��224
//��ˮ������SL4������������
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
//��ˮ������SL3��ʯ��ׯ������
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
//��ˮ������SL2���������ӳ� 
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
//��ˮ������SL1��ʯ��ׯ���ӳ�
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
//������ͨ��    
{5,8},              //��·��250/37  ���ݷ���ӳ�250/ʯ��ׯ���淢��37
{2,3},              //��·��270/15  ������ӳ�270/�������淢��15
//�����淢��    
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
//���ݷ��淢��     
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
//���ݷ���ӳ�    
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
//������ӳ�
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
//�������� txt ����   ***
//��ˮ������ͨ��  //��ˮ������SL4������������ //��ˮ������SL3��ʯ��ׯ������//��ˮ������SL2���������ӳ�  //��ˮ������SL1��ʯ��ׯ���ӳ�
//������ͨ��    //�����淢��    //���ݷ��淢��      //���ݷ���ӳ�       //������ӳ�
unsigned short dat3[]={
//��ˮ������ͨ��
146,        //��������ͨ���źſ���
48,        //����8��ͨ���źſ���
//��ˮ������SL4������������ 
101,       //����1�������źſ���
101,        //����1�������źſ���
102,        //����2�������źſ���
102,        //����2�������źſ���
103,        //����3�������źſ���
104,        //����4�������źſ���
104,        //����4�������źſ���
105,        //����5�������źſ���
106,        //����6�������źſ���
107,        //����7�������źſ���
108,        //����8�������źſ���
109,        //����9�������źſ���
//��ˮ������SL3��ʯ��ׯ������              ??????????????????????????����
101,        //����1�������źſ���
102,        //����2�������źſ���
103,        //����3�������źſ���
104,        //����4�������źſ���
104,        //����4�������źſ���
105,       //����5�������źſ���
106,        //����6�������źſ���
107,        //����7�������źſ���
108,        //����8�������źſ���
109,       //����9�������źſ���
//��ˮ������SL2���������ӳ�             ������������������������
21,        //����1���ӳ��źſ���
21,        //����1���ӳ��źſ���
22,        //����2���ӳ��źſ���
22,        //����2���ӳ��źſ���
23,        //����3���ӳ��źſ���
23,        //����3���ӳ��źſ���
24,        //����4���ӳ��źſ���
24,        //����4���ӳ��źſ���
25,        //����5���ӳ��źſ���
25,        //����5���ӳ��źſ���
26,        //����6���ӳ��źſ���
26,        //����6���ӳ��źſ���
27,        //����7���ӳ��źſ���
27,        //����7���ӳ��źſ���
28,        //����8���ӳ��źſ���
28,        //����8���ӳ��źſ���
29,        //����9���ӳ��źſ���
29,        //����9���ӳ��źſ���
//��ˮ������SL1��ʯ��ׯ���ӳ�
21,        //����1���ӳ��źſ���
22,        //����2���ӳ��źſ���
23,        //����3���ӳ��źſ���
24,        //����4���ӳ��źſ���
24,        //����4���ӳ��źſ���
25,        //����5���ӳ��źſ���
26,        //����6���ӳ��źſ���
27,        //����7���ӳ��źſ���
27,        //����7���ӳ��źſ���
28,        //����8���ӳ��źſ���
28,        //����8���ӳ��źſ���
29,        //����9���ӳ��źſ���
29,        //����9���ӳ��źſ���
//������ͨ��  
43,        //����3��ͨ���źſ���
142,        //����2��ͨ���źſ���
//�����淢��  
1,        //����1�������źſ���
2,        //����2�������źſ���
3,        //����3�������źſ���
4,        //����4�������źſ���
5,        //����5�������źſ���
5,        //����5�������źſ���
6,       //����6�������źſ���
7,        //����7�������źſ���
7,        //����7�������źſ���
8,        //����8�������źſ���
8,        //����8�������źſ���
9,        //����9�������źſ���
9,        //����9�������źſ���
//���ݷ��淢��  
101,        //����1�������źſ���
102,        //����2�������źſ���
103,        //����3�������źſ���
104,        //����4�������źſ���
105,        //����5�������źſ���
105,        //����5�������źſ���
106,        //����6�������źſ���
107,        //����7�������źſ���
108,        //����8�������źſ���
109,        //����9�������źſ���
//���ݷ���ӳ�  
121,        //����1���ӳ��źſ���
122,        //����2���ӳ��źſ���
123,        //����3���ӳ��źſ���
124,        //����4���ӳ��źſ���  
125,        //����5���ӳ��źſ���
125,        //����5���ӳ��źſ���  
126,        //����6���ӳ��źſ���
127,        //����7���ӳ��źſ���  
128,       //����8���ӳ��źſ���
129,        //����9���ӳ��źſ���  
//������ӳ�
121,        //����1���ӳ��źſ���
121,        //����1���ӳ��źſ���
122,        //����2���ӳ��źſ���
122,        //����2���ӳ��źſ���  
123,        //����3���ӳ��źſ���
123,        //����3���ӳ��źſ���  
124,        //����4���ӳ��źſ���
124,        //����4���ӳ��źſ���  
125,        //����5���ӳ��źſ���
125,        //����5���ӳ��źſ���  
126,        //����6���ӳ��źſ���
127,        //����7���ӳ��źſ���
128,        //����8���ӳ��źſ���
129,        //����9���ӳ��źſ���
};

//***
#define CON_LENGTH 14             //[3]counter 4[daocha]  LENGTH�޸ģ�һ�㲻��
unsigned short	conditon[CON_LENGTH][5]={
//����������??????
	{305,201,1},//x1jg-h ��д            
	{307,202,1},//x2jg��д
	{309,203,1},//x3jg��д
	{392,204,1},//xjz-H          X��վ��һ������2DG   �����վ����
	{588,205},//xs1lq-H                 ����������1��ȥ
	{592,206},//xs2lq
	{580,207},//xs3lq
	{562,211,2}, //ss1jg     ����������1�ӽ�
	{574,212,2},//ss2jg
	{570,213,2},//ss3jg
	{436,214,2},//sjz-H       S��վ��һ������3DG      
	{315,215},//s1lq��д
	{313,216},//s2lq��д
	{311,217}//s3lq��д

	//{2455,208}//1419       //�����źŵ�1419
//-----------------------------------------
 //ʯ��ׯ������??????
	{576,201,5},//xd1jg-h             
	{572,202,5},//xd2jg
	{584,203,5},//xd3jg
	{456,204,5},//xjz-H          X��վ��һ������ 15DG   ���ݷ���
	{325,205},//x1lq-H��д                 
	{321,206},//x2lq��д
	{323,207},//x3lq��д
	{327,211,6},//{1171,211,254,0,2},//s1jg��д
	{329,212,6},//{1173,212,254,0,2},//s2jg��д
	{319,213,6},//{1167,213,254,0,2},//s3jg��д
	{440,214,6},//sjz-H       S��վ��һ������74DG   
	{590,215},//sd1lq
	{578,216},//sd2lq
	{582,217}//sd3lq

	
	//{2455,208}//1419       //�����źŵ�1419
	
};
 
//***
unsigned short factor[9][4]={
	 {0},//����������??????
	 {0,0,391},//xjz-b  X��վ��һ������2DG-B
	 {0,0,435},//sjz-b  S��վ��һ������3DG-B
	 {0,0,499},//scz-b  S��վ���һ�����Σ�XFǰһ�����Σ� 4LG_B
	 {0,0,447}//xcz-b   X��վ���һ�����Σ�SFǰһ�����Σ� 7DG-B
//------------------------------------------------------------------------------------------------
         //ʯ��ׯ������??????
	 {0,0,455},//xjz-b  X��վ��һ������15DG-B
	 {0,0,439},//sjz-b  S��վ��һ������74DG-B
	 {0,0,443},//scz-b  S��վ���һ�����Σ�XFǰһ�����Σ� 11DG_B
	 {0,0,501}//xcz-b   X��վ���һ�����Σ�SFǰһ�����Σ� 3LG-B
	 };