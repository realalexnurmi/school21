/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:37:53 by enena             #+#    #+#             */
/*   Updated: 2020/11/22 20:59:15 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_lstprf_anlz(t_list_prf **lst)
{
	while (*lst)
	{

		*lst = (*lst)->next;
	}
}

t_list_prf		*ft_lstprf_last(t_list_prf *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void			ft_lstprf_addback(t_list_prf **lst, t_list_prf *new)
{
	if (new)
	{
		if (*lst)
			ft_lstprf_last(*lst)->next = new;
		else
			*lst = new;
	}
}

t_list_prf		*ft_lstprf_new(size_t begin, size_t end, t_func_do func)
{
	t_list_prf	*new;

	if (!(new = malloc(sizeof(t_list_prf))))
		return (NULL);
	new->next = NULL;
	new->begin = begin;
	new->end = end;
	new->func = func;
	new->flag = NONE_FLAG;
	new->width = 0;
	new->prec = 0;
	new->size = NONE;
	new->content = NULL;
	new->print = NULL;
	return (new);
}

t_func_do		ft_conv_comp(char const supp_conv)
{
	unsigned int	counter;

	counter = 0;
	while (counter < CONV_COUNT)
	{
		if (supp_conv == g_conv_array[counter])
			return (g_func_array[counter]);
		counter++;
	}
	return (NULL);
}

size_t			ft_parser(t_list_prf **l_spec, char const *fs)
{
	size_t		ind_len;
	size_t		ind_end;
	t_func_do	func;

	ind_len = 0;
	while (fs[ind_len])
	{
		if (fs[ind_len] == '%')
		{
			ind_end = ind_len + 1;
			func = NULL;
			while (fs[ind_end] && (!func))
			{
				if (!(func = ft_conv_find_func(fs[ind_end])))
				{
					ft_lstprf_addback(l_spec,
							ft_lstprf_new(ind_len, ind_end, func));
				}
				ind_end++;
			}
			ind_len = ind_end - 1;
		}
		ind_len++;
	}
	return (ind_len);
}

int				ft_printf(char const *format, ...)
{
	char			*print_str;
	size_t			print_len;
	va_list			list_arg;
	t_list_prf		*list_spec;

	va_start(list_arg, format);
	list_spec = NULL;
	print_len = ft_parser(&list_spec, format);
	ft_lstprf_anlz();
	return (print_len);
}
