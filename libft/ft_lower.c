#include "libft.h"
// Convert all uppercase characters of string in lowercase
void	ft_lower(char *s)
{
	if (s)
		while (*s)
		{
			*s = ft_tolower(*s);
			s++;
		}
}
