/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include <stddef.h>
#define INT_SIZE 8
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len <= 0)
		return -1;
	int i, count[20] = { 0 }, value = 0;
	for (int i = 0; i < len; ++i)
	{
		count[A[i]] = count[A[i]] + 1;
	}

	for (int i = 0; i < len; ++i)
	{
		if (count[A[i]] == 1)
			return A[i];
	}
}