/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doprec_fstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:55:07 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:29:02 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		increasenum(char *p, char *e)
{
	t_bool		hasdig;
	char		trans;

	hasdig = false;
	while (--e != p + 1 + (*(p + 1) == '.'))
		if (*e != '0')
			hasdig = true;
	trans = 1;
	if (!hasdig && ft_iseven(*p))
		trans = 0;
	--e;
	while (trans)
	{
		if (*e == '.')
			--e;
		*e = (*e - '0' + trans) + '0';
		trans = 0;
		if (*e - '0' >= 10)
		{
			*e -= 10;
			trans = 1;
		}
		--e;
	}
}

char			*ft_doprec_fstr(char *num, int prec)
{
	char		*dot_tmp;
	size_t		lendec;
	char		*ret;

	if (!num)
		return (NULL);
	dot_tmp = ft_strchr(num, '.');
	lendec = ft_strlen(dot_tmp);
	if ((size_t)prec >= lendec)
	{
		if (!(dot_tmp = ft_zerroc(prec - lendec + 1)) ||
				!(ret = ft_strjoin(num, dot_tmp)))
			return (NULL);
		free(dot_tmp);
	}
	else
	{
		if (dot_tmp[prec + 1] >= '5')
			increasenum(dot_tmp + prec - (prec == 0), dot_tmp + lendec);
		dot_tmp[prec + (prec != 0)] = '\0';
		ret = ft_strdup(num);
	}
	free(num);
	return (ret);
}
