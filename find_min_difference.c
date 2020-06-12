#include <stdio.h>
#include <stdlib.h>

void find_min_diff(int *x , int *y , int size_x , int size_y , int target);

int main(void)
{
	int A[] = {1,4,5,7};
	int B[] = {10,20,30,40};
	find_min_diff(A , B , 4 , 4 , 32); 
	return 0;
}

void find_min_diff(int *x , int *y , int size_x , int size_y , int target)
{
	int new_size = size_y + size_x;
	int *result = (int *)malloc(new_size* sizeof(int));
	int index_x = 0;
	int index_y = 0;
	int result_index = 0;
	while(index_x < size_x && index_y < size_y)
	{
		if (x[index_x] < y[index_y])
		{
			result[result_index] = x[index_x];
			index_x++;
		}
		else
		{
			result[result_index] = y[index_y];
			index_y++;
		}
		result_index++;
	}
	while(index_x < size_x)
	{
		result[result_index] = x[index_x];
		index_x++;
		result_index++;
	}
	while(index_y < size_y)
	{
		result[result_index] = y[index_y];
		index_y++;
		result_index++;
	}

	int left = 0;
	int right = new_size - 1;
	int min_diff = 100000;
	int temp_diff = 0;

	while(left < right)
	{
		temp_diff = abs(result[left] + result[right] - target);
		if (temp_diff < min_diff)
		{
			min_diff = temp_diff;
		}
		left++;
		right--;
	}
	printf("Min diff:%d\n", min_diff);

}