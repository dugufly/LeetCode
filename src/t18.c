//https://leetcode.com/problems/4sum/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int retCnt = 0;
int ** retAry = 0;
int *num1, *num2, *num3, *num4;
int  isGroupOK(int index)
{
	int i;
	for (i = 0; i < index; i++)
	{
		if (num1[index] == num1[i] &&
			num2[index] == num2[i] &&
			num3[index] == num3[i] &&
			num4[index] == num4[i])
			return 0;
	}
	return 1;
}
void fn1(int* nums, int start, int end, int leftNum, int leftTarget, int* marks)
{
	int i = 0;
	if (leftNum <= 0)
	{
		if (!leftTarget)
		{
			int j = 0;

			for (i = 0; i < end; i++)
			{
				if (marks[i] == 1)
				{

					if (j == 0) num1[retCnt] = nums[i];
					else if (j == 1) num2[retCnt] = nums[i];
					else if (j == 2) num3[retCnt] = nums[i];
					else if (j == 3) num4[retCnt] = nums[i];
					j++;

				}

			}
			if (isGroupOK(retCnt))
				retCnt++;

		}

		return ;
		
	}

	for (i = start; i < end; i++)
	{
		marks[i] = 1;
		fn1(nums, i + 1, end, leftNum - 1, leftTarget - nums[i], marks);
		marks[i] = 0;
	}

	return ;
}


/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int * marks = (int*)calloc(numsSize, sizeof(int));
	num1 = (int *)malloc(sizeof(int) * numsSize * 10);
	num2 = (int *)malloc(sizeof(int) * numsSize * 10);
	num3 = (int *)malloc(sizeof(int) * numsSize * 10);
	num4 = (int *)malloc(sizeof(int) * numsSize * 10);
	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < numsSize - 1 - i; j++)
		{
			if (nums[j]>nums[j + 1])
			{
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}



	retCnt = 0;
	fn1(nums, 0, numsSize, 4, target, marks);
	retAry = (int **)calloc(retCnt, sizeof(int*));
	for (i = 0; i < retCnt; i++)
	{
		retAry[i] = (int*)malloc(sizeof(int) * 4);
		retAry[i][0] = num1[i];
		retAry[i][1] = num2[i];
		retAry[i][2] = num3[i];
		retAry[i][3] = num4[i];
	}

	*returnSize = retCnt;
	free(marks);
	free(num1);
	free(num2);
	free(num3);
	free(num4);
	return retAry;
}


int testT18()
{

	int nums2[] = { -5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5 };
	int nums[] = { 0, 0, 0, 0 };
	int returnSize;
	int i, j;



	int **ret = fourSum(nums2, 12, 0, &returnSize);
	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%4d", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}