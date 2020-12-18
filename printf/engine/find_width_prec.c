/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_width_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:43:18 by enena             #+#    #+#             */
/*   Updated: 2020/12/18 21:28:41 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

t_bool	ft_check_width_prec(t_list_prf *curr, va_list *ap, char *s)
{
	while (*++s)
	{
		if (*s == '.')
			if (!(curr->prec))
			{
				if (!(curr->prec = malloc(sizeof(int))))
					return (FALSE);
				*(curr->prec) = 0;
			}
		if (*s == '*')
		{
			if (*(s - 1) == '.')
				*(curr->prec) = va_arg(*ap, int);
			else
			{
				if (!(curr->width))
					if (!(curr->width = malloc(sizeof(int))))
						return (FALSE);
				*(curr->width) = va_arg(*ap, int);
			}
		}
	}
	return (ft_last_num(&(curr->prec), s, FALSE)
			&& ft_last_num(&(curr->width), s, TRUE));
}

t_bool	ft_last_num(int **find, char *s, t_bool is_width)
{
	t_bool	found;
	int		last;

	found = FALSE;
	last = 0;
	while (!(found) && *--s != '%' &&
			!(*s == '*'))
	{
		if (ft_isdigit(*s) && !(ft_isdigit(*(s - 1))) &&
				((*(s - 1) != '.') == is_width))
		{
			last = ft_atoi(s);
			if (last > 0)
				found = TRUE;
		}
		if (found)
		{
			if (!(*find))
				if (!((*find) = malloc(sizeof(int))))
					return (FALSE);
			**find = last;
		}
	}
	return (TRUE);
}
