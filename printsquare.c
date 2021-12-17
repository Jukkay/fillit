/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:23:07 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/17 17:59:15 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// print all tetriminos on the list one character at a time starting from top left.
// print the tetrimino that has position at that coordinate. if collision, print the one with # in it.
// print alphabet char according to the tetriminos place on the list.

// convert coordinates to

// int x = 0;
// int y = 0;
// int l = 0;
// while(y < boxwidth)
// {
// 	while((alltetri)[l].shape > 0)
// 	{
// 		a = x - (alltetri)[l].pos->x);
// 		b = y - (alltetri)[l].pos->y);

// 		if(ft_abs(a) < 4 && ft_abs(b) < 4)
// 		{
// 			if(sbshort( 1bitattopleftshort, 0, 0) & sbshort((alltetri)[l].shape, a, b))
// 				return (0);
// 		}
// 		l++;
// 	}
// 		if((x  < boxwidth)
// 			x++;
// 		else if(y < boxwidth)
// 		{
// 			x = 0;
// 			y++;
// 		}

// }

char	ft_check_char(t_tetris *arr, int size, int tetriscount, int a)
{
	t_point			pos;
	char			c;
	unsigned short	cursor;
	unsigned short	diff;
	int				i;

	cursor = 32768;
	i = 0;
	pos.x = a % size;
	pos.y = a / size;
	printf("x %d, y %d\n", pos.x, pos.y);
	while (i < tetriscount)
	{
		diff = (cursor & (arr[i].shape << a));
		printf("x %d, y %d\n", arr[i].pos->x, arr[i].pos->y);
		// printf("diff: %hu\n", diff);
		if (diff != 0) // && arr[i].pos->x <= pos.x && arr[i].pos->x + arr[i].size->x  >= pos.x && arr[i].pos->y == pos.y)
		{
			c = 'A' + i;
			printf("%d matched, returning %c\n", i, c);
			return (c);
		}
		i++;
	}
	c = '.';
	return (c);
}
// 1000
// 0000
// 0000
// 0000

// 1000
// 1000
// 1000
// 1000

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
	}
}