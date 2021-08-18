#include "libft.h"
// Returns TRUE (1) if character digit, else FALSE (0)
t_bool	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (true);
	else
		return (false);
}
