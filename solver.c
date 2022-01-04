/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/04 13:39:51 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//int g_checkcount;

static int	collisioncheck(int i, t_tetris *alltetri)
{
	int	l;
	int	a;
	int	b;

	l = -1;
	while (alltetri[++l].shape > 0)
	{
		if (l == i && l++ >= 0)
			continue ;
		else if (alltetri[l].pos->x >= 0)
		{
			a = (alltetri[i].pos->x - alltetri[l].pos->x);
			b = (alltetri[i].pos->y - alltetri[l].pos->y);
			if(((a < 0 && alltetri[i].size->x > -a)
				|| (a >= 0&& alltetri[l].size->x > a))
				&& ((b < 0 && alltetri[i].size->y > -b)
				|| (b >= 0 && alltetri[l].size->y > b)))
			{
				if(alltetri[i].shape & offsetshort(alltetri[l].shape, a, b))
					return (0);
			}
		}
	}
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
	int	l;

	l = 0;
	while (alltetri[l].shape > 0 && alltetri[l].pos->x >= 0)
		l++;
	if (alltetri[l].shape == 0)
		return (1);
	while (move_tpos(l, alltetri, boxwidth) == 1)
	{
		if (collisioncheck(l, alltetri))
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
	//ft_putnbr(g_checkcount);
	//ft_putendl(" collisions");
	return (minsize);
}
