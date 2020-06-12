#include <stdio.h>
#include <stdlib.h>

void convert_matrix(int *matrix , int rows , int columns);

int main()
{
	int old_matrix[5][5] = {{1,2,3},{4,5,6}};

	convert_matrix((int *)old_matrix , 2 , 3);

	printf("%d\n", old_matrix[2][0]);
}

void convert_matrix(int *matrix , int rows , int columns)
{
	int current_max_row = rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = (rows - columns); j < columns; j++)
		{
			matrix[current_max_row][j] = matrix[i][j];
			matrix[i][j] = NULL;
		}
		current_max_row++;
	}
}