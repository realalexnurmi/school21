/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_handlers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 07:10:51 by enena             #+#    #+#             */
/*   Updated: 2020/12/26 04:17:25 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_isspecialfloat(char *pr, t_uchar *outflag)
{
	if (!(ft_strncmp(pr, "nan", 3)))
	{
		*outflag &= ~(ZERO_FLAG | SPCE_FLAG | PLUS_FLAG);
		return (TRUE);
	}
	if (!(ft_strncmp(pr, "inf", 3)))
	{
		*outflag &= ~ZERO_FLAG;
		return (TRUE);
	}
	if (!(ft_strncmp(pr, "-inf", 4)))
	{
		*outflag &= ~ZERO_FLAG;
		return (TRUE);
	}
	return (TRUE);
}

void	ft_movedot(char *b, char *place)
{
	char *tmp;

	tmp = ft_strchr(b, '.');
	while (tmp != place)
	{
		ft_swap_ch(tmp, (place > tmp ? tmp + 1 : tmp - 1));
		tmp = ft_strchr(b, '.');
	}
}

char	*ft_findexp(double fnum, int prec, int *intexp)
{
	char	*snum;
	char	*tmp;
	char	*dot;

	if (!(snum = ft_dtoa(fnum, 333)))
		return (NULL);
	tmp = snum;
	dot = NULL;
	while (*tmp == '0' || *tmp == '.')
		tmp++;
	if (!dot)
		dot = ft_strchr(snum, '.');
	*intexp = dot - tmp - (dot > tmp);
	free(snum);
	snum = ft_dtoa(fnum, prec - *intexp);
	if (!snum)
		return (NULL);
	return (snum);
}

char	*ft_writeexp(char *in, int exp, int prec)
{
	char	*a;
	char	*ret;

	prec++;
	if (exp == -335)
		exp = 0;
	if (exp < 0)
	{
		if (!(a = ft_strjoin(in, exp > -10 ? "e-0" : "e-")))
			return (NULL);
		exp = -exp;
	}
	else if (!(a = ft_strjoin(in, exp < 10 ? "e+0" : "e+")))
		return (NULL);
	free(in);
	if (!(in = ft_lltoa_base(exp, 10)) ||
			!(ret = ft_strjoin(a, in)))
		return (NULL);
	free(in);
	free(a);
	return (ret);
}

char	*ft_get_e(double fnum, int prec)
{
	char		*p1;
	char		*p2;
	char		*ret;
	int			intexp;
	t_bool		sign;

	sign = take_g_sign(&fnum);
	if (!(p1 = ft_findexp(fnum, prec, &intexp)))
		return (NULL);
	ft_movedot(p1, ft_strchr(p1, '.') - intexp);
	if (!(ret = ft_strdup(ft_strchr(p1, '.') - 1)))
		return (NULL);
	free(p1);
	ret = ft_doprec_fstr(ret, prec);
	if (!(p2 = ft_writeexp(ret, intexp, prec)))
		return (NULL);
	ret = sign ? ft_strjoin("-", p2) : ft_strdup(p2);
	free(p2);
	return (ret);
}
