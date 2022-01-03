/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 12:58:43 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int	collisioncheck(int i, t_tetris *alltetri, int boxwidth)
{
	int l;
	int a;
	int b;

	l = -1;
	if((alltetri[i].pos->x + alltetri[i].size->x > boxwidth))
		return (0);
	if((alltetri[i].pos->y + alltetri[i].size->y > boxwidth))
		return (0);
	while(alltetri[++l].shape > 0)
	{
		if(l == i && l++ >= 0)
			continue;
		else if(alltetri[l].pos->x >= 0)
		{
			a = (alltetri[i].pos->x - alltetri[l].pos->x);
			b = (alltetri[i].pos->y - alltetri[l].pos->y);
			if(ft_abs(a) < 4 && ft_abs(b) < 4)
			{
				if(alltetri[i].shape & sbshort(alltetri[l].shape, a, b))
					return (0);
			}
		}
	}
	return (1);
}

int	move_tpos(int index, t_tetris *tetris, int boxwidth)
{
	if(tetris[index].pos->x  + tetris[index].size->x < boxwidth)
		tetris[index].pos->x++;
	else if(tetris[index].pos->y + tetris[index].size->y < boxwidth)
		ft_setpoint(tetris[index].pos, 0, tetris[index].pos->y + 1);
	else
	{
		ft_setpoint(tetris[index].pos, -1, -1);
		return (0);
	}
	return (1);
}

int	solver(t_tetris *alltetri, int boxwidth)
{
	int l;

	l = 0;
	while(alltetri[l].shape > 0 && alltetri[l].pos->x >= 0)
		l++;
	if(alltetri[l].shape == 0)
		return (1);
	ft_setpoint(alltetri[l].pos, 0, 0);
	while (alltetri[l].pos->x + alltetri[l].size->x <= boxwidth \
		&& alltetri[l].pos->y + alltetri[l].size->y <= boxwidth)
	{
		if(collisioncheck(l, alltetri, boxwidth))
		{
			while (solver(alltetri, boxwidth) == 0)
			{
				while(move_tpos(l, alltetri, boxwidth) == 1)
				{
					if(collisioncheck(l, alltetri, boxwidth) == 1)
						break;
				}
				if(alltetri[l].pos->x == -1)
					return (0);
			}
			return(1);
		}
		if(move_tpos(l, alltetri, boxwidth) == 0)
			return (0);
	}
	ft_setpoint(alltetri[l].pos, -1, -1);
	return (0);
}

/* int	boxsize(t_tetris *tetri)
{
	int	i;
	int	start;

	i = 0;
	while((tetri)[i].shape > 0)
	{
		i++;
	}
	start = 1;
	while (start * start < i * 4)
		start++;
	return (start);
} */

int	solve_tetris(t_tetris *tetri)
{
	int minsize;
	int	i;

	i = 0;
	while((tetri)[i].shape > 0)
	{
		i++;
	}
	minsize = 1;
	while (minsize * minsize < i * 4)
		minsize++;
	while(solver(tetri, minsize) == 0)
	{
		minsize++;
	}
	return (minsize);
}
