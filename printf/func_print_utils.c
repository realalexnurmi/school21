/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:48:00 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 01:04:41 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "tester.h"

char	*ft_make_min_width(t_list_prf *lp, char *pr)
{
	size_t	len;
	char	*add;
	char	*ret;

	if (!(lp->width))
		return (pr);
	else
	{
		len = ft_strlen(pr);
		ret = pr;
		if (*(lp->width) > len)
		{
			if (!(add = ft_calloc(*(lp->width) - len + 1, sizeof(char))))
				return (NULL);
			ft_memset(add, ((lp->flag & ZERO_FLAG) ? '0' : ' '), *(lp->width) - len);
			if (!(ret = (lp->flag & MNUS_FLAG) ? ft_strjoin(pr, add) :
				ft_strjoin(add, pr)))
				return (NULL);
			free(add);
			free(pr);
		}
		return (ret);
	}
}

void	ft_take_prec(t_list_prf *lp, char *pr)
{
	size_t	c_cnt;
	char	*end;

	if (lp->prec)
	{
		c_cnt = ft_get_charcount((size_t)*(lp->prec), pr);
		if (ft_strlen(pr) > c_cnt)
		{
			while (c_cnt--)
				pr = ft_took_next_char(pr);
		*pr = '\0';
		}
	}
}
