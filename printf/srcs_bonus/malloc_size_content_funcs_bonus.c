/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_size_content_funcs_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:25:25 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 18:06:03 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_malloc_l_content(t_list_prf *curr, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		curr->p_cnt = malloc(sizeof(double));
	if (conv == 'c')
		curr->p_cnt = malloc(sizeof(char));
	if (conv == 's')
		curr->p_cnt = malloc(sizeof(char *));
	if (conv == 'p')
		curr->p_cnt = malloc(sizeof(void *));
	if ((conv == 'd') || (conv == 'i'))
		curr->p_cnt = malloc(sizeof(long int));
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		curr->p_cnt = malloc(sizeof(t_ulint));
	if (conv == 'n')
		curr->p_cnt = malloc(sizeof(long int *));
}

void	ft_malloc_ll_content(t_list_prf *curr, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		curr->p_cnt = malloc(sizeof(double));
	if (conv == 'c')
		curr->p_cnt = malloc(sizeof(char));
	if (conv == 's')
		curr->p_cnt = malloc(sizeof(char *));
	if (conv == 'p')
		curr->p_cnt = malloc(sizeof(void *));
	if ((conv == 'd') || (conv == 'i'))
		curr->p_cnt = malloc(sizeof(int));
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		curr->p_cnt = malloc(sizeof(t_uint));
	if (conv == 'n')
		curr->p_cnt = malloc(sizeof(int *));
}

void	ft_malloc_h_content(t_list_prf *curr, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		curr->p_cnt = malloc(sizeof(double));
	if (conv == 'c')
		curr->p_cnt = malloc(sizeof(char));
	if (conv == 's')
		curr->p_cnt = malloc(sizeof(char *));
	if (conv == 'p')
		curr->p_cnt = malloc(sizeof(void *));
	if ((conv == 'd') || (conv == 'i'))
		curr->p_cnt = malloc(sizeof(int));
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		curr->p_cnt = malloc(sizeof(t_uint));
	if (conv == 'n')
		curr->p_cnt = malloc(sizeof(int *));
}

void	ft_malloc_hh_content(t_list_prf *curr, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		curr->p_cnt = malloc(sizeof(double));
	if (conv == 'c')
		curr->p_cnt = malloc(sizeof(char));
	if (conv == 's')
		curr->p_cnt = malloc(sizeof(char *));
	if (conv == 'p')
		curr->p_cnt = malloc(sizeof(void *));
	if ((conv == 'd') || (conv == 'i'))
		curr->p_cnt = malloc(sizeof(int));
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		curr->p_cnt = malloc(sizeof(t_uint));
	if (conv == 'n')
		curr->p_cnt = malloc(sizeof(int *));
}

void	ft_malloc_z_content(t_list_prf *curr, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		curr->p_cnt = malloc(sizeof(double));
	if (conv == 'c')
		curr->p_cnt = malloc(sizeof(char));
	if (conv == 's')
		curr->p_cnt = malloc(sizeof(char *));
	if (conv == 'p')
		curr->p_cnt = malloc(sizeof(void *));
	if ((conv == 'd') || (conv == 'i'))
		curr->p_cnt = malloc(sizeof(int));
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		curr->p_cnt = malloc(sizeof(t_uint));
	if (conv == 'n')
		curr->p_cnt = malloc(sizeof(int *));
}
