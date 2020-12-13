/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:48:00 by enena             #+#    #+#             */
/*   Updated: 2020/12/13 11:59:01 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_get_charlen(size_t cnt_byte, char *mbs)
{
	size_t	cnt_char;
	size_t	wclen;

	cnt_char = 0;
	while ((cnt_byte) && (*mbs))
	{
		if (0x80 & *mbs)
		{
			wclen = ft_wclen(ft_mbtowc(mbs));
			if (wclen > cnt_byte)
				return (cnt_char);
			cnt_byte -= wclen;
			cnt_char++;
			mbs += wclen;
		}
		else
		{
			cnt_byte--;
			cnt_char++;
			mbs++;
		}
	}
	return (cnt_char);
}

char	*ft_make_min_width(t_list_prf *lp, char *pr)
{
	size_t	gcl;
	char	*add;
	char	*ret;

	if (!(lp->width))
		return (pr);
	else
	{
		gcl = ft_get_charlen(*(lp->width), pr);
		ret = pr;
		if (*(lp->width) > gcl)
		{
			if (!(add = ft_calloc(*(lp->width) - gcl + 1, sizeof(char))))
				return (NULL);
			ft_memset(add, ((lp->flag & ZERO_FLAG) ? '0' : ' '), *(lp->width) - gcl);
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
	if (lp->prec && *(lp->prec) < ft_strlen(pr))
		pr[*(lp->prec)] = '\0';
}
