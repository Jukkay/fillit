/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:23:07 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/03 17:39:44 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freearr(t_tetris *arr, int tetriscount)
{
	int	i;

	i = 0;
	while (i < tetriscount)
	{
		free(arr[i].size);
		free(arr[i].pos);
		i++;
	}
}

char	ft_check_char(t_tetris *arr, int size, int tetriscount, int a)
{
	t_point			pos;
	unsigned short	cursor;
	int				i;

	cursor = 32768;
	i = 0;
	pos.x = (a + size) % size;
	pos.y = a / size;
	while (i < tetriscount)
	{
		if (arr[i].shape & offsetshort(cursor, -(pos.x - arr[i].pos->x), \
		-(pos.y - arr[i].pos->y)))
			return ('A' + i);
		i++;
	}
	return ('.');
}

void	ft_print_square(t_tetris *arr, int size, int tetriscount)
{
	int		i;
	int		square;

	i = 0;
	square = size * size;
	while (i < square)
	{
		ft_putchar(ft_check_char(arr, size, tetriscount, i));
		i++;
		if ((i + size) % size == 0)
			ft_putchar('\n');
	}
	freearr(arr, tetriscount);
}
