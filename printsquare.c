/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:23:07 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/20 18:06:26 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (arr[i].shape & sbshort(cursor, -(pos.x - arr[i].pos->x), -(pos.y - \
		arr[i].pos->y)))
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
}
