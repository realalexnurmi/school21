/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs_mandatory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:29:02 by enena             #+#    #+#             */
/*   Updated: 2020/12/21 21:41:50 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_MANDATORY_H
# define SRCS_MANDATORY_H

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
** HANDLERS {srcs_mandatory folder}
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

/*
** BODY PART {srcs_mandatory folder}
*/
/*
** ft_lstprf_new_mandatory
*/
t_list_prf		*ft_lstprf_new(size_t begin, size_t end, t_func_do func);

/*
** apply_handlers_mandatory
*/
t_bool			ft_lstprf_apply_func_to_content(t_list_prf *curr);

/*
** check_mod_special_case_mandatory
*/
void			ft_check_modify(t_list_prf *curr, char *s);
void			ft_check_special_case(t_list_prf *curr, char *s);

/*
** malloc_claim_content_mandatory
*/
t_bool			ft_malloc_content(t_list_prf *curr, char conv);
t_bool			ft_claim_content(t_list_prf *curr, va_list *ap, char conv);

/*
** funcdo_convert_utils_mandatory
*/
long long int	ft_take_signed(t_list_prf *curr);
t_ullint		ft_take_unsigned(t_list_prf *curr);

#endif
