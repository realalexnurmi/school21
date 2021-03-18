/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:34:35 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 06:44:34 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

t_bool			set_resolution(void *plink, char **tab)
{
	t_setting_link	*link;
	long long int	width;
	long long int	height;

	link = plink;
	if (ft_tab_size(tab) != link->cnt_fields)
		return (setting_error(link->idntf, err_wrong_count_fields));
	if (!(ft_isanum(tab[1])) || !(ft_isanum(tab[2])))
		return (setting_error(link->idntf, err_wrong_information));
	if (tab[1][0] == '-' || tab[2][0] == '-')
		return (setting_error(link->idntf, err_wrong_information));
	width = ft_atoll(tab[1]);
	height = ft_atoll(tab[2]);
	if (!(link->get = malloc(sizeof(t_resolution))))
		return (error_handler(err_alloc_fail));
	((t_resolution *)link->get)->width = (width > INT_MAX || width == -1) ?
		INT_MAX : width;
	((t_resolution *)link->get)->height = (height > INT_MAX || height == -1) ?
		INT_MAX : height;
	link->destroy = &free_resolution;
	return (link->is_set = true);
}

t_bool			set_texture(void *plink, char **tab)
{
	t_setting_link	*link;
	t_bool			is_png;
	void			*img_ptr;
	int				width;
	int				height;

	link = plink;
	if (ft_tab_size(tab) != link->cnt_fields)
		return (setting_error(link->idntf, err_wrong_count_fields));
	is_png = false;
	if (!((ft_check_extention(tab[1], TEXTURE_XPM_EXTN)) ||
		(is_png = ft_check_extention(tab[1], TEXTURE_PNG_EXTN))))
		return (setting_error(link->idntf, err_bad_extention_texture));
	if (!(img_ptr = (is_png ?
		mlx_png_file_to_image(((t_game_master *)link->backlink)->mlx,
			tab[1], &width, &height) :
		mlx_xpm_file_to_image(((t_game_master *)link->backlink)->mlx,
			tab[1], &width, &height))))
		return (setting_error(link->idntf, err_convert_texture));
	if (!(link->get = get_image(img_ptr, width, height)))
		return (error_handler(err_alloc_fail));
	link->destroy = &free_image;
	return (link->is_set = true);
}

t_bool			set_color(void *plink, char **tab)
{
	t_setting_link	*link;
	char			**rgbtab;
	t_uint			rgb[3];

	link = plink;
	if (ft_tab_size(tab) != link->cnt_fields)
		return (setting_error(link->idntf, err_wrong_count_fields));
	if (ft_charcount(tab[1], ',') != 2)
		return (setting_error(link->idntf, err_wrong_count_comma_color));
	if (!(rgbtab = ft_split(tab[1], ',')))
		return (error_handler(err_alloc_fail));
	if (!(ft_isanum(rgbtab[0])) || !(ft_isanum(rgbtab[1])) ||
		!(ft_isanum(rgbtab[2])))
		return (setting_error(link->idntf, err_wrong_information));
	if (((rgb[0] = ft_atoi(rgbtab[0])) > 255 || (rgb[0] < 0)) ||
		((rgb[1] = ft_atoi(rgbtab[1])) > 255 || (rgb[1] < 0)) ||
		((rgb[2] = ft_atoi(rgbtab[2])) > 255 || (rgb[2] < 0)))
		return (setting_error(link->idntf, err_wrong_information));
	rgbtab = ft_free_tab(rgbtab);
	if (!(link->get = malloc(sizeof(t_uint))))
		return (error_handler(err_alloc_fail));
	*((t_uint *)link->get) = ((rgb[0] << 16) & 0x00FF0000) |
	((rgb[1] << 8) & 0x0000FF00) | (rgb[2] & 0x000000FF);
	link->destroy = &free_color;
	return (link->is_set = true);
}
