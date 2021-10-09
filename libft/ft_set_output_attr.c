/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_output_attr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:22:48 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:22:50 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function for setting attr text output from enum {t_text_attr}
static char	*pick_setstring_from_attr(t_text_attr attr)
{
	const char	ss[26][6] = {
		"\033[0m", "\033[1m", "\033[2m", "\033[4m", "\033[5m",
		"\033[7m", "\033[22m", "\033[24m", "\033[25m", "\033[27m", "\033[30m",
		"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m",
		"\033[37m", "\033[40m", "\033[41m", "\033[42m", "\033[43m", "\033[44m",
		"\033[45m", "\033[46m", "\033[47m"};

	return (ft_strdup(ss[attr]));
}

t_bool		ft_set_output_attr(int fd, t_text_attr attr)
{
	char	*setstring;

	setstring = NULL;
	if (!(setstring = pick_setstring_from_attr(attr)))
		return (false);
	write(fd, setstring, 6);
	setstring = ft_sec_free(setstring);
	return (true);
}
