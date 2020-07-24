#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr , int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int num_array[7] = {64, 34, 25, 12, 22, 11, 90};

	int *ptr = num_array;

	bubble_sort(ptr , 7);

	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
}