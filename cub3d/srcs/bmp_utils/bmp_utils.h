/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:31:21 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 21:31:10 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_UTILS_H
# define BMP_UTILS_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "error_handling.h"
# include <fcntl.h>
# define BMP_EXTN			".bmp"
# define BMP_IDENTIFIER		"BM"
# define BMP_BYTEPERPIXEL	4
# define BMP_SIZEOFHEADER	54
# define BMP_SIZEOFINFO		40
# define BMP_RESERVED		0
# define BMP_PLANES			1
# define BMP_BITPERPIXEL	32
# define BMP_COMPRESSION	0
# define BMP_SIZEIMAGE		0
# define BMP_XPELSPERMETER	0
# define BMP_YPELSPERMETER	0
# define BMP_CLRUSED		0
# define BMP_CLRIMPORTANT	0
# define BMP_MAX_DIMENSION	10000

t_bool	save_image_as_bmp(t_image *data, const char *name);

#endif
