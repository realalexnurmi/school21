#include "libft.h"
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (p_dst > p_src)
		while (n--)
			p_dst[n] = p_src[n];
	else if (p_dst < p_src)
		while (n--)
			*p_dst++ = *p_src++;
	return (dst);
}
