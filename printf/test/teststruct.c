#include <stdio.h>

typedef struct	s_sct
{
	int a;
	char *s;
}				t_sct;

int main()
{
	t_sct d1;
	t_sct d2;

	d1.a = 5;
	d1.s = "sassdasdasdas";
	d2.a = 6;
	d2.s = "qqqqqqqqqqqqqqqqqqqq";
	printf("D1:%d %s\n", d1.a, d1.s);
	printf("D2:%d %s\n", d2.a, d2.s);
	d2 = d1;
	printf("D2 after D1:%d %s\n", d2.a, d2.s);
}
