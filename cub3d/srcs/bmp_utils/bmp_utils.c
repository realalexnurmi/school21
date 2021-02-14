/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:16:17 by enena             #+#    #+#             */
/*   Updated: 2021/02/10 18:16:19 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_utils.h"

static void		set_bmp_info_from_image(t_bitmapinfo *info, t_image *data)
{
	info->size = BMP_SIZEOFINFO;
	info->width = data->width;
	info->height = -data->height;
	info->planes = BMP_PLANES;
	info->bitcount = BMP_BITPERPIXEL;
	info->compression = BMP_COMPRESSION;
	info->sizeimage = BMP_SIZEIMAGE;
	info->xpelspermeter = BMP_XPELSPERMETER;
	info->ypelspermeter = BMP_YPELSPERMETER;
	info->clrused = BMP_CLRUSED;
	info->clrimportant = BMP_CLRIMPORTANT;
}

static void		set_bmp_data_from_image(t_bmpfile *bmp, t_image *data)
{
	ft_memcpy(bmp->fileheader.type, BMP_IDENTIFIER, sizeof(BMP_IDENTIFIER));
	bmp->fileheader.size = data->width * data->height * BMP_BYTEPERPIXEL +
		BMP_SIZEOFHEADER;
	bmp->fileheader.reserved = 0;
	bmp->fileheader.offset = BMP_SIZEOFHEADER;
	set_bmp_info_from_image(&bmp->info, data);
	bmp->data = data->addr;
}

t_bool		save_image_as_bmp(t_image *data, const char *name)
{
	int			fd;
	char		*bmp_file_name;
	t_bmpfile	bmp_data;

	if (!(bmp_file_name = ft_strjoin(name, BMP_EXTN)))
		return (error_handler(err_alloc_fail));
	if ((fd = open(bmp_file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
		return (error_handler(err_open_write_fail));
	bmp_file_name = ft_sec_free(bmp_file_name);
	set_bmp_data_from_image(&bmp_data, data);
	if (!(ft_write_bmp(fd, &bmp_data)))
		return (error_handler(err_write_fail));
	if (close(fd) < 0)
		return (error_handler(err_close_fail));
	return (true);
}
