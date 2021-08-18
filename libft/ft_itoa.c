#include "libft.h"
char	*ft_itoa(int n)
{
	char	*s;
	size_t	cnt;
	int		copy;

	cnt = 0;
	copy = n;
	if (copy <= 0)
		cnt++;
	while (copy)
	{
		copy /= 10;
		cnt++;
	}
	if (!(s = ft_calloc((cnt + 1), sizeof(char))))
		return (NULL);
	if (n < 0)
		*s = '-';
	while (cnt-- > (*s == '-'))
	{
		s[cnt] = (n < 0 ? -(n % 10) : n % 10) + '0';
		n /= 10;
	}
	return (s);
}
