#include <stdio.h>
#include <stdlib.h>

int add_one(int x)
{
	x = -~x;
	return x;
}

void swap(int *x, int *y)
{
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}

int main()
{
	int x = 9;
	int y = 1;
	printf("Add one to x: %d\n", add_one(x));
	swap(&x,&y);
	printf("Swappped: %d  %d\n", x,y);
	return 0;
}