#include <stdio.h>
#include <stdlib.h>

int find_in_substring(char *haystack , char *needle)
{
	int haystack_index = 0;
	int needle_index = 0;
	int starting_point = NULL;

	while(haystack[haystack_index] != '\0')
	{
		if (haystack[haystack_index] == needle[needle_index])
		{
			starting_point = haystack_index;
			while(haystack[haystack_index] == needle[needle_index] && needle[needle_index] != '\0')
			{
				needle_index++;
				haystack_index++;
			}
			if (needle[needle_index] != '\0')
			{
				needle_index = 0;
				starting_point = NULL;
			}
			else
			{
				return starting_point;
			}
		}
		else
		{
			haystack_index++;
		}
	}
	return -1;
}

int main()
{
	char haystack[20] = "asasgya";
	haystack[7] = '\0';
	char needle[4] = "ft";
	needle[2] = '\0';
	char *haystack_pointer = &haystack;
	char *needle_pointer = &needle;

	printf("Position first found at :%d\n", find_in_substring(haystack_pointer , needle_pointer));

	return 0;
}