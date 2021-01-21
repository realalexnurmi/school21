/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_handlers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 07:10:51 by enena             #+#    #+#             */
/*   Updated: 2021/01/21 05:55:05 by enena            ###   ########.fr       */
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
	return (FALSE);
}

int		ft_movedot(char *str, char *place)
{
	char	*tmp;
	int		ofst;
	int		dir;

	tmp = ft_strchr(str, '.');
	ofst = 0;
	dir = (place > tmp ? 1 : -1);
	while (tmp != place)
	{
		ft_swap_ch(tmp, tmp + dir);
		tmp += dir;
		ofst -= dir;
	}
	return (ofst);
}

char	*ft_writeexp(char *in, int exp, t_bool ish)
{
	char	*a;
	char	*ret;

	if (ish)
		in[ft_strlen(in) - 1] = '\0';
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

char	*ft_prepare_scientific(char *s_dbl, int prec, t_bool issign,
														t_bool ish)
{
	char	*tmp_place;
	int		exp;
	int		finddot;

	tmp_place = s_dbl;
	finddot = 0;
	while (*tmp_place == '0' || *tmp_place == '.')
	{
		finddot = finddot || (*tmp_place == '.');
		tmp_place++;
	}
	exp = ft_movedot(s_dbl, tmp_place + !finddot);
	if (!(tmp_place = ft_doprec_fstr(s_dbl, prec)))
		return (NULL);
	s_dbl = ft_strchr(tmp_place, (prec == 0 ? '\0' : '.')) - 1;
	if (*s_dbl == '0')
	{
		exp += (prec == 0 || ft_movedot(s_dbl, s_dbl));
		s_dbl[ft_strlen(s_dbl) - 1] = '\0';
		s_dbl--;
	}
	if (!(s_dbl = ft_strdup(s_dbl - issign)))
		return (NULL);
	free(tmp_place);
	return (ft_writeexp(s_dbl, exp, ish));
}

char	*ft_convert_in_scientific(double dbl, int prec, t_uchar *flg)
{
	char		*s_dbl;
	char		*tmp;
	t_bool		issign;
	t_bool		ish;
	char		sign;

	ish = !!(*flg & HASH_FLAG);
	if (!(s_dbl = ft_dtoa(dbl, 324 + prec)))
		return (NULL);
	if (!!ft_isspecialfloat(s_dbl, flg))
		return (s_dbl);
	if (!!(issign = !(ft_isdigit(*s_dbl))))
		ft_takesign(&sign, s_dbl);
	if (!(tmp = ((dbl == 0.0 || dbl == -0.0) ? ft_strdup(s_dbl) :
					ft_strjoin("0", s_dbl))))
		return (NULL);
	free(s_dbl);
	s_dbl = NULL;
	if (!(s_dbl = ((dbl == 0.0 || dbl == -0.0) ?
					ft_writeexp(ft_doprec_fstr(tmp, prec), 0, ish) :
					ft_prepare_scientific(tmp, prec, issign, ish))))
		return (NULL);
	if (issign)
		ft_addsign(sign, s_dbl);
	return (s_dbl);
}
