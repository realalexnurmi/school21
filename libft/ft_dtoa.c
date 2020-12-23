/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:36:10 by enena             #+#    #+#             */
/*   Updated: 2020/12/23 13:08:09 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*getint(t_ullint mant, long long int exp)
{
	const float	log2_10 = 0.3010299;
	char		*ret;
	char		*add;
	char		*s_exp;
	size_t		len;

	if (exp <= 0)
		return (ft_strdup((exp == -1023) ? "0" : "1"));
	len = (size_t)(((exp + 1) * log2_10) + 1);
	if (!(add = ft_zerroc(len + 2, sizeof(char))) ||
			!(s_exp = ft_ulltoa_base(exp, 10)))
		return (NULL);
	add[len] = '2';
	if (!(add = ft_pownumstr(add, s_exp)) ||
			!(ret = ft_strdup(add)))
		return (NULL);
	while (exp--)
	{
		ft_halfnumstr(add);
		if (mant & 0x8000000000000000)
			ft_sumnumstr(ret, add);
		mant <<= 1;
	}
	//ft_twinfree((void **)(&add), ((void **)&s_exp));
	free(add);
	free(s_exp);
	return (ret);
}

static char			*doprec(char *dec, int prec, char *inta)
{
	char	trans;
	char	*save;

	trans = 0;
	save = dec;
	if (dec[prec + 1] - '0' >= 5)
	{
		trans = 1;
		dec = dec + prec;
	}
	while (trans && *dec != '.')
	{
		*dec = (*dec - '0' + trans) + '0';
		trans = 0;
		if (*dec - '0' >= 10)
		{
			*dec -= 10;
			trans = 1;
		}
		dec--;
	}
	if (trans)
		ft_sumnumstr(inta, "1");
	save[prec + 1] = '\0';
	return (save);
}

static char			*getdec(t_ullint mant, t_ullint exp, int prec, char *inta)
{
	char	*ret;
	char	*add;

	if (prec == 0)
		return (ft_strdup(""));
	if (exp >= 52)
		return (ft_zerroc(prec + 1, sizeof(char)));
	if (!(ret = ft_zerroc(prec + 2, sizeof(char))) ||
			!(add = ft_zerroc(prec + 2, sizeof(char))))
		return (NULL);
	mant <<= exp;
	exp = 52 - exp;
	add[0] = '5';
	while (exp--)
	{
		if (mant & 0x8000000000000000)
			ft_sumnumstr(ret, add);
		ft_halfnumstr(add);
		mant <<= 1;
	}
	free(add);
	add = ret;
	ret = ft_strjoin(".", ret);
	free(add);
	return (doprec(ret, prec, inta));
}

static t_binary_d	getmem(double dnum)
{
	t_binary_d	mem;

	ft_memcpy(&mem.mant, &dnum, 8);
	mem.sign = (mem.mant >> 63) & 0x0000000000000001;
	mem.exp = ((mem.mant >> 52) & 0x00000000000007ff) - 1023;
	mem.mant &= 0x000fffffffffffff;
	return (mem);
}

char				*ft_dtoa(double dnum, int prec)
{
	t_binary_d	mem;
	char		*int_ret;
	char		*dec;
	char		*temp;

	int_ret = NULL;
	dec = NULL;
	temp = NULL;
	if (dnum != dnum)
		return (ft_strdup("nan"));
	mem = getmem(dnum);
	if (mem.exp == 1024)
		return (mem.sign ? ft_strdup("-inf") : ft_strdup("inf"));
	if (!(temp = getint(mem.mant, mem.exp)))
		return (NULL);
	int_ret = temp;
	if ((!(dec = getdec(mem.mant, mem.exp, prec, int_ret))) ||
			(!(temp = ft_strjoin(int_ret, dec))))
		return (NULL);
	if ((ft_strlen(int_ret) > 1) && (*int_ret == '0'))
		temp = ft_memmove(temp, temp + 1, ft_strlen(temp) + 1);
	//ft_twinfree((char **)(&int_ret), ((char **)(&dec)));
	free(int_ret);
	free(dec);
	if (!(int_ret = mem.sign ? ft_strjoin("-", int_ret) : int_ret))
		return (NULL);
	return (int_ret);
}
