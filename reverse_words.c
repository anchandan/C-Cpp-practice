#include <stdio.h>
#include <string.h>


void reverse_word(char *begin , char *end)
{
	char temp;
	while(begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

void reverse_string(char *s)
{
	char *word_begin = s;

	char *temp = s;

	while(*temp)
	{
		temp++;
		if (*temp == '\0')
		{
			reverse_word(word_begin , (temp-1));
		}
		else if(*temp == ' ')
		{
			reverse_word(word_begin , (temp-1));
			word_begin = temp + 1;
		}
	}
	reverse_word(s , (temp-1));
}

int main()
{
	char s[] = "I like this program very much";
	char *ptr = s;
	reverse_string(ptr);
	printf("%s\n", ptr);
	return 0;
}