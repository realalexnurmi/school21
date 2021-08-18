#include "libft.h"
size_t		ft_stous(long long int signd)
{
	size_t	ret;

	if (signd < 0)
		ret = ~signd + 1;
	else
		ret = signd;
	return (ret);
}
