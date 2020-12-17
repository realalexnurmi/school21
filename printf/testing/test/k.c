#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
	signed char	*s;
	signed char	*s1;
	signed char	*s2;

	s = malloc(sizeof(char));
	s1 = malloc(sizeof(char));
	s2 = malloc(sizeof(char));
	*s = 0b10010000;
	printf("\n|%hhd|\n", *s);
	*s1 = ~(*s);
	printf("\n|%hhd|\n", *s1);
	*s2 = ~(*s - 1);
	printf("\n|%hhd|\n", *s2);
}
