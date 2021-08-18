#include "libft.h"
// If [c] represents an uppercase letter,
// and there exists a corresponding lowercase letter.
// All other arguments in the domain are returned unchanged.
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + ('a' - 'A'));
	else
		return (c);
}
