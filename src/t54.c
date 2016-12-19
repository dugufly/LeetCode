//https://leetcode.com/problems/spiral-matrix/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPositionOK(int x, int y, int matrixRowSize, int matrixColSize, int *marks)
{
	if (x < 0 || y < 0 || x >= matrixColSize || y >= matrixRowSize) return 0;
	if (marks[y*matrixColSize + x]) return 0;
	return 1;
}
int getDirection(int x, int y, int matrixRowSize, int matrixColSize, int *marks)
{
	if (x>0 && !marks[y*matrixColSize + x - 1])
		return 2;
	else if (y>0 && !marks[(y - 1)*matrixColSize + x])
		return 3;
	else if (x<matrixColSize - 1 && !marks[y *matrixColSize + x + 1])
		return 0;
	else if (y<matrixRowSize - 1 && !marks[(y + 1) *matrixColSize + x])
		return 1;
	else
		return -1;


}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
	int numEle = matrixRowSize*matrixColSize;
	int* retList = (int*)malloc(matrixRowSize*matrixColSize*sizeof(int));
	int *marks = (int*)calloc(numEle, sizeof(int));
	int i, j, x = -1, y = 0, retIndex = 0;
	int direction = 0;//0:left to right; 1:top to bottom; 2:right to left; 3:bottom to top

	while (retIndex<numEle)
	{
		if (direction == 0)
		{
			x++;
			for (;;)
			{
				if (isPositionOK(x, y, matrixRowSize, matrixColSize, marks))
				{
					retList[retIndex++] = matrix[y][x];
					marks[y*matrixColSize + x] = 1;
					x++;
				}
				else
				{
					x--;
					direction = getDirection(x, y, matrixRowSize, matrixColSize, marks);
					break;
				}
			}
		}
		else if (direction == 1)//top to bottom
		{
			y++;
			for (;;)
			{
				if (isPositionOK(x, y, matrixRowSize, matrixColSize, marks))
				{
					retList[retIndex++] = matrix[y][x];
					marks[y*matrixColSize + x] = 1;
					y++;
				}
				else
				{
					y--;
					direction = getDirection(x, y, matrixRowSize, matrixColSize, marks);
					break;
				}
			}

		}
		else if (direction == 2)//right to left
		{
			x--;
			for (;;)
			{
				if (isPositionOK(x, y, matrixRowSize, matrixColSize, marks))
				{
					retList[retIndex++] = matrix[y][x];
					marks[y*matrixColSize + x] = 1;
					x--;
				}
				else
				{
					x++;
					direction = getDirection(x, y, matrixRowSize, matrixColSize, marks);
					break;
				}
			}
		}
		else if (direction == 3)//:bottom to top
		{
			y--;
			for (;;)
			{
				if (isPositionOK(x, y, matrixRowSize, matrixColSize, marks))
				{
					retList[retIndex++] = matrix[y][x];
					marks[y*matrixColSize + x] = 1;
					y--;
				}
				else
				{
					y++;
					direction = getDirection(x, y, matrixRowSize, matrixColSize, marks);
					break;
				}
			}

		}

	}
	free(marks);
	return retList;

}
void testT54()//Middle-ÌâÄ¿111£º54. Spiral Matrix
{
	//int mat[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//int matrixRowSize = 3;
	//int matrixColSize = 3;
	//int *matrix[3] = { 0 };
	//matrix[0] = mat[0];
	//matrix[1] = mat[1];
	//matrix[2] = mat[2];

	int mat[][2] = { { 1, 2 }, { 4, 5 } };
	int matrixRowSize = 2;
	int matrixColSize = 2;
	int *matrix[2] = { 0 };
	matrix[0] = mat[0];
	matrix[1] = mat[1];

	int *retList = spiralOrder(matrix, matrixRowSize, matrixColSize);

	for (int i = 0; i < matrixRowSize*matrixColSize; i++)
		printf("%3d", retList[i]);

	return 0;
}