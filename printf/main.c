#include "libftprintf.h"
#include <locale.h>

int main()
{
    wchar_t*	haiku = L"古古古古古古古古古";
	wchar_t		h = L'古';
	char		*str = "Hello!";

	const char		*s = "\n|%0*.*s|\n";
	const char		*ds = "\\n|%10.3s|\\n";
	setlocale(LC_ALL, "");

	//str = ft_wcstombs(haiku);
	//ft_putstr_fd(str, 1);
	printf("%s\n", ds);
	printf(s, -10, 3, str);
	ft_printf(s, -10, 3, str);
	return (1);
}
