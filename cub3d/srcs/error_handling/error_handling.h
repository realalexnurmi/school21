/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:49:00 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 06:05:30 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "mlx.h"

typedef enum	e_error
{
	err_wrong_count_fields = 1,
	err_wrong_information,
	err_bad_extention_texture,
	err_convert_texture,
	err_wrong_count_comma_color,
	setting_error_end,
	err_alloc_fail,
	err_missing_conf,
	err_bad_extention_conf,
	err_open_read_fail,
	err_open_write_fail,
	err_read_fail,
	err_write_fail,
	err_close_fail,
	err_incorect_name_setting,
	err_missing_setting,
	err_empty_line_in_map,
	err_first_line_map,
	err_middle_line_map,
	err_last_line_map,
	err_too_much_player,
	err_player_not_found,
	err_map_too_small,
	err_map_only_fill,
	err_map_not_closed,
	err_missing_map,
	err_too_much_arguments,
	err_unknown_flag,
	err_new_image_fail,
	err_window_not_open,
	err_too_big_save_bmp,
	warning,
	wrn_resolution_width_increased,
	wrn_resolution_height_increased,
	wrn_resolution_width_reduced,
	wrn_resolution_height_reduced,
	all
}				t_error;

static int		g_error_callback;

static char		*g_err_wrn_strings[all] = {
	" wrong count information fields",
	" in fields has wrong information",
	" texture has wrong extention. Only .xpm and .png allowed",
	" texture not converted. Maybe it is broken",
	" detect wrong count comma in set color",
	"SETTINGS ERRORS END",
	"Allocate error",
	"Configuration missing",
	"Bad extension configuration. Need \".cub\"",
	"Error open for read",
	"Error open for write",
	"Error while read",
	"Error while write",
	"Error closing?",
	"Incorrect name setting (too long indetifier)",
	"Not all required setting setted",
	"Empty line in map",
	"Bad first line map or broken name setting",
	"Find trash into map",
	"Incorrect last line map",
	"Find doubling player character",
	"Player not found",
	"Map impossible small. Abort!",
	"Map has only fill character ~ empty map",
	"Map has not closed space",
	"Map not found?!",
	"Too much arguments. Abort.",
	"Unknown flag(s). Abort.",
	"Trouble with new image.",
	"Trouble with new window.",
	"Resolution for save BMP too big!",
	"WARNING!!!",
	"Your resolution setting incorrect. Width increased to minimal value",
	"Your resolution setting incorrect. Height increased to minimal value",
	"Your resolution setting incorrect. Width reduced to screen size",
	"Your resolution setting incorrect. Height reduced to screen size",
	"ALL? How you see it? Review? My code is the best"
};

t_bool	error_handler(t_error err);
t_bool	setting_error(char idntf[SIZE_IDNTF_SETTING], t_error err);
void	escape_deal(t_game_master *gm);

void	free_resolution(void *plink);
void	free_image(void *plink);
void	free_color(void *plink);
void	free_matrix(char **mtrx, ssize_t count_row);
#endif
