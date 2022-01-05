/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/05 17:09:44 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//int g_checkcount;

unsigned short	movemask(int k, unsigned short mask, t_tetris *alltetri)
{
	int	i;
	int	a;
	int	b;

	i = -1;
	mask = offsetshort(mask, 1, 0);
	if (alltetri[k].pos->x == 0)
		mask = 0;
	while (alltetri[++i].shape > 0)
	{
		if (i == k)
			continue ;
		if ((alltetri[k].pos->x == 0 && alltetri[i].pos->x != -1)
			|| (alltetri[i].pos->x >= 0
				&& alltetri[i].pos->x <= alltetri[k].pos->x + 4
				&& alltetri[i].pos->x + alltetri[i].size->x
				>= alltetri[k].pos->x + 4))
		{	
			a = (alltetri[k].pos->x - alltetri[i].pos->x);
			b = (alltetri[k].pos->y - alltetri[i].pos->y);
			mask = mask | offsetshort(alltetri[i].shape, a, b);
		}
	}
	return (mask);
}

static int	collisioncheck(int i, t_tetris *alltetri, unsigned short mask)
{
	if (alltetri[i].shape & mask)
		return (0);
	return (1);
}

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

static int	solver(t_tetris *alltetri, int boxwidth)
{
	int				l;
	unsigned short	mask;

	mask = 0;
	l = 0;
	while (alltetri[l].shape > 0 && alltetri[l].pos->x >= 0)
		l++;
	if (alltetri[l].shape == 0)
		return (1);
	while (move_tpos(l, alltetri, boxwidth) == 1)
	{
		mask = movemask(l, mask, alltetri);
		if (collisioncheck(l, alltetri, mask))
		{
			if (solver(alltetri, boxwidth) == 0)
			{
				continue ;
			}
			return (1);
		}
	}
	ft_setpoint(alltetri[l].pos, -1, -1);
	return (0);
}

int	solve_tetris(t_tetris *tetri)
{
	int	minsize;
	int	i;

	i = 0;
	while ((tetri)[i].shape > 0)
	{
		i++;
	}
	minsize = 1;
	while (minsize * minsize < i * 4)
		minsize++;
	while (solver(tetri, minsize) == 0)
	{
		minsize++;
	}
	return (minsize);
}
