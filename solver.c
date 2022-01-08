/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:40:45 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/08 21:08:52 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	move_tpos(int i, t_tetris *alltetri, int boxwidth, t_uint16 *map)
{
	t_uint16	mask;

	alltetri[i].pos->x++;
		mask = 57344 >> alltetri[i].pos->x;
	while (((map[alltetri[i].pos->y] & mask) ^ mask) == 0)
	{
		if ((alltetri[i].pos->x) + alltetri[i].size->x < boxwidth)
		{
			alltetri[i].pos->x++;
		}
		else if (alltetri[i].pos->y + alltetri[i].size->y < boxwidth)
		{
			ft_setpoint(alltetri[i].pos, 0, alltetri[i].pos->y + 1);
		}		
		else
		{
			ft_setpoint(alltetri[i].pos, -1, -1);
			return (0);
		}
		mask = 57344 >> alltetri[i].pos->x;
	}
	return (1);
}

static int	solver(t_tetris *alltetri, int boxwidth, t_uint16 *map)
{
	int				i;

	i = 0;
	while (alltetri[i].shape > 0 && alltetri[i].pos->x >= 0)
		i++;
	if (alltetri[i].shape == 0)
		return (1);
	ft_setpoint(alltetri[i].pos, -1, 0);
	while (move_tpos(i, alltetri, boxwidth, map) == 1)
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
	return (0);
}

static void	initmap(int boxwidth, t_uint16 *map)
{
	int	i;

	i = -1;
	while (++i < boxwidth)
	{
		map[i] = 65535 >> boxwidth;
	}
	map[i] = 65535;
}

int	solve_tetris(t_tetris *tetri)
{
	int			minsize;
	int			i;
	t_uint16	tmap[16];
	t_uint16	*map;

	map = tmap;
	i = 0;
	while ((tetri)[i].shape > 0)
		i++;
	minsize = 1;
	while (minsize * minsize < i * 4)
		minsize++;
	i = -1;
	initmap(minsize, map);
	while (solver(tetri, minsize, map) == 0)
	{
		minsize++;
		initmap(minsize, map);
	}
	return (minsize);
}
