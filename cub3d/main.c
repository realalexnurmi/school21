/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:43:39 by enena             #+#    #+#             */
/*   Updated: 2021/01/26 20:42:43 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game_master gm;
	if (init_gm(&gm))
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, W, H, "SUCK");
	t_image	data;
	data.img = mlx_new_image(mlx, W, H);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.len_line, &data.endian);
	// t_image	data2;
	// data2.img = mlx_new_image(mlx, 500, 500);
	// data2.addr = mlx_get_data_addr(data2.img, &data2.bpp, &data2.len_line, &data2.endian);
	set_clr(&data.clr, CL_SHIT);
	int x = 0;
	int y = 0;
	while (x < W)
	{
		while (y < H)
		{
			put_pxl_to_img(&data, get_pxl(get_point(x, y)));
			y++;
		}
		y = 0;
		x++;
	}
	t_line line;
	float xst = 1;
	float yst = 1;
	float size = 100.0;
	line.p1 = get_point(1 * size + xst, 7 * size + yst);
	line.p2 = get_point(12 * size + xst, 11 * size + yst);
	set_clr(&data.clr, CL_BLUE);
	draw_line(&data, line);

	line.p1 = get_point(3 * size + xst, 4 * size + yst);
	line.p2 = get_point(14 * size + xst, 8 * size + yst);
	set_clr(&data.clr, CL_RED);
	draw_line(&data, line);

	line.p1 = get_point(2 * size + xst, 9 * size + yst);
	line.p2 = get_point(10 * size + xst, 3 * size + yst);
	set_clr(&data.clr, CL_GREEN);
	draw_line(&data, line);

	line.p1 = get_point(7 * size + xst, 12 * size + yst);
	line.p2 = get_point(9 * size + xst, 1 * size + yst);
	set_clr(&data.clr, CL_YELLOW);
	draw_line(&data, line);

	line.p1 = get_point(11 * size + xst, 2 * size + yst);
	line.p2 = get_point(17 * size + xst, 8 * size + yst);
	set_clr(&data.clr, CL_ORANGE);
	draw_line(&data, line);

	line.p1 = get_point(11 * size + xst, 5 * size + yst);
	line.p2 = get_point(17 * size + xst, 5 * size + yst);
	set_clr(&data.clr, CL_PURPLE);
	draw_line(&data, line);

	line.p1 = get_point(17 * size + xst, 1 * size + yst);
	line.p2 = get_point(11 * size + xst, 8 * size + yst);
	set_clr(&data.clr, CL_BLACK);
	draw_line(&data, line);
	
	line.p1 = get_point(14 * size + xst, 3 * size + yst);
	line.p2 = get_point(14 * size + xst, 8 * size + yst);
	set_clr(&data.clr, CL_LIME);
	draw_line(&data, line);
	mlx_put_image_to_window(mlx, win, data.img, 0, 0);
	mlx_loop(mlx);
}
