#include "libft.h"
t_bool	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
