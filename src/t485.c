/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.

Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

*/
#include <math.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int max = 0;
	int i,start=-1,end=0;
	for (i = 0; i < numsSize; i++)
	{
		if (start < 0 && nums[i]) {
			start = i;
		}
		if (start >= 0)
		{
			if (!nums[i])
			{
				end = i - 1;
				max = max > (i - start) ? max : (i - start);
				start = -1;
			}
			if (nums[i] && i == (numsSize - 1))
			{
				end = i;
				max = max > (end - start + 1) ? max : (end - start + 1);
				start = -1;
			}
		}


	}
	return max;
}

void testT485()
{
	int nums[] = { 1, 1, 0, 1, 1, 1 ,0};
	int numSize = 7;
	int returnSize;

	returnSize = findMaxConsecutiveOnes(nums, numSize);

}