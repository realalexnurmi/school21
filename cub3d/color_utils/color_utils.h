/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 03:15:42 by enena             #+#    #+#             */
/*   Updated: 2021/01/31 03:15:45 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTILS_H
# define COLOR_UTILS_H
# include "defines.h"

/*
** ENUM - rules names for definition color
*/
typedef enum				e_rn
{
	WHITE,
	SILVER,
	GRAY,
	BLACK,
	RED,
	MAROON,
	ORANGE,
	YELLOW,
	OLIVE,
	LIME,
	GREEN,
	AQUA,
	TEAL,
	BLUE,
	NAVY,
	FUCHSIA,
	PURPLE,
	SHIT,
	FLOOR,
	CEIL,
	NO,
	SO,
	WE,
	EA
}							t_rn;

/*
** ENUM - rules types for definition color
*/
typedef enum				e_type_rule
{
	BASE,
	SETTED,
	TEXTURE
}							t_type_rule;

/*
** Struct storage information about rule for definition color
*/
typedef struct				s_info_rule
{
	t_type_rule	type;
	void		*info;
}							t_info_rule;

/*
** Struct
*/
typedef struct				s_rule
{
	t_rn	name;
	void	*data;
}							t_rule;

/*
** Color storage structure
*/
typedef struct				s_clr
{
	t_uchar a;
	t_uchar	r;
	t_uchar g;
	t_uchar b;
	float	br;
	float	tr;
}							t_clr;

/*
** Definition type getter-functions
*/
typedef t_clr				(*t_getter_clr)(void *, void *);
/*
** File: color_utils_part_1.c
** Functions for getting ARGB component from raw color data
** and use it when setting storage color struct [t_clr]
*/

t_uchar	get_a(t_uint clr_data);
t_uchar	get_r(t_uint clr_data);
t_uchar	get_g(t_uint clr_data);
t_uchar	get_b(t_uint clr_data);
void	set_clr(t_clr *clr, t_uchar red, t_uchar green, t_uchar blue);
/*
** File: color_utils_part_2.c
** Functions for operating with properties and parameters 
** in storage color struct [t_clr]
*/

void	set_clr_br(t_clr *clr, float br);
void	set_clr_tr(t_clr *clr, float tr);
t_clr	get_clr(t_uint clr_data);
t_clr	get_merge_clr(t_clr clr1, t_clr clr2);
t_uint	get_color_data(t_clr clr);
/*
** File: color_utils_part_4.c
** Functions for global work with obtaining the desired color
*/

t_rule	get_rule(t_rn name, void *data);
t_clr	took_clr(t_rule rule);

/*
** File: color_utils_part_5.c
** Getter-functions colors
*/
t_clr	base_clr(void *info, void *data);
t_clr	setted_clr(void *info, void *data);
t_clr	texture_clr(void *info, void *data);

/*
** Array with name rule and info
*/
static t_info_rule				g_rlbk[COUNT_RULE];

/*
** Global constant array pointer to getter-functions
*/
static const t_getter_clr	g_getclr[COUNT_TYPE_RULE] = {
	base_clr,
	setted_clr,
	texture_clr
};

/*
** Color pallete global constant for definition BASE color
*/
static const t_uint			g_pallete_base_color[COUNT_BASE_COLOR] = {
	0x000000,
	0xC0C0C0,
	0x808080,
	0x000000,
	0xFF0000,
	0x800000,
	0xFFA500,
	0xFFFF00,
	0x808000,
	0x00FF00,
	0x008000,
	0x00FFFF,
	0x008080,
	0x0000FF,
	0x000080,
	0xFF00FF,
	0x800080,
	0x7B5804
}

#endif
