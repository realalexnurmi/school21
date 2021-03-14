/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:02:24 by enena             #+#    #+#             */
/*   Updated: 2021/02/28 15:35:20 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
// #include <fcntl.h>
// #include <unistd.h>
#include <stdio.h>
// #include <stdlib.h>
#include "mlx.h"
// #include "cub3d.h"

int					main(void)
{
	// t_image		image;
	//const char	*intoname = "map";
	// char		*filename;
	// void		*mlx;
	// void		*win;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 2000, 2000, "SUCK");
	// if (!(image.img = mlx_png_file_to_image(mlx, "best2.png", &image.width, &image.height)))
	// 	printf("SUCK\n");
	// else
	// {
	// image.img = mlx_new_image(mlx, 100, 100, 0x0000AEFF);
	int h, w;
	// h = 1;
	// w = 1;
	printf("WTF?\n");
	mlx_get_screen_size(&h, &w);
	printf("h:%d, w:%d\n", h, w);
	// image.addr = mlx_get_data_addr(image.img, &image.bpp,
	// 	&image.len_line, &image.endian);
	// printf("lenline:%d\n", image.len_line);
	// printf("H:%d\n", image.height);
	// printf("W:%d\n", image.width);
	// put_pxl_to_img(&image, get_pxl(get_point(0.0, 0.0)));
	// put_pxl_to_img(&image, get_pxl(get_point(1.0, 0.0)));
	// put_pxl_to_img(&image, get_pxl(get_point(0.0, 1.0)));
	// // put_pxl_to_img(&image, get_pxl(get_point(1.0, 1.0)));
	// mlx_put_image_to_window(mlx, win, image.img, 0, 0);
	// //image.width = 1; image.height = 1;
	// // filename = ft_strdup(BASENAME);
	// // add_name_image_resolution(&filename, &image);
	// // save_image_as_bmp(&image, filename);
	// // printf("done\n");
	// mlx_loop(mlx);
	// t_a data;
	// int	size, fd;
	// size = 1;
	// data.head.a.data = 0x4d42;
	// data.head.b.data = 1;
	// fd = open("1.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	// printf("%zu\n", sizeof(data));
	// printf("%hhx\n", data.byte[0]);
	// printf("%hhx\n", data.byte[1]);
	// printf("%hhx\n", data.byte[2]);
	// printf("%hhx\n", data.byte[3]);
	// write(fd, &data.byte, 6);
	// close(fd);
	// }
	gm.frame = malloc(sizeof(t_image));
	gm.frame->img = mlx_png_file_to_image(gm.mlx, "./test/batman.png", &gm.frame->width, &gm.frame->height);
	gm.win = mlx_new_window(gm.mlx, gm.frame->width, gm.frame->height, "batman");
	mlx_put_image_to_window(gm.mlx, gm.win, gm.frame->img, 0, 0);
	mlx_loop(gm.mlx);
	return (0);
}
