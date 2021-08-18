#include "libft.h"
// Returns TRUE (1) if character printed, else FALSE (0)
t_bool	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (true);
	else
		return (false);
}
