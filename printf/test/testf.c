#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void change(char *s)
{
	s[0] = 'Y';
}

int main()
{
	char *s;

	s = calloc(5, sizeof(char));

	s[0] = 'H';
	s[1] = 'e';
	s[2] = 'l';
	s[3] = 'l';
	change(s);
	printf("%s",s);
}
