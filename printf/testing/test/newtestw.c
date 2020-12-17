#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
	setlocale(LC_ALL, "");
	long long int	*s;

	s = malloc(sizeof(long long int));
	printf("%12800d%lln\n",1, s);
	printf("%lld\n", *s);
}
