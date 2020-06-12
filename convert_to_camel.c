#include <stdio.h>
#include <stdlib.h>


void to_camel_case(char *s , int s_len)
{
	for (int i = 0; i < s_len; i++)
	{
		if (s[i] == ' ')
		{
			int j = i;
			i++;
			printf("%c\n", s[i]);
			s[i] = s[i] - ' ';
			printf("%c\n", s[i]);
			while(s[i] != 32 && i < s_len)
			{
				s[j] = s[i];
				printf("%c\n", s[i]);
				j++;
				i++;
			}
			//s[j] = s[i+1];
			printf("Found space:%d\n",s[i]);
			i--;
			//s[j] = s[i];
		}
	}
	printf("%s\n", s);
}

int main()
{
	char str[] = "The man went to market to get some vegetables";
	str[45] = '\0';

	to_camel_case(str , 45);
}