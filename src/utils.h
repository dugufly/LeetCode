#ifndef _LEET_UTILS_
#define _LEET_UTILS_

#ifndef INT_MAX
#define INT_MAX ~(1<<(sizeof(int)*8-1))
#endif

#ifndef INT_MIN
#define INT_MIN  (1<<(sizeof(int)*8-1))
#endif


void BubbleSort(int *pSrc, int size);
int* SortAndDelDupVal(int * pSrc, int srcSize, int *dstSize);

#endif//_LEET_UTILS_