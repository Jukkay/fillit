/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:40:45 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/06 21:52:13 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	move_tpos(int index, t_tetris *alltetri, int boxwidth)
{
	if (alltetri[index].pos->x == -1)
	{
		ft_setpoint(alltetri[index].pos, 0, 0);
		if (alltetri[index].pos->x + alltetri[index].size->x <= boxwidth \
		&& alltetri[index].pos->y + alltetri[index].size->y <= boxwidth)
			return (1);
		return (0);
	}
	if (alltetri[index].pos->x + alltetri[index].size->x < boxwidth)
		alltetri[index].pos->x++;
	else if (alltetri[index].pos->y + alltetri[index].size->y < boxwidth)
		ft_setpoint(alltetri[index].pos, 0, alltetri[index].pos->y + 1);
	else
	{
		ft_setpoint(alltetri[index].pos, -1, -1);
		return (0);
	}
	return (1);
}

static int	solver(t_tetris *alltetri, int boxwidth, unsigned short *map)
{
	int				i;

	i = 0;
	while (alltetri[i].shape > 0 && alltetri[i].pos->x >= 0)
		i++;
	if (alltetri[i].shape == 0)
		return (1);
	while (move_tpos(i, alltetri, boxwidth) == 1)
	{
		if (collisioncheck(i, alltetri, map))
		{
			printtomap(i, alltetri, map);
			if (solver(alltetri, boxwidth, map) == 0)
			{
				remofmap(i, alltetri, map);
				continue ;
			}
			return (1);
		}
	}
	ft_setpoint(alltetri[i].pos, -1, -1);
	return (0);
}

int	solve_tetris(t_tetris *tetri)
{
	int	minsize;
	int	i;
	unsigned short	tmap[16];
	unsigned short	*map;

	map = tmap;
	i = 0;
	while ((tetri)[i].shape > 0)
		i++;
	minsize = 1;
	while (minsize * minsize < i * 4)
		minsize++;
	i = -1;
	while(++i < 16)
		map[i] = (unsigned short)0;
	while (solver(tetri, minsize, map) == 0)
	{
		i = -1;
		while(++i < 16)
			map[i] = (unsigned short)0;
		minsize++;
	}
	return (minsize);
}