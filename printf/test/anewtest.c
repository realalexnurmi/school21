#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_tmp;

	p_tmp = (unsigned char*)b;
	while (len--)
	{
		*p_tmp = (unsigned char)c;
		p_tmp++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, (int)('\0'), n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p_temp;

	p_temp = malloc(count * size);
	if (p_temp)
		ft_bzero(p_temp, count * size);
	return (p_temp);
}

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

void	ft_putchar_fd(char *c, int fd)
{
	if (!((*c & 0x80) && !(*c & 0x40)))
	{
		if ((*c & 0x80) == 0x00)
			write(fd, c, 1);
		if ((*c & 0xC0) == 0xC0 && !(*c & 0x20))
			write(fd, c, 2);
		if ((*c & 0xE0) == 0xE0 && !(*c & 0x10))
			write(fd, c, 3);
		if ((*c & 0xF0) == 0xF0 && !(*c & 0x08))
			write(fd, c, 4);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
		{
			ft_putchar_fd(s, fd);
			s++;
		}
}

size_t	ft_wclen(wchar_t wc)
{
	wint_t	i;
	
	i = (wint_t)wc;
	if (i <= 0x0000007F)
		return (1);
	if (i <= 0x000007FF)
		return (2);
	if (i <= 0x0000FFFF)
		return (3);
	if (i <= 0x0010FFFF)
		return (4);
	return (0);
}

size_t	ft_wstrlen(wchar_t *wstring)
{
	size_t	len;

	len = 0;
	while (*wstring)
		len += ft_wclen(*wstring++);
	return (len);
}

size_t	ft_wc_to_mbc(wchar_t wc, char *s)
{
	unsigned char	oct[4];
	wint_t			num;
	size_t			wln;

	ft_bzero(oct, 4);
	num = (wint_t)wc;
	wln = ft_wclen(wc);
	oct[0] = ((0xF0 << ((4 - wln) + (wln == 1))) |
			(((0x7F >> (wln - (wln == 1)))) & (char)(num >> 8 * (wln - 1))));
	oct[1] = (wln < 2) ? oct[1] :
		((0x3F & (char)((num >> 8 * (wln - 2)) & 0x000000FF)) | 0x80);
	oct[2] = (wln < 3) ? oct[2] :
		((0x3F & (char)((num >> 8 * (wln - 3)) & 0x000000FF)) | 0x80);
	oct[3] = (wln < 4) ? oct[3] :
		((0x3F & (char)(num & 0x000000FF)) | 0x80);
	printf("|%hhx||%hhx||%hhx||%hhx|\n", oct[0], oct[1], oct[2], oct[3]);
	s = ft_memcpy(s, &(oct[0]), 4);
	return (wln);
}

char	*ft_wcs_to_mbcs(wchar_t *wstring)
{
	char	*s;

	s = ft_calloc(ft_wstrlen(wstring) + 1, sizeof(char));
	while (*wstring)
	{
		s += ft_wc_to_mbc(*wstring, s);
		wstring++;
	}
	return (s);
}

int main()
{
    setlocale(LC_ALL, "");
	//wchar_t w = L'i';
	//char s[4] = "i";
    //wchar_t *wcs = L"i";
	//wchar_t w = L'¾';
	//char s[4] = "¾";
    //wchar_t *wcs = L"¾";
	//wchar_t w = L'古';
	//char s[4] = "古";
    //wchar_t *wcs = L"古";
	wchar_t w = L'𐀁';
	char s[4] = "𐀁";
    wchar_t *wcs = L"𐀁";
    char *t;
	printf("|%hhx|%hhx|%hhx|%hhx|\n", s[0], s[1], s[2], s[3]);
	t = ft_wcs_to_mbcs(wcs);
	printf("%hhx", t[0]);
	ft_putstr_fd(t, 1);
}
