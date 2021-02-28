/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:54:22 by enena             #+#    #+#             */
/*   Updated: 2021/02/28 11:20:49 by enena            ###   ########.fr       */
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

typedef enum	e_side_player
{
	west,
	east,
	north,
	south
}				t_side_player;

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
	void			*get;
	t_set_setting	set;
	t_destroyer		destroy;
	void			*backlink;
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
	t_map_list	*tmp;
}				t_map;

typedef struct	s_player
{
	float		x;
	float		y;
	float		dirx;
	float		diry;
}				t_player;

/*
** Main structure
*/
typedef struct	s_game_master
{
	t_settings		*sl;
	t_map			*map;
	t_player		*pl;
	t_bool			save;
	void			*mlx;
	void			*win;
	t_image			*frame;
}				t_game_master;

#endif
