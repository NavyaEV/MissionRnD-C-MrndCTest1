/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int callfunction(int *, int *);

int between_days(struct node *date1head, struct node *date2head){
	struct node *temp;
	int d1[3], d2[3],main,dif=0;
	if ((date1head == NULL) || (date2head == NULL))
	{
		return -1;
	}
	temp = date1head;
	d1[0] = (temp->data * 10) + temp->next->data;
	temp = temp->next->next;
	d1[1] = (temp->data * 10) + temp->next->data;
	temp = temp->next->next;
	date1head = temp->next->next;
	d1[2] = (temp->data * 1000) + (temp->next->data * 100) + (date1head->data * 10) + date1head->next->data;
	temp = date2head;
	d2[0] = (temp->data * 10) + temp->next->data;
	temp = temp->next->next;
	d2[1] = (temp->data * 10) + temp->next->data;
	temp = temp->next->next;
	date2head = temp->next->next;
	d2[2] = (temp->data * 1000) + (temp->next->data * 100) + (date2head->data * 10) + date2head->next->data;
	
	if (d2[2] > d1[2])
	{
		main = d2[2];
		dif=callfunction(d1, d2);
	}
	else
	{
		main = d1[2];
		dif=callfunction(d2, d1);
	}
	return dif;
}
int callfunction(int *old, int *young)
{
	int dif = 0,k,temp;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (old[2] - young[2] == 0)
	{
		if ((old[1] - young[1]) == 0)
		{
			if ((old[0] - young[0]) > 0)
				return old[0] - young[0];
			else if ((old[0] - young[0])==0)
			{
				return 0;
			}
			else
			{
				return -1 * (old[0] - young[0]);
			}
		}
		else if ((old[1] - young[1]) > 0)
		{
			k = old[1] - young[1] - 1;
			temp = young[1]+1;
			while (k>0)
			{
				dif += month[temp - 1];
				k--;
				temp++;
			}
			dif += (month[old[1]] - old[0]) + (month[young[0]] - young[0]);
			return dif;
		}
		else
		{
			dif = callfunction(young, old);
			return dif;
		}
	}
	k = old[2] - young[2] - 1;
	temp = young[2] + 1;
	while (k > 0)
	{
		if (temp % 4 == 0)
			dif += 366;
		else
			dif += 365;
		k--;
		temp++;
	}
}