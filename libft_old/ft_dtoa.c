/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:36:10 by enena             #+#    #+#             */
/*   Updated: 2021/01/21 01:12:55 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*getint(t_ullint mant, long long int exp)
{
	const float	log2_10 = 0.3010299;
	char		*ret;
	char		*add;
	char		*s_exp;

	if (exp <= 0)
		return (ft_strdup(exp == 0 ? "1" : "0"));
	if (!(add = ft_zerroc((((exp + 1) * log2_10) + 1) + 1)) ||
			!(s_exp = ft_lltoa_base(exp, 10)))
		return (NULL);
	add[ft_strlen(add) - 1] = '2';
	if (!(add = ft_pownumstr(add, s_exp)) ||
			!(ret = ft_strdup(add)))
		return (NULL);
	while (exp-- > 0)
	{
		add = ft_halfnumstr(add);
		if (mant & 0x0008000000000000)
			ft_sumnumstr(ret, add);
		mant <<= 1;
	}
	free(add);
	free(s_exp);
	return (ret);
}

static char			*getdec(t_ullint mant, long long int exp, int prec)
{
	char	*ret;
	char	*add;

	exp = 52 - exp;
	if (exp <= 52)
		mant <<= 52 - exp + 1;
	if (!(ret = ft_zerroc(exp <= 0 ? prec + 2 : exp + 2)))
		return (NULL);
	if (exp > 0)
	{
		if (!(add = ft_zerroc(exp + 2)))
			return (NULL);
		add[0] = '1';
		while ((exp-- >= 0) &&
				(add = ((exp != 1074) ? ft_halfnumstr(add) : add)))
			if (exp <= 52)
			{
				if (mant & 0x0010000000000000)
					ft_sumnumstr(ret, add);
				mant <<= 1;
			}
		free(add);
	}
	ret[0] = '.';
	return (ret);
}

static void			init(char **a, char **b, char **c)
{
	*a = NULL;
	*b = NULL;
	*c = NULL;
}

char				*ft_dtoa(double dnum, int prec)
{
	t_binary_d	mem;
	char		*int_ret;
	char		*dec;
	char		*tmp;

	if (dnum != dnum)
		return (ft_strdup("nan"));
	init(&int_ret, &dec, &tmp);
	mem = ft_getmemdouble(dnum);
	if (mem.exp == 1024)
		return (mem.sign ? ft_strdup("-inf") : ft_strdup("inf"));
	if (!(int_ret = getint(mem.mant, mem.exp)) ||
			!(dec = getdec(mem.mant, mem.exp, prec)) ||
			!(tmp = ft_doprec_fstr(ft_strjoin(int_ret, dec), prec)))
		return (NULL);
	free(dec);
	dec = tmp;
	if (ft_strlen(int_ret) > 1)
		while (*dec == '0')
			dec++;
	free(int_ret);
	if (!(int_ret = (mem.sign == 1 ? ft_strjoin("-", dec) : ft_strdup(dec))))
		return (NULL);
	free(tmp);
	return (int_ret);
}
