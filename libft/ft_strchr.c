#include "libft.h"
char	*ft_strchr(const char *s, int c)
{
	size_t	st_len;

	st_len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + st_len));
	else
		return ((char *)ft_memchr(s, c, st_len));
}
