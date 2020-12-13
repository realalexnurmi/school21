/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_parsing_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:00:06 by enena             #+#    #+#             */
/*   Updated: 2020/12/13 11:29:56 by enena            ###   ########.fr       */
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

t_bool			ft_last_num(int **find, char *s, t_bool is_width)
{
	t_bool	found;
	int		last;

	found = FALSE;
	last = 0;
	while (!(found) && *--s != '%' &&
			!(*s == '*'))
	{
		if (ft_isdigit(*s) && !(ft_isdigit(*(s - 1))) && ((*(s - 1) != '.') == is_width))
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
	ft_check_special_case(curr, (s - 1));
}

void			ft_check_special_case(t_list_prf *curr, char *s)
{
	if (curr->width && *(curr->width) < 0)
	{
		*(curr->width) *= -1;
		curr->flag = curr->flag | MNUS_FLAG;
	}
	if (curr->flag & PLUS_FLAG)
		curr->flag &= (~(SPCE_FLAG));
	if (curr->flag & MNUS_FLAG)
		curr->flag &= (~(ZERO_FLAG));
	if (ft_isupper(*s))
		curr->flag = curr->flag | UPCS_FLAG;
	*s = ft_tolower(*s);
	if (curr->prec && (*s == 'd' || *s == 'i' || *s == 'o' || *s == 'x'))
		curr->flag &= (~(ZERO_FLAG));
}
