/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stddef.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int checkdate(int day, int month, int year)
{
	if (day == 0 || month == 0 || year == 0)
		return(-1);
	else if (month > 12 || day > 31)
		return(-1);
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day > 29)
				return(-1);
		}
		else
		{
			if (day > 28)
				return(-1);
		}

	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return(-1);
	}
}
int greaternum(char *date1, char *date2)
{
	int d1 = ((date1[0] - '0') * 10 + (date1[1] - '0'));
	int d2 = ((date2[0] - '0') * 10 + (date2[1] - '0'));
	int m1 = ((date1[3] - '0') * 10 + (date1[4] - '0'));
	int m2 = ((date2[3] - '0') * 10 + (date2[4] - '0'));
	int y1 = ((date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0'));
	int y2 = ((date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0'));
	int x = checkdate(d1, m1, y1);
	int y = checkdate(d2, m2, y2);
	if (x != -1 && y != -1)
	{
		if (y1 > y2)
			return 1;
		else if (y1 < y2)
			return 0;
		else
		{
			if (m1>m2)
				return 1;
			else if (m1 < m2)
				return 0;
			else
			{

				if (d1>d2)
					return 1;
				else
					return 0;
			}

		}
	}
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr==NULL||date==NULL||len<=0)
		return -1;
	int i;
	for ( i = 0; i < len; i++)
	{
		if (greaternum(Arr[i].date, date))
		{
			break;
		}
	}
	return len - i;
}
