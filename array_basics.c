#include <stdio.h>
#include <stdbool.h>

int find_sum(int *arr , int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int find_largest(int *arr , int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

bool recursive_linear_search(int *arr , int current_index ,int len , int key)
{
	if(arr[current_index] == key)
	{
		return true;
	}
	else if(current_index >= len - 1)
		return false;
	else
	{
		return recursive_linear_search(arr ,  ++current_index, len , key);
	}
}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	printf("final sum:%d\n", find_sum(array , 10));
	printf("max:%d\n", find_largest(array , 10));
	printf("%d\n", recursive_linear_search(array , 0 , 10 , 21));
}