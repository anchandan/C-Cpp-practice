#include <stdio.h>
#include <stdlib.h>

void memcpy(void *dest , const void *src , int number_of_bytes)
{
	for (int i = 0; i < number_of_bytes; i++)
	{
		*dest[i] = *src[i];
	}
}

int main()
{
	char src[] = "Aman";
	char dest[50];

	memcpy(dest , src , 4);
	printf("%s\n", (char *)dest);
}