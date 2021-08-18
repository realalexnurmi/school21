#include "libft.h"
// Returns TRUE (1) if character uppercase letter, else FALSE (0)
t_bool	ft_isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (true);
	else
		return (false);
}
