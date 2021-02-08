 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:54:22 by enena             #+#    #+#             */
/*   Updated: 2021/01/26 20:54:23 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_convex_polygon
{
}				t_convex_polygon;

/*
** Struct for data image
*/
typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len_line;
	int		endian;
}				t_image;

/*
** Struct for coordinate
*/
typedef struct	s_point
{
	float	x;
	float	y;
}				t_point;

/*
** Struct for line (Yep, i'm still normal, not crazy!)
*/
typedef struct	s_line
{
	t_point p1;
	t_point p2;
	void	*data;
	
}				t_line;

/*
** Struct for pixel
*/
typedef struct	s_pxl
{
	t_uint	x;
	t_uint	y;
	t_rule	rule;
}				t_pxl;

typedef struct	s_resolution
{
	int	width;
	int height;
}				t_resolution;

typedef struct	s_game_master
{
	t_resolution	res;
	void			*mlx;
	void			*win;
	t_image			*frame;
	t_image			*next_frame;
}				t_game_master;

typedef void	(*t_set_setting)(void *, char **);

enum			e_setting_name
{
	RESOLUTION,
	NO_TEXTURE,
	SO_TEXTURE,
	WE_TEXTURE,
	EA_TEXTURE,
	S_TEXTURE,
	FLOOR_COLOR,
	CEIL_COLOR
};

typedef struct	s_setting_link
{
	char			idntfr[3];
	t_bool			set;
	void			*param;
	t_set_settnig	setter;
}				t_setting_link;

typedef struct	s_settings
{
	t_bool			all_set;
	t_setting_link	*setting;
}				t_settings;

tydef struct	s_object_master
{
	
}
#endif