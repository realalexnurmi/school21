/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcdo_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:46:19 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 23:44:15 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_make_min_width(t_list_prf *lp, char *pr)
{
	char	setchar;
	char	*add;
	char	*ret;

	lp->len = ft_strlen(pr);
	lp->len = (lp->len == 0 && lp->func == ft_c_func) ? 1 : lp->len;
	if (lp->width)
	{
		if ((size_t)*(lp->width) > lp->len)
		{
			if (!(ret = ft_calloc(*(lp->width) + 1, sizeof(char))))
				return (NULL);
			setchar = (lp->flag & ZERO_FLAG) ? '0' : ' ';
			add = (lp->flag & MNUS_FLAG) ? ret : ret + *(lp->width) - lp->len;
			ft_memcpy(add, pr, lp->len);
			add = (lp->flag & MNUS_FLAG) ? ret + lp->len : ret;
			ft_memset(add, setchar, *(lp->width) - lp->len);
			lp->len = *(lp->width);
			free(pr);
			return (ret);
		}
	}
	return (pr);
}

void	ft_take_prec_str(t_list_prf *lp, char *pr)
{
	size_t	c_cnt;

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

char	*ft_take_prec_int(t_list_prf *lp, char *pr, t_bool issigned)
{
	size_t	len;
	char	*add;
	char	*ret;

	if (lp->prec)
	{
		len = ft_strlen(pr) - issigned;
		if (((size_t)*(lp->prec) > len) && (len = *(lp->prec) - len))
		{
			if (!(add = ft_calloc(len + 1, sizeof(char))))
				return (NULL);
			ft_memset(add, '0', len);
			if (!(ret = ft_strjoin(add, pr)))
				return (NULL);
			free(add);
			free(pr);
			return (ret);
		}
	}	
	if ((!(lp->prec) || (*(lp->prec) == 0)) &&
			len == 1 && *(pr + issigned) == '0')
			*(pr + issigned) = '\0';	
	return (pr);
}
