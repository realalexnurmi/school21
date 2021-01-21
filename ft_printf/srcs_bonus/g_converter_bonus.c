/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_converter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:26:20 by enena             #+#    #+#             */
/*   Updated: 2021/01/21 06:16:04 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_g_convert(char *in, int prec, double src, t_uchar *flg)
{
	char	*ret;
	char	*tmp;
	t_bool	ish;
	int		exp;
	int		prec_real;

	ish = !!(*flg & HASH_FLAG);
	if (ft_isspecialfloat(in, flg))
		return (in);
	tmp = ft_strchr(in, 'e');
	exp = ft_atoi(tmp + 1);
	prec_real = ft_prec_g_real(prec, exp, tmp);
	if (exp >= prec)
		ret = ft_convert_in_scientific(src, prec_real, flg);
	else if (exp < -4)
		ret = ft_convert_in_scientific(src, prec_real, flg);
	else
	{
		ret = ft_dtoa(src, (ish ? prec : prec_real));
		ret[ft_strlen(ret) - ish] = '\0';
	}
	free(in);
	if (!ret)
		return (NULL);
	return (ret);
}

int		ft_prec_g_real(int cnt_num, int exp, char *in)
{
	int		prec_real;

	prec_real = cnt_num;
	if ((exp < -4) || (exp >= cnt_num))
		prec_real = cnt_num - 1;
	else
		prec_real = cnt_num - exp - 1;
	prec_real = prec_real >= 0 ? prec_real : 0;
	in--;
	while (prec_real && (*in == '0' || *in == '.'))
	{
		prec_real--;
		in--;
	}
	return (prec_real);
}
