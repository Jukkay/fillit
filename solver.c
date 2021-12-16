/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/16 13:58:39 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int	collisioncheck(int i, t_tetris **alltetri, int boxwidth)
{
	int l;

	l = 0;
	if(((*alltetri)[i].pos->x + (*alltetri)[i].size->x > boxwidth))
		return (0);
	if(((*alltetri)[i].pos->y + (*alltetri)[i].size->y > boxwidth))
		return (0);

	while((*alltetri)[l].shape > 0 && ((*alltetri)[l].pos->x >= 0))
	{
		if(l == i)
		{
			l++;
			continue;
		}
		if(sbshort((*alltetri)[i].shape, 0, 0) & sbshort((*alltetri)[l].shape, \
			(*alltetri)[i].pos->x - (*alltetri)[l].pos->x, \
			(*alltetri)[i].pos->y - (*alltetri)[l].pos->y))
			return (0);
		l++;
	}
	return (1);
}

int	move_tpos(int index, t_tetris **tetris, int boxwidth)
{
	if((*tetris)[index].pos->x  + (*tetris)[index].size->x < boxwidth)
	(*tetris)[index].pos->x++;
	else if((*tetris)[index].pos->y + (*tetris)[index].size->y < boxwidth)
	{
		(*tetris)[index].pos->x = 0;
		(*tetris)[index].pos->y++;
	}
	else
	{
		(*tetris)[index].pos->x = -1;
		(*tetris)[index].pos->y = -1;
		return (0);
	}
	return (1);
}

int	solver(t_tetris **alltetri, int boxwidth)
{

	//t_bool check;
	int l;

	l = 0;
	while((*alltetri)[l].shape > 0)
	{
		if((*alltetri)[l].pos->x == -1)
			break;
		l++;
	}
	if((*alltetri)[l].shape == 0)
		return (1);

		
	
	(*alltetri)[l].pos->x = 0;
	(*alltetri)[l].pos->y = 0;
	while ((*alltetri)[l].pos->x  + (*alltetri)[l].size->x <= boxwidth \
		&& (*alltetri)[l].pos->y + (*alltetri)[l].size->y <= boxwidth)
	{
		if(collisioncheck(l, alltetri, boxwidth))
		{
			while (solver(alltetri, boxwidth) == 0)
			{
				if(move_tpos(l, alltetri, boxwidth) == 0)
					return (0);
			}
			return(1);
		}
		else
		{
			if(move_tpos(l, alltetri, boxwidth) == 0)
				return (0);
		}
	}

	return (0);	

}

int	boxsize(t_tetris **tetri)
{
	int	i;
	int	start;

	i = 0;
	while((*tetri)[i].shape > 0)
	{
		i++;
	}
	start = 1;
	while (start * start < i * 4)
		start++;
	return (start);
}

int	solve_tetris(t_tetris **tetri)
{
	int minsize;

	minsize = boxsize(tetri);
	while(!solver(tetri, minsize))
	{
		minsize++;
	}
	return (minsize);
}
