/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:24:22 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 23:20:39 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/*
** Definition of count handle specifier
*/
# define CONV_COUNT 9

/*
** Binary form definition flag
*/
# define NONE_FLAG 0b00000000
# define ZERO_FLAG 0b00000001
# define MNUS_FLAG 0b00000010
# define UPCS_FLAG 0b00000100

/*
** My own LIBFT
*/
# include "libft.h"

/*
** Standart work with indefinite number of arguments
** Uses:	type: va_list, macros: va_start, va_arg, va_end
*/
# include <stdarg.h>

/*
** Generic function pointer type conversion specifier handlers
*/
typedef t_bool	(*t_func_do)(void *);

/*
** Type node of list for parsing
** next: pointer to next node
** begin: index in [format] in %
** end: index in [format] in specifier conversion
** func: pointer to handler specifier function
** width/prec: pointer to same params
** flag: unsigned char for flag {0-}
** p_cnt: pointer to copy correspond argument
** print: pointer to rezult string
*/
typedef struct	s_list_prf
{
	struct s_list_prf	*next;
	size_t				begin;
	size_t				end;
	t_func_do			func;
	int					*width;
	int					*prec;
	t_uchar				flag;
	void				*p_cnt;
	char				*print;
}				t_list_prf;

/*
** ft_printf
*/
int				ft_printf(const char *format, ...);

/*
** 1)ENGINE PART {engine_srcs folder}
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
int				ft_error_escape(t_list_prf **list, char ***tab);

/*
** list_work_utils
*/
void			ft_lstprf_addback(t_list_prf **lst, t_list_prf *new);
t_list_prf		*ft_lstprf_last(t_list_prf *lst);
size_t			ft_lstprf_size(t_list_prf *lst);

/*
** list_free_utils
*/
void			ft_lstprf_del(t_list_prf *curr_del);
void			ft_lstprf_del_first(t_list_prf **head_list);
void			ft_lstprf_clear(t_list_prf **head_list);

/*
** tab_utils
*/
char			**ft_init_null_tab(char ***tab, size_t size);
void			ft_free_tab(char ***tab);

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

/*
** 2) BODY PART {srcs folder}
*/
/*
** ft_lstprf_new
*/
t_list_prf		*ft_lstprf_new(size_t begin, size_t end, t_func_do func);

/*
** apply_handlers
*/
t_bool			ft_lstprf_apply_func_to_content(t_list_prf *curr);

/*
** check_mod_special_case
*/
void			ft_check_modify(t_list_prf *curr, char *s);
void			ft_check_special_case(t_list_prf *curr, char *s);

/*
** malloc_claim_content
*/
t_bool			ft_malloc_content(t_list_prf *curr, char conv);
t_bool			ft_claim_content(t_list_prf *curr, va_list *ap, char conv);

/*
** funcdo_convert_utils
*/
long long int	ft_take_signed(t_list_prf *curr);
t_ullint		ft_take_unsigned(t_list_prf *curr);

/*
** 3) HANDLERS {srcs folder}
*/
/*
** handle_cs_prc_func
*/
t_bool			ft_c_func(void *node);
t_bool			ft_s_func(void *node);
t_bool			ft_prc_func(void *node);

/*
** handle_diuxp_func
*/
t_bool			ft_di_func(void *node);
t_bool			ft_u_func(void *node);
t_bool			ft_x_func(void *node);
t_bool			ft_p_func(void *node);

/*
** Global array conversion specifier for find correspond handler
*/
static const char		g_conv_array_printf[CONV_COUNT] = {
	'c',
	'%',
	's',
	'p',
	'd',
	'i',
	'u',
	'x'};

/*
** Global array corresponding handlers for specifier:
** pointer function
*/
static const t_func_do	g_func_array_printf[CONV_COUNT] = {
	ft_c_func,
	ft_prc_func,
	ft_s_func,
	ft_p_func,
	ft_di_func,
	ft_di_func,
	ft_u_func,
	ft_x_func};

#endif
