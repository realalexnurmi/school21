#include "libft.h"
char	*ft_ulltoa_base(t_ullint n, t_uchar base)
{
	const char		digit[17] = "0123456789abcdef";
	char			*s;
	size_t			cnt;
	t_ullint		copy;

	if ((base == 0) || (base == 1) || (base > 16))
		return (NULL);
	cnt = 1;
	copy = n / base;
	while (copy)
	{
		copy /= base;
		cnt++;
	}
	s = ft_calloc((cnt + 1), sizeof(char));
	if (!(s))
		return (NULL);
	while (cnt-- > 0)
	{
		s[cnt] = digit[(n % base)];
		n /= base;
	}
	return (s);
}
