/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_part_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:45:35 by enena             #+#    #+#             */
/*   Updated: 2021/02/26 11:38:42 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"

/*
** Getting rule from {rule_name} with {data_rule}
*/
t_rule	get_rule(t_rn name, void *data)
{
	t_rule	ret;
	
	ret.name = name;
	ret.data = data;
	return (ret);
}

/*
** Main function to get the storage color struct [t_clr]
** from a given {rule}
*/
t_clr	took_clr(t_rule rule)
{
	t_clr	ret;

	ret = g_getclr[g_rlbk[rule.name].type](g_rlbk[rule.name].info, rule.data);
	return (ret);
}