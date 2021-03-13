/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 07:49:25 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:28:48 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruments.h"

static void		took_wall_texture(t_game_master *gm, t_ray *ray, t_wall *wall)
{
	int	choose_text;

	if (ray->side == n_s)
		choose_text = (ray->y > gm->pl->y) ? so_texture : no_texture;
	else
		choose_text = (ray->x > gm->pl->x) ? ea_texture : we_texture;
	wall->texture = gm->sl->link[choose_text].get;
	if (ray->side == n_s)
		wall->x = gm->pl->x + ray->perp_dist * ray->dir_x;
	else
		wall->x = gm->pl->y + ray->perp_dist * ray->dir_y;
	wall->x -= floor(wall->x);
	wall->x = 1.0 - wall->x;
	wall->texture_x = (int)(wall->x * (float)wall->texture->width);
	if ((ray->side == e_w && ray->dir_x > 0) ||
		(ray->side == n_s && ray->dir_y < 0))
		wall->texture_x = wall->texture->width - wall->texture_x - 1;
	wall->step_y = (float)wall->texture->height / (float)wall->height;
	wall->y = (ray->wall_top - ray->horizon + wall->height / 2) * wall->step_y;
}

static float	perpendicular_distance(t_ray *ray, t_player *player)
{
	float	pd;

	if (ray->side == n_s)
		pd = (ray->y - player->y + (1 - ray->step_y) / 2) / ray->dir_y;
	else
		pd = (ray->x - player->x + (1 - ray->step_x) / 2) / ray->dir_x;
	return (pd);
}

void			calculate_wall(t_ray *ray, t_game_master *gm)
{
	if (ray->hit)
	{
		ray->perp_dist = perpendicular_distance(ray, gm->pl);
		gm->render->wall->height = gm->render->cubed / ray->perp_dist;
		gm->render->wall->height *= (ray->perp_dist != 0);
		calculate_edge(&ray->wall_top, &ray->wall_bot,
			gm->frame->height, gm->render->wall->height);
	}
	else
	{
		gm->render->wall->height = 0;
		ray->wall_top = ray->horizon;
		ray->wall_bot = ray->horizon;
	}
	took_wall_texture(gm, ray, gm->render->wall);
}
