/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:54:22 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 05:56:24 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "libft.h"
# include "defines.h"

/*
** Struct for data image
*/
typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		bytepp;
	int		len_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct	s_resolution
{
	int	width;
	int	height;
}				t_resolution;

typedef enum	e_side
{
	west,
	north,
	east,
	south
}				t_side;

typedef enum	e_type_wall
{
	e_w,
	n_s
}				t_type_wall;

enum			e_setting_name
{
	resolution,
	no_texture,
	so_texture,
	we_texture,
	ea_texture,
	s_texture,
	floor_color,
	ceil_color
};

typedef t_bool	(*t_set_setting)(void *, char **);
typedef void	(*t_destroyer)(void *);

typedef struct	s_setting_link
{
	t_bool			is_set;
	char			idntf[SIZE_IDNTF_SETTING];
	size_t			cnt_fields;
	void			*backlink;
	t_set_setting	set;
	t_destroyer		destroy;
	void			*get;
}				t_setting_link;

typedef struct	s_settings
{
	t_bool			is_all_set;
	t_setting_link	*link;
}				t_settings;

typedef struct	s_map_list
{
	size_t		bgn_ind;
	size_t		end_ind;
	size_t		len;
	size_t		listsize;
	t_list		*list;
}				t_map_list;

typedef struct	s_map
{
	t_bool		player_set;
	char		**yx;
	ssize_t		mx_y;
	ssize_t		mx_x;
	ssize_t		count_sprite;
	t_map_list	*tmp;
}				t_map;

typedef struct	s_player
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
	float		pln_x;
	float		pln_y;
	float		strafe_l_x;
	float		strafe_l_y;
}				t_player;

enum			e_key_name
{
	w,
	a,
	s,
	d,
	left,
	right,
	esc,
	space
};

enum			e_table_cs_tn
{
	cosine,
	sinus,
	tangent,
	cotangent
};

typedef enum	e_dir_rotate
{
	counter_clock,
	clockwise
}				t_dir_rotate;

typedef enum	e_key_status
{
	released,
	pressed
}				t_key_status;

typedef int		(*t_key_react)(void *);

typedef struct	s_key
{
	int				code;
	t_key_status	status;
	t_key_react		react;
}				t_key;

typedef struct	s_keys
{
	t_bool	any_is_pressed;
	t_key	*key;
}				t_keys;

typedef struct	s_ray
{
	ssize_t		ind;
	int			x;
	int			y;
	float		dir_x;
	float		dir_y;
	float		sclrcam;
	float		delt_x;
	float		delt_y;
	float		dist_x;
	float		dist_y;
	float		perp_dist;
	int			step_x;
	int			step_y;
	int			last_top;
	int			wall_top;
	int			horizon;
	int			wall_bot;
	int			last_bot;
	t_bool		hit;
	t_type_wall	side;
}				t_ray;

typedef struct	s_wall
{
	t_image		*texture;
	int			height;
	int			texture_x;
	int			texture_y;
	float		x;
	float		y;
	float		step_y;
}				t_wall;

typedef struct	s_sprite
{
	float		x;
	float		y;
	int			height;
	int			width;
	int			cntr;
	int			x_draw_begin;
	int			x_draw_end;
	int			y_draw_begin;
	int			y_draw_end;
	float		perp_dist;
	float		dist_pow2;
}				t_sprite;

typedef struct	s_render
{
	t_ray		*rays;
	t_wall		*wall;
	t_sprite	**sprites;
	t_bool		need;
	float		cubed;
}				t_render;
/*
** Main structure
*/
typedef struct	s_game_master
{
	void			*mlx;
	void			*win;
	char			*name;
	t_settings		*sl;
	t_map			*map;
	t_player		*pl;
	t_bool			save;
	t_keys			*keys;
	t_image			*frame;
	float			**table;
	t_render		*render;
}				t_game_master;

#endif
