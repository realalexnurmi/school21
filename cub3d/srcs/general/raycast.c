/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 06:04:57 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:21:23 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	cast_ray(t_ray *ray, t_player *player)
{
	ray->dir_x = player->dir_x + player->pln_x * ray->sclrcam;
	ray->dir_y = player->dir_y + player->pln_y * ray->sclrcam;
	ray->x = (int)player->x - (player->x < 0.0);
	ray->y = (int)player->y - (player->y < 0.0);
	ray->delt_x = fabs(1.0 / ray->dir_x);
	ray->delt_y = fabs(1.0 / ray->dir_y);
	ray->step_x = (ray->dir_x < 0) ? -1 : 1;
	ray->step_y = (ray->dir_y < 0) ? -1 : 1;
	ray->dist_x = ray->step_x * (ray->x - player->x +
		(ray->step_x == 1)) * ray->delt_x;
	ray->dist_y = ray->step_y * (ray->y - player->y +
		(ray->step_y == 1)) * ray->delt_y;
}

static void	hitting_ray(t_ray *ray, t_game_master *gm)
{
	ray->hit = false;
	while (!(ray->hit))
	{
		if (ray->dist_y < ray->dist_x && ray->dist_y < MAX_RENDER_DISTANCE)
		{
			ray->dist_y += ray->delt_y;
			ray->y += ray->step_y;
			ray->side = n_s;
		}
		else if (ray->dist_x < MAX_RENDER_DISTANCE)
		{
			ray->dist_x += ray->delt_x;
			ray->x += ray->step_x;
			ray->side = e_w;
		}
		else
			break ;
		if (ray->x >= 0 && ray->y >= 0 &&
			ray->x <= gm->map->mx_x && ray->y <= gm->map->mx_y)
		{
			if (ft_strchr(VALID_WALL_MAP_CHAR, gm->map->yx[ray->y][ray->x]))
				ray->hit = true;
		}
	}
}

void		render_frame(t_game_master *gm)
{
	ssize_t	x;
	ssize_t	i;

	x = -1;
	while (++x < gm->frame->width)
	{
		cast_ray(&gm->render->rays[x], gm->pl);
		hitting_ray(&gm->render->rays[x], gm);
		calculate_wall(&gm->render->rays[x], gm);
		draw_ceil(&gm->render->rays[x], gm->sl->link[ceil_color].get,
			gm->frame);
		draw_wall(&gm->render->rays[x], gm->render->wall, gm->frame);
		draw_floor(&gm->render->rays[x], gm->sl->link[floor_color].get,
			gm->frame);
		gm->render->rays[x].last_top = gm->render->rays[x].wall_top;
		gm->render->rays[x].last_bot = gm->render->rays[x].wall_bot;
	}
	calculate_sprites(&(gm->render->sprites), gm->pl, gm->map->count_sprite,
		gm->frame);
	i = -1;
	while (++i < gm->map->count_sprite)
		draw_sprite(gm->render->sprites[i], gm->render->rays,
			gm->sl->link[s_texture].get, gm->frame);
	gm->render->need = false;
}
