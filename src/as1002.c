/*
http://172.17.11.34/JudgeOnline/problem.php?id=1002
来源：湖南省第六届大学生计算机程序设计竞赛 题目C

题目描述
定理：把一个至少两位的正整数的个位数字去掉，再从余下的数中减去个位数的5倍。当且仅当差是17的倍数时，原数也是17的倍数 。

例如，34是17的倍数，因为3-20=-17是17的倍数；201不是17的倍数，因为20-5=15不是17的倍数。输入一个正整数n，你的任务是判断它是否是17的倍数。

输入
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=10^100），表示待判断的正整数。n=0表示输入结束，你的程序不应当处理这一行。

输出
对于每组测试数据，输出一行，表示相应的n是否是17的倍数。1表示是，0表示否。

样例输入
34
201
2098765413
1717171717171717171717171717171717171717171717171718
0
样例输出
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
		printf("%d\n", m == 0 ? 1 : 0);//如果m=0 返回1；反之 返回0

	}
	
}

void testAS1002()
{

	is17BeiShu2();
	system("pause");
}