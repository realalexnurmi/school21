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


	const char		*s = "\n|%.3s|\n";
	setlocale(LC_ALL, "");
	printf("MY: %d\n", ft_printf(s, str));
	printf("PF: %d\n", printf(s, str));
	printf("PF: %d\n", printf("\n%s\n", str));
	return (1);
}
