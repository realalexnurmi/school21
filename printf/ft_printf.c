/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:37:53 by enena             #+#    #+#             */
/*   Updated: 2020/11/20 20:21:56 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list_func		*ft_init_lst_func(t_list_func **

size_t			ft_parser(t_list_prf **l_spec,
									t_list_func **l_func, char const *fs)
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
				if (!(func = ft_conv_comp(l_func, fs[ind_end])))
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
	t_list_func		*list_func;

	va_start(list_arg, format);
	list_func = NULL;
	list_func = ft_init_lst_func(&list_func);
	list_spec = NULL;
	print_len = ft_parser(&list_spec, &list_func, format);
	ft_analize_list_prf();
	return (print_len);
}
