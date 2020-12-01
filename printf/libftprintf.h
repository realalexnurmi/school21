/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:24:22 by enena             #+#    #+#             */
/*   Updated: 2020/12/01 20:18:29 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define CONV_COUNT 1
# define NONE_FLAG 0b00000000
# define ZERO_FLAG 0b00000001
# define MNUS_FLAG 0b00000010
# define HASH_FLAG 0b00000100
# define SPCE_FLAG 0b00001000
# define PLUS_FLAG 0b00010000
# define UPCS_FLAG 0b00100000
# include <stdarg.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>

typedef _Bool			t_bool;
typedef unsigned char	t_stbl;

typedef void	(*t_func_do)(void **);

typedef enum	e_msize
{
	NONE,
	L,
	LL,
	H,
	HH,
	Z
}				t_msize;

typedef struct	s_list_prf
{
	struct s_list_prf	*next;
	size_t				begin;
	size_t				end;
	t_func_do			func;
	size_t				*width;
	size_t				*prec;
	t_stbl				flag;
	t_msize				size;
	void				*to_content;
	char				*print;
}				t_list_prf;

int				ft_printf(const char *format, ...);

const char		g_conv_array[CONV_COUNT] = {
	's'};
const t_func_do	g_func_array[CONV_COUNT] = {
	ft_s_func};

#endif
