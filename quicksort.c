#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end)
{
	int pivot = (start + end) / 2;

	while(start < end)
	{
		while(arr[start] < pivot)
		{
			start++;
		}
		while(arr[end] > pivot)
		{
			end--;
		}
		if (start <= end)
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			
			end--;
			start++;
		}
	}
	return start;
}

void quicksort(int *arr, int start, int end)
{
	int partition_index = 0;
	if (start < end)
	{
		partition_index = partition(arr, start, end);
		quicksort(arr,start,(partition_index - 1));
		quicksort(arr, (partition_index+1), end);
	}
}

void sort(int *arr, int size)
{
	quicksort(arr, 0 , (size - 1));
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int elements[10] = {9,8,7,6,5,4,3,2,1,0};

	sort(elements, 10);
	return 0;
}