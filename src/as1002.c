/*
http://172.17.11.34/JudgeOnline/problem.php?id=1002
��Դ������ʡ�������ѧ�������������ƾ��� ��ĿC

��Ŀ����
������һ��������λ���������ĸ�λ����ȥ�����ٴ����µ����м�ȥ��λ����5�������ҽ�������17�ı���ʱ��ԭ��Ҳ��17�ı��� ��

���磬34��17�ı�������Ϊ3-20=-17��17�ı�����201����17�ı�������Ϊ20-5=15����17�ı���������һ��������n������������ж����Ƿ���17�ı�����

����
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1<=n<=10^100������ʾ���жϵ���������n=0��ʾ�����������ĳ���Ӧ��������һ�С�

���
����ÿ��������ݣ����һ�У���ʾ��Ӧ��n�Ƿ���17�ı�����1��ʾ�ǣ�0��ʾ��

��������
34
201
2098765413
1717171717171717171717171717171717171717171717171718
0
�������
1
0
1
0



*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//This is my code
void is17BeiShu()
{
	char dataArray[200] = { 0 };
	char *data = "2098765413";
	char tmpArray[200] = { 0 };
	int i,ret=0;
	int val;

	//strcpy(dataArray, data);
	while (scanf("%s",dataArray)!=-1)
	{
		int length = strlen(dataArray);

		if (!strcmp(dataArray, "0")) return;

		while (length>=10)
		{
			int last = atoi(dataArray+length - 9);
			int lastNum = last % 10;
			int leftNums = last / 10;

			int afterSub = leftNums - lastNum * 5;
			if (afterSub >= 0)
			{
				sprintf(dataArray+length-9, "%08d", afterSub);
				length--;
			}
			else
			{
				int bJiedao = 0;
				int indexStart = 0,intexEnd=0,bits=0;
				int tmp = 100000000 + afterSub;
				sprintf(tmpArray + length - 9, "%d", tmp);
				for (i = length - 10; i >= 0; i--)
				{
					if (!bJiedao&&dataArray[i] > '0')
					{
						tmpArray[i]=dataArray[i] - 1;
						bJiedao = 1;
					}
					else if (!bJiedao)
					{
						tmpArray[i] = '9';
					}
					else
					{
						tmpArray[i] = dataArray[i];
					}
				}
				for (i = 0; i < length; i++)
				{
					if (tmpArray[i] != '0')
						break;
				}
				sprintf(dataArray,"%s", tmpArray+i);

				length = strlen(dataArray);

			}

			
		}
		
		int val = atoi(dataArray);
		ret = (val % 17) ? 0 : 1;
		
		
		printf("%d\n", ret);

	}
}

//This is sb's code
void is17BeiShu2()
{
	
	char s[101];
	while (scanf("%s", &s) == 1 && s[0] != '0')
	{
		int m = 0;
		for (int i = 0; i < strlen(s); i++)
		{
			m = (m * 10 + s[i] - '0') % 17;
			//printf("%d ", m);
		}
		printf("%d\n", m == 0 ? 1 : 0);//���m=0 ����1����֮ ����0

	}
	
}

void testAS1002()
{

	is17BeiShu2();
	system("pause");
}