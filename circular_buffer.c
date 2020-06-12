#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	unsigned int front;
	unsigned int rear;
	unsigned int curr_size;
	unsigned int total_size;
	int arr[0];
}circular_buf;

typedef circular_buf* circular_buf_handle;


circular_buf * buf_init(unsigned int size)
{
	circular_buf *temp = (circular_buf *)malloc(sizeof(*temp) + sizeof(int) * size);
	temp->front = -1;
	temp->rear = -1;
	temp->curr_size = 0;
	temp->total_size = size;
	return temp;
}

void buf_enqueue(circular_buf *buf , int value)
{
	if (buf->curr_size == 0)
	{
		buf->front = 0;
		buf->rear = 0;
		buf->arr[buf->rear] = value;
		buf->curr_size++;
	}
	else if (buf->curr_size == buf->total_size)
	{
		return;
	}
	else
	{
		buf->rear = (buf->rear+1) % buf->total_size;
		buf->arr[buf->rear] = value;
		buf->curr_size++;
	}
}

int buf_dequeue(circular_buf *buf)
{
	int temp = 0;
	if (buf->curr_size == 0)
	{
		buf->front = -1;
		buf->rear = -1;
		return -1;
	}
	else
	{
		temp = buf->arr[buf->front];
		buf->front = (buf->front+ 1) % buf->total_size; 
		buf->curr_size--;
	}
	return temp;
}
int buf_top(circular_buf *buf)
{
	return buf->arr[buf->front];
}

int buf_size(circular_buf *buf)
{
	return buf->curr_size;
}

int main()
{
	circular_buf *buffer;
	circular_buf_handle buf;
	buffer = buf_init(10);
	buf = buf_init(10);
	printf("Circular buffers\n");
	printf("%d\n", buf_dequeue(buffer));
	buf_enqueue(buffer , 10);
	printf("%d\n", buf_top(buffer));
	printf("%d\n", buf_dequeue(buffer));
	printf("%d\n", buf_dequeue(buffer));
}
