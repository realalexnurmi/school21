/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_convert_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:08:03 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:29:58 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static t_bool	add_row_in_matrix_from_node_list(t_map *map, const ssize_t row)
{
	const char	*fill = VALID_FILL_MAP_CHAR;
	t_list		*cur;
	char		*tmp;
	size_t		len;
	size_t		i;

	cur = map->tmp->list;
	if (!(map->yx[row] = malloc(sizeof(char) * map->tmp->len)))
		return (error_handler(err_alloc_fail));
	tmp = &cur->content[map->tmp->bgn_ind];
	i = 0;
	len = map->tmp->len;
	while (*tmp && len--)
		map->yx[row][i++] = *tmp++;
	ft_memset(&map->yx[row][i], fill[0], map->tmp->len - i);
	map->tmp->list = map->tmp->list->next;
	ft_lstdelone(cur, &free);
	return (true);
}

static t_bool	is_closed(t_map *map, const ssize_t y, const ssize_t x)
{
	if (((x != 0) &&
		((ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y - 1][x - 1])) ||
		(ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y][x - 1])) ||
		(ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y + 1][x - 1])))) ||
		(ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y - 1][x])) ||
		(ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y + 1][x])) ||
		((x != map->mx_x) &&
		((ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y - 1][x + 1])) ||
		(ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y][x + 1])) ||
		(ft_strchr(VALID_FILL_MAP_CHAR, map->yx[y + 1][x + 1])))))
		return (error_handler(err_map_not_closed));
	return (true);
}

static t_bool	player_init(t_map *map, t_player **pl,
							const ssize_t y, const ssize_t x)
{
	const float		vec_xy[2][4][2] =
	{{{-1.0, 0.0}, {0.0, -1.0}, {1.0, 0.0}, {0.0, 1.0}},
	{{0.0, -1.0}, {1.0, 0.0}, {0.0, 1.0}, {-1.0, 0.0}}};
	t_side			side;

	if (!(*pl = malloc(sizeof(t_player))))
		return (error_handler(err_alloc_fail));
	if (map->yx[y][x] == 'N')
		side = north;
	if (map->yx[y][x] == 'S')
		side = south;
	if (map->yx[y][x] == 'W')
		side = west;
	if (map->yx[y][x] == 'E')
		side = east;
	(*pl)->dir_x = vec_xy[0][side][0];
	(*pl)->dir_y = vec_xy[0][side][1];
	(*pl)->pln_x = vec_xy[1][side][0];
	(*pl)->pln_y = vec_xy[1][side][1];
	(*pl)->strafe_l_x = vec_xy[1][side][0];
	(*pl)->strafe_l_y = vec_xy[1][side][1];
	map->yx[y][x] = MAP_CHAR_UNDER_PLAYER;
	(*pl)->x = (float)x + 0.5;
	(*pl)->y = (float)y + 0.5;
	return (true);
}

static t_bool	check_closed_and_player_init(t_map *map, t_player **pl)
{
	ssize_t	x;
	ssize_t	y;

	y = 0;
	while (++y < map->mx_y)
	{
		x = -1;
		while (++x <= map->mx_x)
		{
			if (ft_strchr(VALID_INSIDE_MAP_CHAR, map->yx[y][x]))
				if (!(is_closed(map, y, x)))
					return (false);
			if (ft_strchr(VALID_PLAYER_MAP_CHAR, map->yx[y][x]))
			{
				if (!(is_closed(map, y, x)))
					return (false);
				if (!(player_init(map, pl, y, x)))
					return (false);
			}
			if (ft_strchr(SPRITE_CHAR, map->yx[y][x]))
				map->count_sprite++;
		}
	}
	return (true);
}

t_bool			convert_map_player_init(t_map *map, t_player **pl)
{
	ssize_t		y;

	if ((map->tmp->listsize <= 2) || (map->tmp->len <= 2))
		return ((map->tmp->listsize == 0) ?
		error_handler(err_map_only_fill) : error_handler(err_map_too_small));
		if (!(map->player_set))
		return (error_handler(err_player_not_found));
	if (!(map->yx = malloc(sizeof(char *) * map->tmp->listsize)))
		return (error_handler(err_alloc_fail));
	map->mx_y = map->tmp->listsize - 1;
	y = -1;
	while (++y <= map->mx_y)
		if (!(add_row_in_matrix_from_node_list(map, y)))
			return (false);
	map->mx_x = map->tmp->len - 1;
	map->tmp = ft_sec_free(map->tmp);
	if (!(check_closed_and_player_init(map, pl)))
		return (false);
	return (true);
}
