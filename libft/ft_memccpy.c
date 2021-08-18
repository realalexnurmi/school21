#include "libft.h"
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;

	if (dst || src)
	{
		p_dst = (unsigned char *)dst;
		p_src = (unsigned char *)src;
		while (n--)
		{
			if (*p_src != (unsigned char)c)
				*p_dst++ = *p_src++;
			else
			{
				*p_dst = *p_src;
				return (++p_dst);
			}
		}
	}
	return (NULL);
}
