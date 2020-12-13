/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:43:01 by enena             #+#    #+#             */
/*   Updated: 2020/12/12 19:55:58 by enena            ###   ########.fr       */
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
		if (!(s = ft_substr(fs, curr->begin, curr->end - curr->begin)) ||
				!(ft_check_width_prec(curr, ap, s)))
		{
			va_end(*ap);
			return (FALSE);
		}
		ft_check_flag_size(curr, s);
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

t_bool			ft_lstprf_apply_func_to_content(t_list_prf *curr)
{
	int			offset;

	offset = 0;
	while (curr)
	{
		curr->ofst = offset;
		if (!(curr->func(curr)))
			return (FALSE);
		offset += ft_strlen(curr->print) - (curr->end - curr->begin + 1);
		curr = curr->next;
	}
	return (TRUE);
}

t_bool			ft_lstprf_in_tab(t_list_prf **head, char ***s_tab,
															const char *fs)
{
	char		**s_curr;
	size_t		start;

	if (!(*s_tab = malloc(sizeof(char *) * (2 + 2 * ft_lstprf_size(*head)))))
		return (FALSE);
	s_curr = *s_tab;
	start = 0;
	while (*head)
	{
		*s_curr = ft_substr(fs, start, ((*head)->begin - start));
		s_curr++;
		start = (*head)->end + 1;
		*s_curr = ft_strdup((*head)->print);
		s_curr++;
		*head = ft_lstprf_del_first(head);
	}
	*s_curr = ft_substr(fs, start, ft_strlen(&(fs[start])));
	s_curr++;
	*s_curr = NULL;
	return (TRUE);
}

char			*ft_connect(char ***s_tab)
{
	char	*out_str;
	char	*new_str;
	char	**s_curr;

	s_curr = *s_tab;
	if (!(out_str = ft_strjoin(*(s_curr), *(s_curr + 1))))
		return (NULL);
	free(*(s_curr));
	free(*(s_curr + 1));
	s_curr = s_curr + 2;
	while (*s_curr)
	{
		if (!(new_str = ft_strjoin(out_str, *(s_curr))))
			return (NULL);
		free(out_str);
		free(*(s_curr));
		s_curr++;
		out_str = new_str;
	}
	free(*s_tab);
	*s_tab = NULL;
	return (out_str);
}
