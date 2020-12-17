#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	foo2(va_list *ap)
{
	void *p;
	char *str;

	p = malloc(sizeof(char *));
	*((char **)p) = va_arg(*ap, char*);
	str = *((char **)p);
	str[0] = 'p';
	printf("%s\n", str);
	va_end(*ap);
}

void	foo(int a, ...)
{
	va_list	ap;

	va_start(ap, a);
	foo2(&ap);
}

int main()
{
	char *s;

	s = calloc(5 , sizeof(char));
	s = memset(s, 'k', 4);
	foo(1, s);
	printf("%s",s);
	return (1);
}
