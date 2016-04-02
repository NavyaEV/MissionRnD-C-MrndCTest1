/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node * merge(struct node *,struct node *);
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int c = 0;
	struct node *temp,*temp1;
	if ((head2 == NULL) && (head1==NULL))
		return -1;
	else if (head1 == NULL)
	{
		head1 = head2;
		temp = *head1;
		while (temp->next != *head1)
		{
			c++;
			temp = temp->next;
		}
		return c;
	}
	else if (head2 == NULL)
	{
		temp = *head1;
		while (temp->next!= *head1)
		{
			c++;
			temp = temp->next;
		}
		return c;
	}
	temp = *head1;
	temp1 = *head2;
	c = 0;
	while (temp->next!=*head1)
	{
		temp = temp->next;
		c++;
	}
	c++;
	temp1->next = NULL;
	while (temp1->next != *head2)
	{
		temp1 = temp1->next;
		c++;
	}
	c++;
	temp1->next = NULL;
	temp = merge(temp, temp1);
	temp1 = temp;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = temp1;
	*head1 = temp1;
	return c;
}
struct node * merge(struct node *a, struct node *b)
{
	struct node *result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	if (a->data <= b->data){
		result = a;
		result->next = merge(a->next, b);
	}
	else {
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}