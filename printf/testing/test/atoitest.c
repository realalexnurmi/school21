#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long int	ret;
	char			sign;

	ret = 0;
	sign = 1;
	while (*str && ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str && ft_isdigit(*str))
	{
		ret = ret * 10 + ((*str++ - '0') * sign);
		if (ret && (ret * sign < 0))
			return (sign > 0 ? -1 : 0);
	}
	return ((int)ret);
}

int main()
{
	printf("%d\n", atoi("92233725"));
	printf("%d\n", atoi("92233726"));
	printf("%d\n", atoi("92233727"));
	printf("%d\n", atoi("92233728"));
	printf("%d\n", atoi("92233729"));
	printf("%d\n", atoi("-92233725"));
	printf("%d\n", atoi("-92233726"));
	printf("%d\n", atoi("-92233727"));
	printf("%d\n", atoi("-92233728"));
	printf("%d\n", atoi("-92233729"));
	printf("\n");
	printf("%d\n", ft_atoi("92233725"));
	printf("%d\n", ft_atoi("92233726"));
	printf("%d\n", ft_atoi("92233727"));
	printf("%d\n", ft_atoi("92233728"));
	printf("%d\n", ft_atoi("92233729"));
	printf("%d\n", ft_atoi("-92233725"));
	printf("%d\n", ft_atoi("-92233726"));
	printf("%d\n", ft_atoi("-92233727"));
	printf("%d\n", ft_atoi("-92233728"));
	printf("%d\n", ft_atoi("-92233729"));
}
