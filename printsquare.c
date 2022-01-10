/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:23:07 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/07 11:26:06 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	ft_check_char(t_tetris *arr, int size, int a)
{
	t_point			pos;
	unsigned short	cursor;
	int				i;

	cursor = 32768;
	i = 0;
	pos.x = (a + size) % size;
	pos.y = a / size;
	while (arr[i].shape > 0)
	{
		if (arr[i].shape & offsetshort(cursor, -(pos.x - arr[i].pos->x), \
		-(pos.y - arr[i].pos->y)))
		{
			// printf("a: %d, %d matched, printing %c\n", a, i, 'A' + i);
			return ('A' + i);
		}
		i++;
	}
	// printf("a: %d, no match, printing %c\n", a, '.');
	return ('.');
}

void	print_square(t_tetris *arr, int size)
{
	int		i;
	int		square;

	i = 0;
	char	c = 'A';
	while (arr[i].shape > 0)
	{
		printf("shape %c, pos x %d, pos y %d\n", c, arr[i].pos->x, arr[i].pos->y);
		i++;
		c++;
	}
	i = 0;
	square = size * size;
	while (i < square)
	{
		ft_check_char(arr, size, i);
		i++;
		if ((i + size) % size == 0)
			ft_putchar('\n');
	}
}
