#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>

void leaders_in_arr_efficient(int *arr, int size)
{
	int max = arr[size - 1];
	printf("%d ", max);
	for (int i = size - 2; i >=0 ; i--)
	{
		if (arr[i] > max)
		{
			printf("%d ", arr[i]);
			max = arr[i];
		}
	}
	printf("\n");
}

int * leaders_in_arr(int *arr , int size)
{
	int *result = (int *)malloc(size * sizeof(int));
	bool flag = false;
	int result_index = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			//printf("arr[i]: %d , arr[j] : %d\n", arr[i] , arr[j]);
			if (arr[i] <= arr[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			//printf("Inserting: %d\n", arr[i]);
			result[result_index] = arr[i];
			result_index++;
		}
		flag = false;
	}
	return result;
}


int main()
{
	int array[6] = {16, 17, 4, 3, 5, 2};

	int *p = (int *)array;
	int *result = leaders_in_arr(p , 6);
#if 1
	for (int i = 0; i < 6; ++i)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
#endif
	printf("Efficient method result\n");

	leaders_in_arr_efficient(p , 6);
}