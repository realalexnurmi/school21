/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:48:00 by enena             #+#    #+#             */
/*   Updated: 2020/12/16 19:11:16 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_make_min_width(t_list_prf *lp, char *pr)
{
	size_t	len;
	char	*add;
	char	*ret;

	if (lp->width)
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
	return (pr);
}

char	*ft_take_space_plus(t_list_prf *lp, char *pr)
{
	char	*add;
	char	*ret;
	
	if ((lp->flag & SPCE_FLAG) || (lp->flag & PLUS_FLAG))
	{	
		if (!(add = ft_calloc(2, sizeof(char))))
			return (NULL);
		if (lp->flag & SPCE_FLAG)
			add[0] = ((*pr == '-') ? '-': ' ');
		else
			add[0] = ((*pr == '-') ? '-': '+');
		if (!(ret = ft_strjoin(add, pr)))
			return (NULL);
		free(pr);
		free(add);
		return (ret);
	}
	return (pr);
}

void	ft_take_prec_s(t_list_prf *lp, char *pr)
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

char	*ft_take_prec_dioux(t_list_prf *lp, char *pr)
{
	size_t	len;
	char	*add;
	char	*ret;

	if (lp->prec)
	{
		len = ft_strlen(pr) - !(ft_isdigit(*pr));
		if ((*(lp->prec) > len) && (len = *(lp->prec) - len))
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

char	*ft_hash(t_list_prf *lp, char *pr, t_bool isx)
{
	char	*ret;

	if (lp->flag & HASH_FLAG)
	{
		if (isx)
			ret = ft_strjoin("0x", pr);
		else
			ret = ft_strjoin("0", pr);
		if (!ret)
			return (NULL);
		free(pr);
		return (ret);
	}
	return (pr);
}
