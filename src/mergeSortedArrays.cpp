/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int greaterdate(char *date1, char *date2)
{
	int d1 = ((date1[0] - '0') * 10 + (date1[1] - '0'));
	int d2 = ((date2[0] - '0') * 10 + (date2[1] - '0'));
	int m1 = ((date1[3] - '0') * 10 + (date1[4] - '0'));
	int m2 = ((date2[3] - '0') * 10 + (date2[4] - '0'));
	int y1 = ((date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0'));
	int y2 = ((date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0'));
	if (y1 > y2)
		return 1;
	else if (y1 < y2)
		return -1;
	else
	{
		if (m1>m2)
			return 1;
		else if (m1 < m2)
			return -1;
		else
		{

			if (d1>d2)
				return 1;
			else if (d1<d2)
				return -1;
			else
				return(0);
		}
	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL||BLen==NULL||ALen==NULL)
		return NULL;
	else if (A == B)
	{
		int i=0,k=0,rlen=ALen+BLen;
		struct transaction *result = (struct transaction*)malloc(rlen*sizeof(struct transaction));
		while (i < ALen)
		{
				result[k] = A[i];
				k++;
				result[k] = A[i];
				k++;
				i++;
		}
		return(result);
	}
	else
	{
		int i = 0, j = 0, k = 0, x , rlen = ALen + BLen;
		struct transaction *result = (struct transaction*)malloc(rlen*sizeof(struct transaction));
		while (i < ALen&&j < BLen)
		{
			x = greaterdate(A[i].date, B[j].date);
			if (x == 1)
			{
				result[k] = B[j];
				j++; k++;
			}
			else if (x == -1)
			{
				result[k] = A[i];
				i++; k++;
			}
			else
			{
				result[k] = A[i];
				k++;
				result[k] = A[i];
				i++; j++; k++;
			}
		}
		while (i<ALen)
		{
				result[k] = A[i];
				i++;
				k++;
		}
		while (j<BLen)
		{
				result[k] = B[j];
				k++;
				j++;
		}
		return(result);
	}
} 