#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*divide(char *num)
{
	int i;
	char *rs;
	char nn;
	char per;

	rs = num;
	i = 0;
	per = '0';
	while (*num)
	{
		nn = ((((per - '0') * 10) + (*num - '0')) / 2) + '0';
		per = ((*num - '0') % 2) + '0';
		*num = nn;
		num++;
	}
	*num = '5';
	return (rs);
}

char *adding(char *add, char *trm)
{
	char *rs;
	char sum;
	char per;

	rs = add;
	while (*++trm)
		add++;
	trm--;
	per = '0';
	while (add != rs)
	{
		sum = (*add - '0') + (*trm - '0') + (per - '0');
		if (sum >= 10)
		{
			per = '1';
			sum -= 10;
		}
		else
			per = '0';
		*add = sum + '0';
		trm--;
		add--;
	}
	sum = (*add - '0') + (*trm - '0') + (per - '0');
	*add = sum + '0';
	return (rs);
}

int main(int argc, char **argv)
{
	char	*p;
	char	*drob;
	char	*t_drob;
	char	*addendum;
	int		len;

	p = (argc > 1) ? argv[1] : argv[0];
	len = strlen(p);
	addendum = calloc(len + 1, sizeof(char));
	addendum[0] = '5';
	drob = malloc(sizeof(char)*(len + 1));
	drob[len] = '\0';
	t_drob = drob;
	while (len--)
	{
		*t_drob = '0';
		t_drob++;
	}
	while (*p)
	{		
		printf("Add:%s\n", addendum);
		printf("Sum:%s\n", drob);
		if (*p++ == '1')
			drob = adding(drob, addendum);
		addendum = divide(addendum);
	}
	printf("All:%s\n", drob);
	free(drob);
	free(addendum);
}
