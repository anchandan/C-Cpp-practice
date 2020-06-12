#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t return_next_pow_two(const uint8_t old_number)
{
	uint8_t number = old_number;
	if ((number & (number - 1)) == 0)
	{
		return number;
	}
	else
	{
		while(number & (number - 1))
		{
			number = number & (number - 1);
		}
		number = number << 1;
		return number;
	}
}

int main()
{
	uint8_t x = 4;

	printf("%u\n", return_next_pow_two(x));
	return 0;
}