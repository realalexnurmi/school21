#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "");
	char *s = "ccccc";
	int *i;

	i = malloc(sizeof(int));
	printf("|%x|\n", &i);
}
