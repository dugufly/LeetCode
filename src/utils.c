#include "utils.h"


void BubbleSort(int *pSrc, int size)
{
	int i, j, last;
	int tmp;
	i = size - 1;
	while (i>0)
	{
		last = 0;
		for (j = 0; j < i; j++)
		{
			if (pSrc[j]>pSrc[j + 1])
			{
				tmp = pSrc[j];
				pSrc[j] = pSrc[j + 1];
				pSrc[j + 1] = tmp;
				last = j;
			}
		}
		i = last;
	}
}

//return sorted array
int* SortAndDelDupVal(int * pSrc,int srcSize,int *dstSize)
{
	int *pDst ;
	int size = 0,i;

	BubbleSort(pSrc, srcSize);
	if (srcSize <= 0) return 0;
	pDst = (int*)malloc(srcSize*sizeof(int));
	pDst[size++] = pSrc[0];

	for (i = 1; i < srcSize; i++)
	{
		if (pSrc[i] == pSrc[i - 1]) continue;
		pDst[size++] = pSrc[i];
	}

	*dstSize = size;
	return pDst;

}