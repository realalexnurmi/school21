/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_parsing_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:00:06 by enena             #+#    #+#             */
/*   Updated: 2020/12/08 16:58:35 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_func_do		ft_conv_find_func(char supp_conv)
{
	unsigned int			counter;

	counter = 0;
	while (counter < CONV_COUNT)
	{
		if (supp_conv == g_conv_array_printf[counter])
			return (g_func_array_printf[counter]);
		counter++;
	}
	return (NULL);
}

t_bool			ft_check_width_prec(t_list_prf *curr, va_list *ap, char *s)
{
	while (*++s)
	{
		if (*s == '.')
			if (!(curr->prec))
			{
				if (!(curr->prec = malloc(sizeof(int))))
					return (false);
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
						return (false);
				*(curr->width) = va_arg(*ap, int);
			}
		}
	}
	return (ft_last_num((curr->prec), s, false)
			&& ft_last_num((curr->width), s, true));
}

t_bool			ft_last_num(int *find, char *s, t_bool is_width)
{
	t_bool	found;
	int		last;

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
			if (!(find))
				if (!((find) = malloc(sizeof(int))))
					return (false);
			*find = last;
		}
	}
	return (true);
}

void			ft_check_flag_size(t_list_prf *curr, char *s)
{
	while (*++s)
	{
		if (*s == '0' && !(ft_isdigit(*(s - 1))) && *(s - 1) != '.')
			curr->flag = curr->flag | ZERO_FLAG;
		if (*s == '-')
			curr->flag = curr->flag | MNUS_FLAG;
		if (*s == '#')
			curr->flag = curr->flag | HASH_FLAG;
		if (*s == ' ')
			curr->flag = curr->flag | SPCE_FLAG;
		if (*s == '+')
			curr->flag = curr->flag | PLUS_FLAG;
		ft_check_size(&(curr->size), s);
	}
	if (ft_isupcase(*(s - 1)))
		curr->flag = curr->flag | UPCS_FLAG;
	if (curr->width && *(curr->width) < 0)
	{
		*(curr->width) *= -1;
		curr->flag = curr->flag | MNUS_FLAG;
	}
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
