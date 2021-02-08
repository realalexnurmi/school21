/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:49:00 by enena             #+#    #+#             */
/*   Updated: 2021/02/07 13:49:04 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H

typedef enum	e_retval
{
	ALL_RIGHT,
	ERR_ALLOC_FAIL,
	ERR_MISSING_CONF,
	ERR_BAD_EXTENTION_CONF,
	ERR_OPEN_FAIL,
	ERR_READ_FAIL,
	ERR_INCORECT_NAME_SETTING
}				t_retval;
#endif
