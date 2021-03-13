/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_part_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:47:07 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:19:58 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruments.h"

t_bool	get_table(float ***table)
{
	const float rad = ANGLE_DEGREE_ROTATE * M_PI / 180;

	if (!(*table = malloc(sizeof(float *) * 2)))
		return (error_handler(err_alloc_fail));
	if (!((*table)[clockwise] = malloc(sizeof(float) * 4)))
		return (error_handler(err_alloc_fail));
	if (!((*table)[counter_clock] = malloc(sizeof(float) * 4)))
		return (error_handler(err_alloc_fail));
	(*table)[clockwise][sinus] = sin(rad);
	(*table)[clockwise][cosine] = cos(rad);
	(*table)[clockwise][tangent] = tan(rad);
	(*table)[clockwise][cotangent] = 1 / (tan(rad));
	(*table)[counter_clock][sinus] = sin(-rad);
	(*table)[counter_clock][cosine] = cos(-rad);
	(*table)[counter_clock][tangent] = tan(-rad);
	(*table)[counter_clock][cotangent] = 1 / (tan(-rad));
	return (true);
}

void	rotate(float *x, float *y, float *table)
{
	float	oldx;

	oldx = *x;
	*x = *x * table[cosine] - *y * table[sinus];
	*y = oldx * table[sinus] + *y * table[cosine];
}

void	rotate_ninety(float *x, float *y, t_dir_rotate dir)
{
	float	oldx;

	oldx = *x;
	if (dir)
	{
		*x = -1 * *y;
		*y = oldx;
	}
	else
	{
		*x = *y;
		*y = -1 * oldx;
	}
}
