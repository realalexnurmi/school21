/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:37:53 by enena             #+#    #+#             */
/*   Updated: 2020/12/01 21:45:21 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool			ft_last(size_t **find, char *s, t_bool is_width)
{
	t_bool	found;
	size_t	last;

	found = false;
	last = 0;
	while (!(found) && *--s != '%' &&
			!((*s == '*') && ((*(s - 1) != '.') == is_width)))
	{
		if (ft_isdigit(*s) && !(ft_isdigit(*(s - 1))))
		{
			last = (size_t)ft_atoi(s);
			if (last > 0)
				found = true;
		}
		if (found)
		{
			if (!(*find))
				if (!((*find) = malloc(sizeof(size_t))))
					return (false);
			**find = last;
		}
	}
	return (true);
}

t_bool			ft_check_width_prec(t_list_prf **curr, va_list *ap, char *s)
{
	while (*++s)
	{
		if (*s == '.')
			if (!(*curr)->prec)
			{
				if (!((*curr)->prec = malloc(sizeof(size_t))))
					return (false);
				*((*curr)->prec) = 0;
			}
		if (*s == '*')
		{
			if (*(s - 1) == '.')
				*((*curr)->prec) = va_arg(*ap, size_t);
			else
			{
				if (!(*curr)->width)
					if (!((*curr)->width = malloc(sizeof(size_t))))
						return (false);
				*((*curr)->width) = va_arg(*ap, size_t);
			}
		}
	}
	return (ft_last(&((*curr)->prec), s, false)
			&& ft_last(&((*curr)->width), s, true));
}

void			ft_check_size(t_msize *size, char *s)
{
	if (*s == 'l')
		*size = (*(s - 1) == 'l') ? LL : L;
	if (*s == 'h')
		*size = (*(s - 1) == 'h') ? HH : H;
	if (*s == 'z')
		*size = Z;
}

void			ft_check_flag_size(t_list_prf **curr, char *s)
{
	while (*++s)
	{
		if (*s == '0' && !(ft_isdigit(*(s - 1))) && *(s - 1) != '.')
			(*curr)->flag = (*curr)->flag | ZERO_FLAG;
		if (*s == '-')
			(*curr)->flag = (*curr)->flag | MNUS_FLAG;
		if (*s == '#')
			(*curr)->flag = (*curr)->flag | HASH_FLAG;
		if (*s == ' ')
			(*curr)->flag = (*curr)->flag | SPCE_FLAG;
		if (*s == '+')
			(*curr)->flag = (*curr)->flag | PLUS_FLAG;
		ft_check_size(&((*curr)->size), s);
	}
	if (ft_isupcase(*(s - 1)))
		(*curr)->flag = (*curr)->flag | UPCS_FLAG;
	if ((*curr)->width && *(*curr)->width < 0)
	{
		*(*curr)->width *= -1;
		(*curr)->flag = (*curr)->flag | MNUS_FLAG;
	}
}

t_bool			ft_claim_content(t_list_prf **curr, va_list *ap, char conv)
{
	if (((conv == 'c') || (conv == 's')) && ((*curr)->flag & UPCS_FLAG))
		(*curr)->size = L;
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		(*curr)->to_content = (double *)&(va_arg(*ap, double));
	if (conv == 'c')
		(*curr)->to_content = ((*curr)->size == L) ?
			(wchar_t *)&(va_arg(*ap, wchar_t)) : (char *)&(va_arg(*ap, char));
	if (conv == 's')
		(*curr)->to_content = ((*curr)->size == L) ?
			(wchar_t **)&(va_arg(*ap, wchar_t *)) :
			(char **)&(va_arg(*ap, char *));
	if (conv == 'p')
		(*curr)->to_content = (void **)&(va_arg(*ap, void *));
	if ((conv == 'd') || (conv == 'i'))
		(*curr)->to_content = (int *)&(va_arg(*ap, int));
}

t_bool			ft_lstprf_fill(t_list_prf **lst, va_list *ap,
								char const *fs)
{
	t_list_prf	*curr;
	char		*s;

	curr = (*lst);
	while (curr)
	{
		s = NULL;
		if (!(s = ft_substr(fs, curr->begin, curr->end - curr->begin)))
			return (false);
		if (!(ft_check_width_prec(&curr, ap, s)))
			return (false);
		ft_check_flag_size(&curr, s);
		free(s);
		ft_claim_content(&curr, ap, ft_lower(fs[curr->end]));
		curr = curr->next;
	}
	return (true);
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

	new = NULL;
	if (!(new = malloc(sizeof(t_list_prf))))
		return (NULL);
	new->next = NULL;
	new->begin = begin;
	new->end = end;
	new->func = func;
	new->flag = NONE_FLAG;
	new->width = NULL;
	new->prec = NULL;
	new->size = NONE;
	new->content = NULL;
	new->print = NULL;
	return (new);
}

t_func_do		ft_conv_find_func(char const supp_conv)
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

t_bool			ft_parser(t_list_prf **l_spec, char const *fs)
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
				if (!!(func = ft_conv_find_func(fs[ind_end])))
				{
					if (!(new_node = ft_lstprf_new(ind_len - 1, ind_end, func)))
						return (false);
					ft_lstprf_addback(l_spec, new_node);
				}
				ind_end++;
			}
			ind_len = ind_end;
		}
	return (true);
}

int				ft_printf(char const *format, ...)
{
	char			*print_str;
	size_t			print_len;
	va_list			list_arg;
	t_list_prf		*list_spec;

	print_len = ft_strlen(format);
	va_start(list_arg, format);
	list_spec = NULL;
	if (!(ft_parser(&list_spec, format)))
		return (-1);
	if (!(ft_lstprf_fill(&list_spec, &list_arg, format)))
		return (-1);
	va_end(list_arg);
	ft_lstprf_apply();
	return (print_len);
}
