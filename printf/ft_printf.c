/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:37:53 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 18:32:56 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "libftprintf_bonus.h"
#else
# include "libftprintf.h"
#endif

int				ft_printf(char const *format, ...)
{
	char			*print_str;
	char			**s_tab;
	size_t			len;
	va_list			list_arg;
	t_list_prf		*list_spec;

	list_spec = NULL;
	s_tab = NULL;
	if (!(ft_preparser(&list_spec, format)))
		return (ft_error_escape(&list_spec, &s_tab));
	if (list_spec)
	{
		va_start(list_arg, format);
		if (!(ft_lstprf_parser_fill(list_spec, &list_arg, format)) ||
				!(ft_lstprf_apply_func_to_content(list_spec)) ||
				!(ft_lstprf_in_tab(&list_spec, &s_tab, format)))
			return (ft_error_escape(&list_spec, &s_tab));
	}
	if (!(print_str = s_tab ? ft_connect(&s_tab) : ft_strdup(format)))
		return (ft_error_escape(&list_spec, &s_tab));
	len = ft_putstr_fd(print_str, 1);
	free(print_str);
	print_str = NULL;
	return ((int)len);
}
