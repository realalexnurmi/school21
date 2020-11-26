#include <stdio.h>
#include <string.h>
#include <stdarg.h>
//#include <math.h>

void	putback(int n, ...)
{
	int i;
	va_list	ap;

	i = 0;
	va_start(ap, n);
	while (++i < n)
		printf("%*d\n", va_arg(ap, size_t), 5);
	va_end(ap);
}

int main()
{
	signed char i;
	unsigned char i1;
	unsigned int i2;
	int i3;
	signed int i4;
	long int i5;
	unsigned long int i6;

	i = 20;
	i1 = 20;
	i2 = 20;
	i3 = 20;
	i4 = 20;
	i5 = 20;
	i6 = 20;
	putback(7, i, i1, i2, i3, i4, i5, i6);
	return (1);
}
