#include "libftprintf.h"
#include <locale.h>

int main()
{
    wchar_t*	strw = L"古古古";
	wchar_t		h = L'古';
	char		*str = "Hello!";
	char		*str1;
	t_uint u = 1215051;
	int i, i1;


	const char		*s = "\n|%+020.15u %p %n|\n";
	setlocale(LC_ALL, "");
	i = 0;
	i1 = 0;
	//str = ft_wcstombs(strw);
	//ft_putstr_fd(str, 1);
	//printf("\nCL:%zu\n", ft_get_charcount(6, str));
	printf("PF: %d\n", printf(s, u, str, &i));
	printf("NPF: %d\n", i);
	printf("MY: %d\n", ft_printf(s, u, str, &i1));
	printf("NMY: %d\n", i1);
	//printf("\ni: %lld lltoa: %s\n", i1, ft_lltoa_base(i1, 10));
	//printf("\ni: %lld lltoa: %s\n", i2, ft_lltoa_base(i2, 10));
	//printf("\ni: %d lltoa: %s\n", i3, ft_lltoa_base(i3, 10));
	//printf("\ni: %d lltoa: %s\n", i4, ft_lltoa_base(i4, 10));
	//printf("\ni: %llu lltoa: %s\n", u, ft_ulltoa_base(u, 10));
	return (1);
}
