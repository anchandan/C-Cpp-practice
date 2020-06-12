#include <stdio.h>
#include <stdint.h>

typedef union
{
	uint32_t full_32_bit;

	struct
	{
		unsigned byte1 : 8;
		unsigned byte2 : 8;
		unsigned byte3 : 8;
		unsigned byte4 : 8;
	}__attribute__((packed));
}bit_struct;

typedef struct 
{
	uint8_t two_bits : 2;
	uint8_t four_bits : 4;
	uint8_t byte; 
}some_struct;

void main()
{
	bit_struct var;
	some_struct some_var;
	
	var.byte1 = 256;
	var.byte2 = 4;

	some_var.two_bits = 4;
	some_var.byte = 10;	

	printf("%u\n", sizeof(some_var));
}