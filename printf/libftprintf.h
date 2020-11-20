/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:24:22 by enena             #+#    #+#             */
/*   Updated: 2020/11/20 20:20:00 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

//# include <string.h>

typedef unsigned char	t_stbl;

typedef char	(*t_func_do)(void *, size_t, size_t);

typedef struct	s_list_func
{
	struct s_func_list	*next;
	char				conv;
	t_func_do			func;
}				t_list_func;

typedef enum	e_msize
{
	none,
	l,
	ll,
	h,
	hh,
	z
}				t_msize;

typedef struct	s_list_prf
{
	struct s_list	*next;
	size_t			begin;
	size_t			end;
	t_func_do		func;
	t_stbl			flag;
	size_t			width;
	size_t			prec;
	t_msize			size;
	void			*content;
	char			*print;
}				t_list_prf;

int				ft_printf(const char *format, ...);

#endif
