/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int datecheck(int day, int month, int year)
{
	if (day == 0 || month == 0 || year == 0)
		return(-1);
	else if (month>12 || day>31)
		return(-1);
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day>29)
				return(-1);
		}
		else
		{
			if (day>28)
				return(-1);
		}

	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day>30)
			return(-1);
	}
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen <= 0 || A == NULL || BLen <= 0 || B == NULL)
		return NULL;
	else if (A == B)
		return(A);
	else
	{
		struct transaction *result = (struct transaction*)malloc(sizeof(struct transaction));
		int i, j,x,y,count=0;
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				int d1 = (A[i].date[0] - '0') * 10 + (A[i].date[1] - '0');
				int d2 = (B[j].date[0] - '0') * 10 + (B[j].date[1] - '0');
				int m1 = (A[i].date[3] - '0') * 10 + (A[i].date[4] - '0');
				int m2 = (B[j].date[3] - '0') * 10 + (B[j].date[4] - '0');
				int y1 = (A[i].date[6] - '0') * 1000 + (A[i].date[7] - '0') * 100 + (A[i].date[8] - '0') * 10 + (A[i].date[9] - '0');
				int y2 = (B[j].date[6] - '0') * 1000 + (B[j].date[7] - '0') * 100 + (B[j].date[8] - '0') * 10 + (B[j].date[9] - '0');
				x = datecheck(d1, m1, y1);
				y = datecheck(d2, m2, y2);
				if (x != -1 && y != -1)
				{
					if (y1 == y2&&m1 == m2&&d1 == d2)
					{
						count++;
						result = &A[i];

					}
				}
				else
					return NULL;

			}
		}
		if (count == 0)
			return NULL;
		else
			return(result);
			}
		}