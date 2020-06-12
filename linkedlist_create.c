#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
}node;

void reverse_midpoint(node *head)
{
	node *fast = head;
	node *slow = head;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	node *prev = NULL;
	node *current = slow->next;
	node *forward = current;
	while(current != NULL)
	{
		forward = current->next;
		current->next = prev;
		prev = current;
		current = forward;
	}
	slow->next = prev;

	while(head != NULL)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

int main()
{
	struct node *head = (node *)malloc(sizeof(node));
	struct node *curr;
	head->val = 0;
	head->next = NULL;
	curr = head;
	for (int i = 1; i < 5; i++)
	{
		struct node *temp = (node *)malloc(sizeof(node));
		temp->next = NULL;
		temp->val = i;
		curr->next = temp;
		curr = temp;
	}
	curr = head;
	reverse_midpoint(curr);
	/*
	while(curr)
	{
		printf("%d\n", curr->val);
		curr = curr->next;
	}
	*/
	return 0;
}