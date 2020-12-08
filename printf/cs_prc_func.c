/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_prc_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:45:09 by enena             #+#    #+#             */
/*   Updated: 2020/12/08 16:55:40 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_s_func(void *node)
{
	t_list_prf	*lcl;
	char		*str;
	size_t		len;

	lcl = (t_list_prf *)node;
	str = *((char **)lcl->p_cnt);
	len = ft_strlen(str);
	lcl->print = ft_strdup(str);
	return (true);
}

t_bool	ft_c_func(void *node)
{
	t_list_prf	*lcl;
	char		c;

	lcl = (t_list_prf *)node;
	c = *((char *)lcl->p_cnt);
	lcl->print = ft_calloc(2, sizeof(char));
	(lcl->print)[0] = c;
	return (true);
}

t_bool	ft_prc_func(void *node)
{
	return (TRUE);
}
