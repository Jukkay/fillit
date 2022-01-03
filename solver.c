/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 14:41:37 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

static int	collisioncheck(int i, t_tetris *alltetri, int boxwidth)
{
	int	l;
	int	a;
	int	b;

	l = -1;
	if ((alltetri[i].pos->x + alltetri[i].size->x > boxwidth))
		return (0);
	if ((alltetri[i].pos->y + alltetri[i].size->y > boxwidth))
		return (0);
	while (alltetri[++l].shape > 0)
	{
		if (l == i && l++ >= 0)
			continue ;
		else if (alltetri[l].pos->x >= 0)
		{
			a = (alltetri[i].pos->x - alltetri[l].pos->x);
			b = (alltetri[i].pos->y - alltetri[l].pos->y);
			if (ft_abs(a) < 4 && ft_abs(b) < 4)
			{
				if (alltetri[i].shape & sbshort(alltetri[l].shape, a, b))
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
		if (collisioncheck(l, alltetri, boxwidth))
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
