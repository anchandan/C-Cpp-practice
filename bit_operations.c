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

uint8_t reverse_upper_bits(uint8_t num)
{
	uint8_t mask = 0xf0;
	uint8_t reverse_mask = 0x0f;
	uint8_t place_holder = num & mask;
	place_holder >>= 4;
	uint8_t reverse_place_holder = 0;

	for (int i = 0; i < 4; ++i)
	{
		reverse_place_holder |= ((place_holder & 1));
		place_holder >>= 1;
		reverse_place_holder <<=  1;
	}
	reverse_place_holder >>= 1;
	reverse_place_holder <<= 4;
	uint8_t result = (num & reverse_mask) | reverse_place_holder;

	return result;

}


/*
	Insert y in x from bit position a to bit position b. 
*/
uint32_t bits_insert(uint32_t x , uint32_t y , uint8_t a , uint8_t b)
{
	uint32_t allones = ~0;
	uint32_t left = allones << (a + 1);
	uint32_t right = (1 << (b));
	right -= 1;
	uint32_t mask = left | right;
	uint32_t clear_x = x & mask;
	uint32_t insert_y = y << b;

	return clear_x | insert_y;
}

int main()
{
	int x = 9;
	int y = 1;
	//printf("Add one to x: %d\n", add_one(x));
	swap(&x,&y);
	//printf("Swappped: %d  %d\n", x,y);

	//printf("Turning off bit 2: %d\n", invert_bit(3,1));

	//printf("Reverse top 4 bits of 0XBO: %X\n", reverse_upper_bits(0xb0));

	printf("Inserting 12 in 32, Expected 44 got %lu\n" , bits_insert(32,12,4,0));

	return 0;
}