#include "libft.h"
char	**ft_free_tab(char **removetb)
{
	char	**tmp;

	tmp = removetb;
	while (*tmp)
	{
		*tmp = ft_sec_free(*tmp);
		tmp++;
	}
	return (removetb = ft_sec_free(removetb));
}
