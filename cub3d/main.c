/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:43:39 by enena             #+#    #+#             */
/*   Updated: 2021/01/26 20:42:43 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"

int main(int argc, char **argv)
{

	if (pass_err(init_gm(&gm, &argc, &argv)))
		escape_deal();
	return (1);
}
