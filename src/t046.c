/*https://leetcode.com/problems/permutations/
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:

[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

static int **retData = 0;
static int indexRes = 0;
static void DFS(int* nums, int numsSize, int *result, int index)
{
	int i,j;
	int bFind = 0;
	if (index>=numsSize)
	{
		for (i = 0; i < index; i++)
		{
			retData[indexRes][i] = nums[result[i]];
		}
		indexRes++;
	}
	for (i = 0; i < numsSize; i++)
	{
		bFind = 0;
		for (j = 0; j < index; j++)
		{
			if (result[j] == i)
			{
				bFind = 1;
				break;
			}
		}

		if (!bFind)
		{
			result[index] = i;
			DFS(nums, numsSize, result, index+1);
		}
	}
}


/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** permute(int* nums, int numsSize, int* returnSize) {

	int i;

	int size=1;
	int *result = (int*)malloc(numsSize*sizeof(int));
	for (i = numsSize; i > 0; i--)
	{
		size *= i;
	}

	retData = (int**)malloc(size*sizeof(int*));
	for (i = 0; i < size; i++)
	{
		retData[i] = (int*)malloc(numsSize*sizeof(int));
	}

	indexRes = 0;
	DFS(nums, numsSize, result, 0);
	free(result);
	*returnSize = size;
	return retData;
}


void testT046()
{
	int nums[] = { 1, 2, 3 ,4};
	int numSize = 4;
	int returnSize;
	int** ret=permute(nums, numSize, &returnSize);



	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < numSize;j++)
			printf("%3d", ret[i][j]);
		printf("\n");
	}
	

	system("pause");
}