#include <stdio.h>
#include<stdlib.h>

void merge(int *arr, int *temp, int start1, int mid, int start2)
{
	int left = start1;
	int index = left;
	int right = mid + 1;
	int size = start2 - start1 + 1;

	while(left <= mid && right <= start2)
	{
		if (arr[left] < arr[right])
		{
			temp[index] = arr[left];
			left++;
		}
		else
		{
			temp[index] = arr[right];
			right++;
		}
		index++;
	}
	while(left <= mid)
	{
		temp[index] = arr[left];
		index++; 
		left++;
	}
	while(right <= start2)
	{	
		temp[index] = arr[right];
		right++;
		index++;
	}
	for (int i = 0; i < index; i++)
	{
		arr[i] = temp[i];
		//printf("%d ", arr[i]);
	}
	//printf("\n");
}

void merge_sort(int *arr , int *temp ,int left , int right)
{
	int mid;
	if (left < right)
	{
		mid = ((left + right) / 2);

		merge_sort(arr, temp ,left , mid);
		merge_sort(arr, temp ,mid+1 , right);
		merge(arr, temp ,left , mid , right);
	}
}

void sort(int *array, int size)
{
	int l = 0;
	int r = size - 1;
	int *temp = (int *)malloc(size * sizeof(int));
	merge_sort(array , temp ,l , r);
	#if 1
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	#endif
	
}

int main()
{
	int elements[10] = {9,8,7,6,5,4,3,2,1,0};

	sort(elements , 10);
	return 0;
}