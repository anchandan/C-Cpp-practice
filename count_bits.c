#include <stdio.h>
#include <stdlib.h>

uint8_t count_bits(uint8_t num)
{
	uint8_t count = 0;

	if (num == 0)
	{
		return 0;
	}

	while(num & (num - 1))
	{
		count++;
		num = num & (num - 1);
	} 
	return count + 1;
}

int main()
{
	uint8_t num = 1;

	printf("%d\n", count_bits(4));
}