#include "libft.h"
// If [c] represents an lowercase letter,
// and there exists a corresponding uppercase letter.
// All other arguments in the domain are returned unchanged.
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c + ('A' - 'a'));
	else
		return (c);
}
