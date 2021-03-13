/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:49:43 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:24:59 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruments.h"

static size_t	median(t_sprite ***arr, size_t low, size_t middle, size_t high)
{
	if ((*arr)[low]->dist_pow2 > (*arr)[middle]->dist_pow2)
		ft_swap_p((void **)&((*arr)[low]), (void **)&((*arr)[middle]));
	if ((*arr)[low]->dist_pow2 > (*arr)[high]->dist_pow2)
		ft_swap_p((void **)&((*arr)[low]), (void **)&((*arr)[middle]));
	if ((*arr)[high]->dist_pow2 < (*arr)[middle]->dist_pow2)
		ft_swap_p((void **)&((*arr)[low]), (void **)&((*arr)[middle]));
	return (middle);
}

static size_t	partition(t_sprite ***arr, size_t low, size_t high)
{
	size_t		pivot;
	float		value;

	pivot = median(arr, low, (low + high) / 2, high);
	value = (*arr)[pivot]->dist_pow2;
	while (low <= high)
	{
		while ((*arr)[low]->dist_pow2 > value)
			++low;
		while ((*arr)[high]->dist_pow2 < value)
			--high;
		if (low >= high)
			break ;
		if (low < high)
		{
			ft_swap_p((void **)&((*arr)[low]), (void **)&((*arr)[high]));
			++low;
			--high;
		}
	}
	return (high);
}

static void		insert_sort(t_sprite ***arr, size_t low, size_t high)
{
	size_t		i;
	ssize_t		j;
	t_sprite	*swap;

	i = low + 1;
	while (i <= high)
	{
		swap = (*arr)[i];
		j = i - 1;
		while ((j >= 0) && ((*arr)[j]->dist_pow2 < swap->dist_pow2))
		{
			(*arr)[j + 1] = (*arr)[j];
			--j;
		}
		(*arr)[j + 1] = swap;
		++i;
	}
}

void			improve_quick_sort(t_sprite ***arr, size_t low, size_t high)
{
	const size_t	insert_size = 10;
	size_t			pivot;
	size_t			size;

	size = high - low + 1;
	if (size > 1)
	{
		if (size <= insert_size)
			insert_sort(arr, low, high);
		else
		{
			pivot = partition(arr, low, high);
			improve_quick_sort(arr, low, pivot);
			improve_quick_sort(arr, pivot + 1, high);
		}
	}
}
