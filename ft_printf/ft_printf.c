/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:37:53 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 15:51:20 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char const *format, ...)
{
	size_t			len;
	va_list			list_arg;
	t_list_prf		*list_spec;

	list_spec = NULL;
	if (!(ft_preparser(&list_spec, format)))
		return (ft_error_escape(&list_spec));
	if (list_spec)
	{
		va_start(list_arg, format);
		if (!(ft_lstprf_parser_fill(list_spec, &list_arg, format)) ||
				!(ft_lstprf_apply_func_to_content(list_spec)) ||
				!(ft_printlist(&list_spec, &len, format)))
			return (ft_error_escape(&list_spec));
	}
	else
		len = ft_putstr_fd((char *)format, 1);
	return ((int)len);
}
