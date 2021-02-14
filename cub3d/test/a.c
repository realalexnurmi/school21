/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:02:24 by enena             #+#    #+#             */
/*   Updated: 2021/02/10 16:02:34 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "cub3d.h"

int					main(void)
{
	t_image		image;
	//const char	*intoname = "map";
	char		*filename;
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	//win = mlx_new_window(mlx, 2000, 2000, "SUCK");
	if (!(image.img = mlx_png_file_to_image(mlx, "best2.png", &image.width, &image.height)))
		printf("SUCK\n");
	else
	{
	//image.img = mlx_new_image(mlx, 1, 1, 0x0000AEFF);
	image.addr = mlx_get_data_addr(image.img, &image.bpp,
		&image.len_line, &image.endian);
	// printf("lenline:%d\n", image.len_line);
	// printf("H:%d\n", image.height);
	// printf("W:%d\n", image.width);
	// put_pxl_to_img(&image, get_pxl(get_point(0.0, 0.0)));
	// put_pxl_to_img(&image, get_pxl(get_point(1.0, 0.0)));
	// put_pxl_to_img(&image, get_pxl(get_point(0.0, 1.0)));
	// put_pxl_to_img(&image, get_pxl(get_point(1.0, 1.0)));
	//mlx_put_image_to_window(mlx, win, image.img, 0, 0);
	//image.width = 1; image.height = 1;
	filename = ft_strdup(BASENAME);
	add_name_image_resolution(&filename, &image);
	save_image_as_bmp(&image, filename);
	printf("done\n");
	//mlx_loop(mlx);
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
	}
	return (0);
}
