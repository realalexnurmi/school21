#include "libft.h"
char	*ft_lltoa_base(long long int n, t_uchar base)
{
	const char	digit[17] = "0123456789abcdef";
	char		*s;
	size_t		cnt;
	t_ullint	copy;

	if ((base == 0) || (base == 1) || (base > 16))
		return (NULL);
	cnt = (n < 0) ? 2 : 1;
	copy = (n < 0) ? ~n + 1 : n;
	while (copy /= base)
		cnt++;
	if (!(s = ft_calloc((cnt + 1), sizeof(char))))
		return (NULL);
	if (n < 0)
		*s = '-';
	copy = (n < 0) ? ~n + 1 : n;
	while (cnt-- > (*s == '-'))
	{
		s[cnt] = digit[(copy % base)];
		copy /= base;
	}
	return (s);
}
