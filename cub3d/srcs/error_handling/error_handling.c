/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 07:29:06 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:25:37 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

t_bool	error_handler(t_error err)
{
	if (err > setting_error_end)
	{
		if (err < warning)
			ft_putendl_fd("Error", 1);
		else
			ft_putendl_fd("Warning", 1);
	}
	ft_putendl_fd(g_err_wrn_strings[err - 1], 1);
	g_error_callback = err;
	return (err >= warning);
}

t_bool	setting_error(char idntf[SIZE_IDNTF_SETTING], t_error err)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd("In setting ", 1);
	ft_putstr_fd(idntf, 1);
	return (error_handler(err));
}

void	escape_deal(t_game_master *gm)
{
	ssize_t i;

	i = -1;
	if (gm->sl)
	{
		while (++i < CNT_SETTING)
			if (gm->sl->link[i].is_set)
				gm->sl->link[i].destroy(&gm->sl->link[i]);
		gm->sl->link = ft_sec_free(gm->sl->link);
	}
	gm->sl = ft_sec_free(gm->sl);
	if (gm->map && gm->map->yx)
		free_matrix(gm->map->yx, gm->map->mx_y);
	gm->map = ft_sec_free(gm->map);
	gm->pl = ft_sec_free(gm->pl);
	if (gm->win)
		mlx_destroy_window(gm->mlx, gm->win);
	exit(g_error_callback);
}
