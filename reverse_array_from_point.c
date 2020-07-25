#include <stdio.h>
#include <stdlib.h>

void reverse_from_point(int *arr , int size , int point)
{
	int *result = (int *)malloc(size * sizeof(int));
	int count = 0;
	while(count < size)
	{
		result[count] = arr[point];
		count++;
		point = (point + 1) % size;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
}

int main()
{
	int array[7] = {1, 2, 3, 4, 5, 6, 7};

	reverse_from_point(array , 7 , 2);

	return 0;
}