#include <stdio.h>


void print_spiral (int arr[][4], int row_siz, int col_siz){
	int direction = 0;
	int row_start = 0;
	int col_start = 0;
	int col_size = col_siz;
	int row_size = row_siz;
	printf("col_size=%d col_start=%d\n",col_size,col_start);
	int count = row_size * col_size;
	while(count != 0){
		switch(direction){
			case 0:
				printf("col_size=%d col_start=%d\n",col_size,col_start);		
				for (int i = col_start; i < 4; i++)
				{
					//printf("col_size=%d col_start=%d\n",col_size,col_start);
					printf("%d ", arr[row_start][i]);
					count--;
				}
				direction = 1;
				break;
			case 1:
				for (int i = row_start; i < row_size - 1; i++)
				{
					printf("%d ", arr[i][row_size - 1]);
					count--;
				}
				direction = 2;
				//row_size --;
				break;
			case 2:
				for (int i = col_size - 1; i >= col_start ; i--)
				{
					printf("%d ", arr[row_size - 1][i]);
					count--;
				}
				direction = 3;
				//row_size--;
				break;
			case 3:
				for (int i = row_size; i >= row_start + 1 ; i--)
				{
					printf("%d ", arr[i][col_size - 1]);
					count--;
				}
				direction = 0;
				row_start++;
				col_size--;
				row_size--;
				col_start++;
				break;
		}
	}
}

 int main()
{
	const int row_siz = 3;
	const int col_siz = 4;
	int arr[row_siz][col_siz] = {{1,2,3,4},
									{1,2,3,4},
									{1,2,3,4}};

	/* code */
	print_spiral(arr,row_siz,col_siz);
	return 0;
}