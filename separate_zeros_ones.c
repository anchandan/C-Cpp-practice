#include <stdio.h>

void separate_zeros_ones(int *arr , int size)
{
	int left = 0;
	int right = size - 1;
	int temp;
	while(left < right)
	{
		if(arr[left] == 1)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			right--;
		}
		else
			left++;
	}
}

int main()
{
	int array[] = {0,1,1,0,0,0,1,1};
	int size = sizeof(array) / sizeof(int);
	printf("%d\n", size);

	separate_zeros_ones(array , size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}