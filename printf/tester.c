#include "tester.h"

char	ft_ffunc(t_func_do f)
{
	unsigned int			counter;

	counter = 0;
	while (counter < CONV_COUNT)
	{
		if (f == g_func_array_printf[counter])
			return (g_conv_array_printf[counter]);
		counter++;
	}
	return ('?');
}

char	ft_fsize(t_msize size)
{
	if (size == NONE)
		return ('0');
	if (size == L)
		return ('l');
	if (size == LL)
		return ('L');
	if (size == H)
		return ('h');
	if (size == HH)
		return ('H');
	if (size == Z)
		return ('z');
	return ('?');
}

t_bool printlist(t_list_prf *lst, t_bool ret)
{
	size_t i;

	printf("\nCoint of node: %zu\n", ft_lstprf_size(lst));
	i = 1;
	while (lst)
	{
		printf("Node #%3zu\n", i++);
		printf("\t%-10s:%5i\n", "ofst",lst->ofst);
		printf("\t%-10s:%5zu\n", "begin",lst->begin);
		printf("\t%-10s:%5zu\n", "end",lst->end);
		printf("\t%-10s:%5c\n", "func",ft_ffunc(lst->func));
		printf("\t%-10s:%5s\n", "width", ((lst->width) ? ft_itoa(*(lst->width)) : "NULL"));
		printf("\t%-10s:%5s\n", "prec", ((lst->prec) ? ft_itoa(*(lst->prec)) : "NULL"));
		printf("\t%-10s:%5x\n", "flag",lst->flag);
		printf("\t%-10s:%5c\n", "size", ft_fsize(lst->size));
		printf("\t%-10s:%s\n", "print",lst->print);
		lst = lst->next;
	}
	return (ret);
}
