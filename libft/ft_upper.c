#include "libft.h"
// Convert all lowercase characters of string in uppercase
void	ft_upper(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = ft_toupper(*s);
			s++;
		}
	}
}
