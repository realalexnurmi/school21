#include "libft.h"
char	*ft_strdup(const char *s)
{
	char	*p_copy;
	size_t	len;

	len = ft_strlen(s);
	if (!(p_copy = ft_calloc(len + 1, sizeof(char))) || !s)
		return (NULL);
	while (len--)
		p_copy[len] = s[len];
	return (p_copy);
}
