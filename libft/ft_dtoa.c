/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:36:10 by enena             #+#    #+#             */
/*   Updated: 2020/12/25 18:58:11 by enena            ###   ########.fr       */
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
	//printf("%s\n", add);
	//printf("%s\n", s_exp);
	if (!(add = ft_pownumstr(add, s_exp)) ||
			!(ret = ft_strdup(add)))
	//printf("%s\n", add);
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

static void			increasenum(char *p, char *e)
{
	t_bool		hasdig;
	char		trans;

	hasdig = FALSE;
	trans = 0;
	while (--e != p + 1)
		if (*e != '0')
			hasdig = TRUE;
	trans = 1;
	if (!hasdig && ft_isodd(*p))
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

static char			*doprec(char *num, int prec)
{
	char		*dot_tmp;
	int			lendec;
	char		*ret;

	dot_tmp = ft_strchr(num, '.');
	lendec = (int)ft_strlen(dot_tmp);
	if (prec >= lendec)
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

char				*ft_dtoa(double dnum, int prec)
{
	t_binary_d	mem;
	char		*int_ret;
	char		*dec;
	char		*tmp;

	if (dnum != dnum)
		return (ft_strdup("nan"));
	mem = ft_getmemdouble(dnum, &int_ret, &dec, &tmp, &tmp);
	if (mem.exp == 1024)
		return (mem.sign ? ft_strdup("-inf") : ft_strdup("inf"));
	int_ret = getint(mem.mant, mem.exp);
	//printf("a%s\n", int_ret);
	dec = getdec(mem.mant, mem.exp, prec);
	//printf("b%s\n", dec);
	tmp = ft_strjoin(int_ret, dec);
	//printf("c%s\n", tmp);
	tmp = doprec(tmp, prec);
	//printf("d%s\n", tmp);
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
