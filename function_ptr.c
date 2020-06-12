#include <stdio.h>
#include <stdlib.h>

void print_number(int number)
{
	printf("%d\n", number);
}

void say_hi()
{
	printf("Hi\n");
}

int return_increment(int number)
{
	return ++number;
}

int main()
{
	void (*fun_ptr)(void) = &say_hi;
	int x = 5;
	fun_ptr();
	//printf("Number:%d\n" , fun_ptr(x));
	return 0;
}