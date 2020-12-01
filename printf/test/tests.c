#include <stdio.h>
#include <math.h>

int main()
{
	char str[80];
	float num = 2.550f;
	int m = log10(num);
	int digit;
	float tolerance = 0.00000000000000000001;
	float weight;
	char *fstr;

	fstr = &(str[0]);
	printf("%.20f\n",num);
	while (num > 0 + tolerance)
	{
    	weight = pow(10.0f, m);
	    digit = floor(num / weight);
	    num -= (digit * weight);
	    *(fstr++)= '0' + digit;
	    if (m == 0)
	        *(fstr++) = '.';
    	m--;
	}
	*(fstr) = '\0';
	fstr = &(str[0]);
	printf("%s\n",fstr);
}
