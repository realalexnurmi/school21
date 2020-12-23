/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:43:01 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 15:53:11 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool			ft_preparser(t_list_prf **l_spec, char const *fs)
{
	size_t		ind_len;
	size_t		ind_end;
	t_func_do	func;
	t_list_prf	*new_node;

	ind_len = 0;
	new_node = NULL;
	while (fs[ind_len])
		if (fs[ind_len++] == '%')
		{
			ind_end = ind_len;
			func = NULL;
			while (fs[ind_end] && (!func))
			{
				if (!!(func = ft_conv_find_func(ft_tolower(fs[ind_end]))))
				{
					if (!(new_node = ft_lstprf_new(ind_len - 1, ind_end, func)))
						return (FALSE);
					ft_lstprf_addback(l_spec, new_node);
				}
				ind_end++;
			}
			ind_len = ind_end;
		}
	return (TRUE);
}

t_bool			ft_lstprf_parser_fill(t_list_prf *curr, va_list *ap,
															char const *fs)
{
	char		*s;

	while (curr)
	{
		s = NULL;
		if (!(s = ft_substr(fs, curr->begin, curr->end - curr->begin + 1)) ||
				!(ft_check_width_prec(curr, ap, s)))
		{
			if (s)
				free(s);
			va_end(*ap);
			return (FALSE);
		}
		ft_check_modify(curr, s);
		free(s);
		if (fs[curr->end] != '%')
			if (!(ft_claim_content(curr, ap, ft_tolower(fs[curr->end]))))
			{
				va_end(*ap);
				return (FALSE);
			}
		curr = curr->next;
	}
	va_end(*ap);
	return (TRUE);
}

t_bool			ft_printlist(t_list_prf **head, size_t *len, char const *fs)
{
	size_t	start;
	char	*part_fs;

	start = 0;
	*len = 0;
	part_fs = NULL;
	while (*head)
	{
		if (!(part_fs = ft_substr(fs, start, ((*head)->begin - start))))
			return (FALSE);
		*len += ft_putstr_fd(part_fs, 1);
		free(part_fs);
		part_fs = NULL;
		start = (*head)->end + 1;
		write(1, (*head)->print, (*head)->len);
		*len += (*head)->len;
		ft_lstprf_del_first(head);
	}
	if (!(part_fs = ft_substr(fs, start, ft_strlen(&(fs[start])))))
		return (FALSE);
	*len += ft_putstr_fd(part_fs, 1);
	free(part_fs);
	return (TRUE);
}
