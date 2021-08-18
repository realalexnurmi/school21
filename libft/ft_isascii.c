#include "libft.h"
// Returns TRUE (1) if character in ASCII, else FALSE (0)
t_bool	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (true);
	else
		return (false);
}
