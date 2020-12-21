/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:01:21 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 01:41:05 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/*
** My own LIBFT
*/
# include "libft/libft.h"

/*
** Standart work with indefinite number of arguments
** Uses:	type: va_list, macros: va_start, va_arg, va_end
*/
# include <stdarg.h>
# ifdef BONUS
#  include "hdrs/srcs_bonus.h"
# else
#  include "hdrs/srcs_mandatory.h"
# endif

/*
** Prototype ft_printf
*/
int				ft_printf(const char *format, ...);

/*
** ENGINE {engine folder} 
*/
/*
** general_func
*/
t_bool			ft_preparser(t_list_prf **l_spec, char const *fs);
t_bool			ft_lstprf_parser_fill(t_list_prf *curr, va_list *ap,
															char const *fs);
t_bool			ft_lstprf_in_tab(t_list_prf **head, char ***s_tab,
															const char *fs);
char			*ft_connect(char ***s_tab);

/*
** ft_error_escape
*/
int				ft_error_escape(t_list_prf **, char ***);

/*
** list_work_utils
*/
void			ft_lstprf_addback(t_list_prf **, t_list_prf *);
t_list_prf		*ft_lstprf_last(t_list_prf *);
size_t			ft_lstprf_size(t_list_prf *);

/*
** list_free_utils
*/
void			ft_lstprf_del(t_list_prf *);
void			ft_lstprf_del_first(t_list_prf **);
void			ft_lstprf_clear(t_list_prf **);

/*
** tab_utils
*/
char			**ft_init_null_tab(char ***, size_t);
void			ft_free_tab(char ***);

/*
** find_handler
*/
t_func_do		ft_conv_find_func(char const supp_conv);

/*
** find_width_prec
*/
t_bool			ft_check_width_prec(t_list_prf *curr, va_list *ap, char *s);
t_bool			ft_last_num(int **find, char *s, t_bool is_width);

/*
** funcdo_width_prec
*/
char			*ft_make_min_width(t_list_prf *lp, char *pr);
void			ft_take_prec_str(t_list_prf *lp, char *pr);
char			*ft_take_prec_int(t_list_prf *lp, char *pr);

#endif
