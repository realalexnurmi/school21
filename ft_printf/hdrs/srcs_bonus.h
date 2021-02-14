/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:40:04 by enena             #+#    #+#             */
/*   Updated: 2021/02/12 05:21:31 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_BONUS_H
# define SRCS_BONUS_H

/*
** Definition of count handle specifier
*/
# define CONV_COUNT 13

/*
** Binary form definition flag
*/
# define NONE_FLAG 0b00000000
# define ZERO_FLAG 0b00000001
# define MNUS_FLAG 0b00000010
# define HASH_FLAG 0b00000100
# define SPCE_FLAG 0b00001000
# define PLUS_FLAG 0b00010000
# define UPCS_FLAG 0b00100000

/*
** Generic function pointer type conversion specifier handlers
*/
typedef t_bool	(*t_func_do)(void *);

/*
** ENUM type for size modifier
*/
typedef enum	e_msize
{
	none,
	l,
	ll,
	h,
	hh,
	z
}				t_msize;

/*
** Type node of list for parsing
** next: pointer to next node
** ofst: print index offset from index [begin] [format] {work n conv}
** begin: index in [format] in %
** end: index in [format] in specifier conversion
** func: pointer to handler specifier function
** width/prec: pointer to same params {(num) or * and .(num) or .*}
** flag: unsigned char for flag {0-# +}
** size: field save one of modifier size {l, ll, h, hh, z}
** p_cnt: pointer to copy correspond argument
** print: pointer to rezult string
*/
typedef struct	s_list_prf
{
	struct s_list_prf	*next;
	long long int		ofst;
	size_t				begin;
	size_t				end;
	t_func_do			func;
	int					*width;
	int					*prec;
	t_uchar				flag;
	t_msize				size;
	void				*p_cnt;
	size_t				len;
	char				*print;
}				t_list_prf;

/*
** HANDLERS {srcs_bonus folder}
*/
/*
** handle_cs_prc_func_bonus
*/
t_bool			ft_c_func(void *node);
t_bool			ft_s_func(void *node);
t_bool			ft_prc_func(void *node);

/*
** handle_diuxp_func_bonus
*/
t_bool			ft_di_func(void *node);
t_bool			ft_u_func(void *node);
t_bool			ft_x_func(void *node);
t_bool			ft_p_func(void *node);

/*
** handle_nofge_func_bonus
*/
t_bool			ft_n_func(void *node);
t_bool			ft_o_func(void *node);
t_bool			ft_f_func(void *node);
t_bool			ft_g_func(void *node);
t_bool			ft_e_func(void *node);

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
	'o',
	'x',
	'n',
	'f',
	'e',
	'g'};

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
	ft_o_func,
	ft_x_func,
	ft_n_func,
	ft_f_func,
	ft_e_func,
	ft_g_func};

/*
** BODY PART {srcs_bonus folder}
*/
/*
** ft_lstprf_new_bonus
*/
t_list_prf		*ft_lstprf_new(size_t begin, size_t end, t_func_do func);

/*
** apply_handlers_bonus
*/
t_bool			ft_lstprf_apply_func_to_content(t_list_prf *curr);

/*
** check_mod_special_case_bonus
*/
void			ft_check_modify(t_list_prf *curr, char *s);
void			ft_check_special_case(t_list_prf *curr, char *s);
void			ft_check_size(t_msize *size, char *s);

/*
** malloc_claim_content_bonus
*/
t_bool			ft_malloc_content(t_list_prf *curr, char conv);
void			ft_malloc_size_content(t_list_prf *curr, char conv);
t_bool			ft_claim_content(t_list_prf *curr, va_list *ap, char conv);
void			ft_claim_size_content(t_list_prf *curr, va_list *ap, char conv);

/*
** malloc_size_content_funcs_bonus
*/
void			ft_malloc_l_content(t_list_prf *curr, char conv);
void			ft_malloc_ll_content(t_list_prf *curr, char conv);
void			ft_malloc_h_content(t_list_prf *curr, char conv);
void			ft_malloc_hh_content(t_list_prf *curr, char conv);
void			ft_malloc_z_content(t_list_prf *curr, char conv);

/*
** claim_size_content_funcs_bonus
*/
void			ft_claim_l_content(t_list_prf *curr, va_list *ap, char conv);
void			ft_claim_ll_content(t_list_prf *curr, va_list *ap, char conv);
void			ft_claim_h_content(t_list_prf *curr, va_list *ap, char conv);
void			ft_claim_hh_content(t_list_prf *curr, va_list *ap, char conv);
void			ft_claim_z_content(t_list_prf *curr, va_list *ap, char conv);

/*
** funcdo_convert_utils_bonus
*/
long long int	ft_take_signed(t_list_prf *curr);
t_ullint		ft_take_unsigned(t_list_prf *curr);
char			*ft_take_space_plus(t_list_prf *lp, char *pr);
char			*ft_hash(t_list_prf *lp, char *pr);
void			ft_checkxhash(char *pr);

/*
** extention_handlers
*/
t_bool			ft_isspecialfloat(char *pr, t_uchar *outflag);
int				ft_movedot(char *str, char *place);
char			*ft_writeexp(char *in, int exp, t_bool ish);
char			*ft_prepare_scientific(char *s_dbl, int prec, t_bool issign,
																t_bool ish);
char			*ft_convert_in_scientific(double dbl, int prec, t_uchar *flg);

/*
** g_converter
*/
char			*ft_g_convert(char *in, int prec, double src, t_uchar *flg);
int				ft_prec_g_real(int cnt_num, int exp, char *in);

#endif
