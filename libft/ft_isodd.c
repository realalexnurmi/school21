#include "libft.h"
t_bool	ft_isodd(int c)
{
	if ((c == '1') || (c == '3') || (c == '5') || (c == '7') || (c == '9'))
		return (true);
	else
		return (false);
}
