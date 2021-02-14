/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 08:27:13 by enena             #+#    #+#             */
/*   Updated: 2021/02/12 09:06:16 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool write_bitmapinfo(int fd, t_bitmapinfo *info)
{
	if (write(fd, &info->size, sizeof(info->size)) < 0)
		return (false);
	if (write(fd, &info->width, sizeof(info->width)) < 0)
		return (false);
	if (write(fd, &info->height, sizeof(info->height)) < 0)
		return (false);
	if (write(fd, &info->planes, sizeof(info->planes)) < 0)
		return (false);
	if (write(fd, &info->bitcount, sizeof(info->bitcount)) < 0)
		return (false);
	if (write(fd, &info->compression, sizeof(info->compression)) < 0)
		return (false);
	if (write(fd, &info->sizeimage, sizeof(info->sizeimage)) < 0)
		return (false);
	if (write(fd, &info->xpelspermeter, sizeof(info->xpelspermeter)) < 0)
		return (false);
	if (write(fd, &info->ypelspermeter, sizeof(info->ypelspermeter)) < 0)
		return (false);
	if (write(fd, &info->clrused, sizeof(info->clrused)) < 0)
		return (false);
	if (write(fd, &info->clrimportant, sizeof(info->clrimportant)) < 0)
		return (false);
	return (true);
}

static t_bool	write_bitmapfileheader(int fd, t_bitmapfileheader *hdr)
{
	if (write(fd, &hdr->type, sizeof(hdr->type)) < 0)
		return (false);
	if (write(fd, &hdr->size, sizeof(hdr->size)) < 0)
		return (false);
	if (write(fd, &hdr->reserved, sizeof(hdr->reserved)) < 0)
		return (false);
	if (write(fd, &hdr->offset, sizeof(hdr->offset)) < 0)
		return (false);
	return (true);
}

/*
** Writing BMP in binary file;
** So far uses BITMAPINFOHEADER v.3
** and assumes that the {t_bmpfile}[bitmap] is well organized without checking
** Places pixel data just behind the header structure
*/

t_bool			ft_write_bmp(int fd, t_bmpfile *bitmap)
{
	if (fd > 0)
	{
		if (!(write_bitmapfileheader(fd, &bitmap->fileheader)))
			return (false);
		if (!(write_bitmapinfo(fd, &bitmap->info)))
			return (false);
		if (write(fd, bitmap->data,
			bitmap->fileheader.size - bitmap->fileheader.offset) < 0)
			return (false);
		return (true);
	}
	return (false);
}
