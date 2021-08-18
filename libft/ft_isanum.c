#include "libft.h"
// Return [true] if string represent number, else [false]
t_bool	ft_isanum(char *s)
{
	while (ft_isspace(*s))
		s++;
	if ((*s == '-') || (*s == '+'))
		s++;
	while (ft_isdigit(*s))
	{
		s++;
		if (!(*s))
			return (true);
	}
	return (false);
}
