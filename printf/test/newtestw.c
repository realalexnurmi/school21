#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>

void ft_check(int a, ...)
{
	char s;

	va_list ap;
	va_start(ap, a);
	s = va_arg(ap, char);
	printf("%hhu.", s);
	s = va_arg(ap, char);
	printf("%hhu.", s);
	s = va_arg(ap, char);
	printf("%hhu.", s);
}

int main()
{
	setlocale(LC_ALL, "");
	char	*s;

	s = malloc(sizeof(int));
	*s = 12;
	printf("\n|%p, %#lx, %p, %lx|\n", s, s, &s, &s);
}
