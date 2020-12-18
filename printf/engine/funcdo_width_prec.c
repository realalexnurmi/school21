/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcdo_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:46:19 by enena             #+#    #+#             */
/*   Updated: 2020/12/18 19:45:33 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

char	*ft_make_min_width(t_list_prf *lp, char *pr)
{
	size_t	len;
	char	setchar;
	char	*add;
	char	*ret;

	if (lp->width)
	{
		len = ft_strlen(pr);
		ret = pr;
		if ((size_t)*(lp->width) > len)
		{
			if (!(add = ft_calloc(*(lp->width) - len + 1, sizeof(char))))
				return (NULL);
			setchar = (lp->flag & ZERO_FLAG) ? '0' : ' ';
			ft_memset(add, setchar, *(lp->width) - len);
			if (!(ret = (lp->flag & MNUS_FLAG) ? ft_strjoin(pr, add) :
				ft_strjoin(add, pr)))
				return (NULL);
			free(add);
			free(pr);
		}
		return (ret);
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

char	*ft_take_prec_int(t_list_prf *lp, char *pr)
{
	size_t	len;
	char	*add;
	char	*ret;

	if (lp->prec)
	{
		len = ft_strlen(pr) - !(ft_isdigit(*pr));
		if (((size_t)*(lp->prec) > len) && (len = *(lp->prec) - len))
		{
			if (!(add = ft_calloc(len + 1, sizeof(char))))
				return (NULL);
			ft_memset(add, '0', len);
			if (!(ft_isdigit(*pr)))
			{
				add[0] = *pr;
				*pr = '0';
			}
			if (!(ret = ft_strjoin(add, pr)))
				return (NULL);
			free(add);
			free(pr);
			return (ret);
		}
	}
	return (pr);
}
