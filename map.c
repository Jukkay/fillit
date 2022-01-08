/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:49:05 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/08 02:49:36 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printtomap(int i, t_tetris *alltetri, uint16_t *map)
{
	uint16_t		mask;
	int				k;

	mask = 61440;
	k = -1;
	while (++k < alltetri[i].size->y)
	{
		map[alltetri[i].pos->y + k] |= ((alltetri[i].shape & mask)
				<< (4 * k) >> alltetri[i].pos->x);
		mask = mask >> 4;
	}
}

void	remofmap(int i, t_tetris *alltetri, uint16_t *map)
{
	uint16_t		mask;
	int				k;

	mask = 61440;
	k = -1;
	while (++k < alltetri[i].size->y)
	{
		map[alltetri[i].pos->y + k] ^= ((alltetri[i].shape & mask)
				<< (4 * k) >> alltetri[i].pos->x);
		mask = mask >> 4;
	}
}

int	collisioncheck(int i, t_tetris *alltetri, uint16_t *map)
{
	uint16_t		mask;
	int				k;

	k = -1;
	mask = 61440;
	while (++k < alltetri[i].size->y)
	{
		if (map[alltetri[i].pos->y + k]
			& ((alltetri[i].shape & mask) << (4 * k) >> alltetri[i].pos->x))
			return (0);
		mask = mask >> 4;
	}
	return (1);
}
