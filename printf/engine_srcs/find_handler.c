/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:24:22 by enena             #+#    #+#             */
/*   Updated: 2020/12/18 01:12:21 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "libftprintf_bonus.h"
#else
# include "libftprintf.h"
#endif

t_func_do	ft_conv_find_func(char supp_conv)
{
	unsigned int	counter;

	counter = 0;
	while (counter < CONV_COUNT)
	{
		if (supp_conv == g_conv_array_printf[counter])
			return (g_func_array_printf[counter]);
		counter++;
	}
	return (NULL);
}
