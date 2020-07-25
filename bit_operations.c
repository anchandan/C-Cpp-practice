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

int invert_bit(uint8_t num , uint8_t pos)
{
	num &= ~(1 << (pos));
	return num;
}


int main()
{
	int x = 9;
	int y = 1;
	printf("Add one to x: %d\n", add_one(x));
	swap(&x,&y);
	printf("Swappped: %d  %d\n", x,y);

	printf("Turning off bit 2: %d\n", invert_bit(3,0));
	return 0;
}