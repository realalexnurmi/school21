#include "libft.h"
void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		c;

	ln = (long int)n;
	if (ln < 0)
	{
		ft_putchar_fd("-", fd);
		ln = -ln;
	}
	if (ln >= 10)
		ft_putnbr_fd((ln / 10), fd);
	c = (ln % 10) + '0';
	ft_putchar_fd(&c, fd);
}
