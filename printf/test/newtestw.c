#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
	setlocale(LC_ALL, "");
	char	*s;

	s = malloc(sizeof(int));
	*s = 12;
	printf("\n|% d|\n", *s);
}
