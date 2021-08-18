#include "libft.h"
t_bool	ft_check_extention(const char *name, const char *extn)
{
	if (ft_strncmp(ft_strrchr(name, '.'), extn, ft_strlen(extn) + 1))
		return (false);
	return (true);
}
