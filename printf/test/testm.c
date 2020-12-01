#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst || src)
	{
		p_dst = (unsigned char *)dst;
		p_src = (unsigned char *)src;
		while (n--)
			*p_dst++ = *p_src++;
	}
	return (dst);
}

int main()
{
	int		b = 0b01000000010010001111010111000011; //0b11111111100000000000000000000000;
	float	*x;
	int		i = 32;
	int		*p;

	x = ft_memcpy(x, &b, sizeof(float));
	printf("%F\n", *x);
	printf("0b");
	p = (int*)x;
	while (i--)
		{
			if (*p & 0b10000000000000000000000000000000)
				printf("1");
			else
				printf("0");
			*p = *p << 1;
		}
	return (0);
}
