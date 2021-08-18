#include "libft.h"
// Returns TRUE (1) if character lowercase letter, else FALSE (0)
t_bool	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (true);
	else
		return (false);
}
