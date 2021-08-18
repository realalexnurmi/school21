#include "libft.h"
// Returns [true] if character letter or digit, else [false]
t_bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
