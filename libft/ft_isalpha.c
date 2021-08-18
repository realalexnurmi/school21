#include "libft.h"
// Returns TRUE (1) if character letter, else FALSE (0)
t_bool	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
