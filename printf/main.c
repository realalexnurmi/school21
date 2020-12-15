#include "libftprintf.h"
#include <locale.h>

int main()
{
    wchar_t*	strw = L"古古古";
	wchar_t		h = L'古';
	char		*str = "Hello!";

	const char		*s = "\n|%010.1lc|\n";
	setlocale(LC_ALL, "");

	//str = ft_wcstombs(strw);
	//ft_putstr_fd(str, 1);
	//printf("\nCL:%zu\n", ft_get_charcount(6, str));
	//printf("PF: %d\n", printf(s, h));
	//printf("MY: %d\n", ft_printf(s, h));
	printf("\n%s\n", ft_lltoa_base(-32, 16));
	return (1);
}
