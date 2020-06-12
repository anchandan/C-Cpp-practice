#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int index = start;
	int temp;
	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivot) //keep elements smaller than the pivot to the left
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	//swap the pivot and current index to get proper partition
	temp = arr[end];
	arr[end] = arr[index];
	arr[index] = temp;
	return index;
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