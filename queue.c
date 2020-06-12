#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define size 7

int front = -1;
int rear = -1;
int arr[size] = {0};

typedef struct linkedlist
{
	int val;
	struct node *next;
}node;

node *front_node = (node*)malloc(sizeof(node));
node *rear_node = (node*)malloc(sizeof(node));

front_node->next = NULL;
rear_node->next = NULL;

bool enque_linkedlist(int val)
{
	if (rear_node->next == front_node)
	{
		return false;
	}
	else
	{
		if (rear_node->next == NULL && front_node->next == NULL)
		{
			node *temp = (node*)malloc(sizeof(node));
			temp->next = temp;
			temp->val = value;
			rear = temp;
		}
	}
}

bool enque(int value)
{
	if ((rear + 1) % size  == front)
	{
		return false;	
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		rear = (rear + 1) % size;
		arr[rear] = value;
		return true;
	}
}

bool deque()
{
	if (front == -1 && rear == -1)
	{
		return false;	
	}
	else
	{
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (front + 1) % size;
		}
	}
}

void showfront()
{
	if (front == -1 && rear == -1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("%d\n", arr[front]);
	}
}

int main()
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", enque(i));
	}
	printf("%d\n", deque());

	printf("%d\n", enque(8));
	printf("front:%d rear:%d\n", front , rear);
	return 0;
}