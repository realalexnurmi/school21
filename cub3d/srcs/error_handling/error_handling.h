/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:49:00 by enena             #+#    #+#             */
/*   Updated: 2021/02/07 13:49:04 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H
# include "libft.h"
# include "defines.h"

typedef enum	e_error
{
	err_alloc_fail = 1,
	err_missing_conf,
	err_bad_extention_conf,
	err_open_read_fail,
	err_open_write_fail,
	err_read_fail,
	err_write_fail,
	err_close_fail,
	err_incorect_name_setting
}				t_error;

t_bool	error_handler(t_error err);
#endif
