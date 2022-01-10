/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:49:05 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/10 12:02:57 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//puts the tetrimino at the given index into the map
void	printtomap(int i, t_tetris *alltetri, t_uint16 *map)
{
	t_uint16	mask;

	mask = 61440;
	map[alltetri[i].pos->y] |= ((alltetri[i].shape & mask)
			>> alltetri[i].pos->x);
	mask = 3840;
	map[alltetri[i].pos->y + 1] |= ((alltetri[i].shape & mask)
			<< 4 >> alltetri[i].pos->x);
	mask = 240;
	map[alltetri[i].pos->y + 2] |= ((alltetri[i].shape & mask)
			<< 8 >> alltetri[i].pos->x);
	mask = 15;
	map[alltetri[i].pos->y + 3] |= ((alltetri[i].shape & mask)
			<< 12 >> alltetri[i].pos->x);
}

//removes the tetrimino at the given index from the map
void	rmofmap(int i, t_tetris *alltetri, t_uint16 *map)
{
	t_uint16	mask;

	mask = 61440;
	map[alltetri[i].pos->y] ^= ((alltetri[i].shape & mask)
			>> alltetri[i].pos->x);
	mask = 3840;
	map[alltetri[i].pos->y + 1] ^= ((alltetri[i].shape & mask)
			<< 4 >> alltetri[i].pos->x);
	mask = 240;
	map[alltetri[i].pos->y + 2] ^= ((alltetri[i].shape & mask)
			<< 8 >> alltetri[i].pos->x);
	mask = 15;
	map[alltetri[i].pos->y + 3] ^= ((alltetri[i].shape & mask)
			<< 12 >> alltetri[i].pos->x);
}

//checks the tetrimino at the given index to the map
int	collisionmap(int i, t_tetris *alltetri, t_uint16 *map)
{
	t_uint16	mask;

	mask = 61440;
	if (map[alltetri[i].pos->y]
		& ((alltetri[i].shape & mask) >> alltetri[i].pos->x))
		return (0);
	mask = 3840;
	if (map[alltetri[i].pos->y + 1]
		& ((alltetri[i].shape & mask) << 4 >> alltetri[i].pos->x))
		return (0);
	mask = 240;
	if (map[alltetri[i].pos->y + 2]
		& ((alltetri[i].shape & mask) << 8 >> alltetri[i].pos->x))
		return (0);
	mask = 15;
	if (map[alltetri[i].pos->y + 3]
		& ((alltetri[i].shape & mask) << 12 >> alltetri[i].pos->x))
		return (0);
	return (1);
}
