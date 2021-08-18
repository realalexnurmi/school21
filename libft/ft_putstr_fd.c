#include "libft.h"
size_t	ft_putstr_fd(char *s, int fd)
{
	size_t len;

	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}
