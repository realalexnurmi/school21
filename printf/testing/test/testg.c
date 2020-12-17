#include <stdio.h>
#include <math.h>

int main()
{
	double i = 0.0 / 0.0;
	if (i != i)
		printf("WAT");
	else
		printf("OK");
}
