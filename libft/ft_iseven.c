#include "libft.h"
t_bool	ft_iseven(int c)
{
	if ((c == '0') || (c == '2') || (c == '4') || (c == '6') || (c == '8'))
		return (true);
	else
		return (false);
}
