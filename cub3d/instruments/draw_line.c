/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:30:56 by enena             #+#    #+#             */
/*   Updated: 2021/01/26 22:31:00 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	calculate_gradient(t_point p1, t_point p2, t_bool *isxmain)
{
	float	dx;
	float	dy;

	dx = p2.x - p1.x;
    dy = p2.y - p1.y;
	*isxmain = (fabs(dx) > fabs(dy)) ? TRUE : FALSE;
	return (*isxmain ? (dy / dx) : (dx / dy));
}

static float	fpart(float f)
{
	return (f - trunc(f));
}

static float	rfpart(float f)
{
	return (1 - fpart(f));
}

static float	ipart(float f)
{
	return (trunc(f));
}

static void		do_alias_x(t_image *data, t_line line, float grad)
{
	float xend = round(line.p1.x);
    float yend = line.p1.y + grad*(xend - line.p1.x);
    float xgap = rfpart(line.p1.x + 0.5);
    int xpxl1 = xend;
    int ypxl1 = ipart(yend);
    add_pxl_to_img(data, get_pxl(get_point(xpxl1, ypxl1), get_rule(rn, line.data), rfpart(yend)*xgap);
    add_pxl_to_img(data, get_pxl(get_point(xpxl1, ypxl1+1)), fpart(yend)*xgap);
    float intery = yend + grad;
    xend = round(line.p2.x);
    yend = line.p2.y + grad*(xend - line.p2.x);
    xgap = fpart(line.p2.x+0.5);
    int xpxl2 = xend;
    int ypxl2 = ipart(yend);
    add_pxl_to_img(data, get_pxl(get_point(xpxl2, ypxl2)), rfpart(yend) * xgap);
    add_pxl_to_img(data, get_pxl(get_point(xpxl2, ypxl2 + 1)), fpart(yend) * xgap);
    int x;
    for(x=xpxl1+1; x < xpxl2; x++) 
	{
      add_pxl_to_img(data, get_pxl(get_point(x, ipart(intery))), rfpart(intery));
      add_pxl_to_img(data, get_pxl(get_point(x, ipart(intery) + 1)), fpart(intery));
      intery += grad;
    }
}

static void		do_alias_y(t_image *data, t_line line, float grad)
{
    float yend = round(line.p1.y);
    float xend = line.p1.x + grad*(yend - line.p1.y);
    float ygap = rfpart(line.p1.y + 0.5);
    int ypxl1 = yend;
    int xpxl1 = ipart(xend);
    add_pxl_to_img(data, get_pxl(get_point(xpxl1, ypxl1)), rfpart(xend)*ygap);
    add_pxl_to_img(data, get_pxl(get_point(xpxl1 + 1, ypxl1)), fpart(xend)*ygap);
    float interx = xend + grad;
    yend = round(line.p2.y);
    xend = line.p2.x + grad*(yend - line.p2.y);
    ygap = fpart(line.p2.y+0.5);
    int ypxl2 = yend;
    int xpxl2 = ipart(xend);
    add_pxl_to_img(data, get_pxl(get_point(xpxl2, ypxl2)), rfpart(xend) * ygap);
    add_pxl_to_img(data, get_pxl(get_point(xpxl2 + 1, ypxl2)), fpart(xend) * ygap);
    int y;
    for(y=ypxl1+1; y < ypxl2; y++) 
	{
      add_pxl_to_img(data, get_pxl(get_point(ipart(interx), y)), rfpart(interx));
      add_pxl_to_img(data, get_pxl(get_point(ipart(interx) + 1, y)), fpart(interx));
      interx += grad;
	}
}

/*
** Implementation Wu line algorithm
*/
t_bool			draw_line(t_image *data, t_line line)
{
	float   grad;
	t_bool	isxmain;

    grad = calculate_gradient(line.p1, line.p2, &isxmain);
	if ((isxmain && (line.p1.x > line.p2.x)) ||
		(!isxmain && (line.p1.y > line.p2.y)))
		if (!(ft_swap(&line.p1, &line.p2, sizeof(t_point))))
			return (FALSE);
	if (isxmain)
		do_alias_x(data, line, grad);
	else 
		do_alias_y(data, line, grad);
	return (TRUE);
}