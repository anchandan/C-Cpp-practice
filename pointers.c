#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int **x , int **y)
{
	uint64_t temp;
	//printf("*x:%lu\n", *x);
	temp = *x;
	*x = *y;
	*y = temp;
	//printf("Addresses swapped\n");
}
void modify_values(int *x)
{
	*x += 1;
}

int main()
{
	int *x = (int *)malloc(sizeof(int));
	int *y = (int *)malloc(sizeof(int));
	*x = 10;
	*y = 20;
	//uint64_t temp = 0;
#if 0
	printf("Address of x:%lu\n", x);
	printf("Value x is pointing to:%d\n", *x);
	printf("Address of y:%lu\n", y);
	printf("Value y is pointing to:%d\n", *y);
#endif
	//swap(&x,&y);
	modify_values(x);
	printf("%d\n", *x);
#if 0
	printf("\n");
	printf("Address of x:%lu\n", x);
	printf("Value x is pointing to:%d\n", *x);
	printf("Address of y:%lu\n", y);
	printf("Value y is pointing to:%d\n", *y);
#endif
	//int arr[5] = {1,2,3,4,5};

	int arr[3][4] = {{1,2,3,4},
					 {1,2,3,4},
					 {1,2,3,4}};

	int *p = (int *)arr;

	printf("0,0: %d\n",(int)(*p) );
	printf("2,3: %d\n",(int)*(p+((2*4)+ 2)));
}