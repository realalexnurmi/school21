/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:01:21 by enena             #+#    #+#             */
/*   Updated: 2020/12/18 22:44:07 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include "engine.h"
# ifdef BONUS
#  include "handlers_defines.h"
#  include "srcs_body.h"
# else
#  include "handlers_defines_bonus.h"
#  include "srcs_body_bonus.h"
# endif

/*
** Prototype ft_printf
*/

int ft_printf(const char *, ...);

#endif
