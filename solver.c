/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/16 11:23:15 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	collisioncheck(int i, t_tetris **alltetri, int boxwidth)
{
	int l;

	l = 0;
	if((*alltetri)[i].pos->x + (*alltetri)[i].size->x >= boxwidth)
		return (0);
	if((*alltetri)[i].pos->y + (*alltetri)[i].size->y >= boxwidth)
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
		return (0);

	(*alltetri)[l].pos->x = 0;
	(*alltetri)[l].pos->y = 0;
	while ((*alltetri)[l].pos->x  + (*alltetri)[l].size->x <= boxwidth \
		|| (*alltetri)[l].pos->y + (*alltetri)[l].size->y <= boxwidth)
	{

		if(collisioncheck(l, alltetri, boxwidth))
		{
			solver(alltetri, boxwidth);
			return (1);
		}

		if((*alltetri)[l].pos->x  + (*alltetri)[l].size->x <= boxwidth)
			(*alltetri)[l].pos->x++;
		else if((*alltetri)[l].pos->y + (*alltetri)[l].size->y <= boxwidth)
		{
			(*alltetri)[l].pos->x = 0;
			(*alltetri)[l].pos->y++;
		}
		else
		{
			(*alltetri)[l].pos->x = -1;
			(*alltetri)[l].pos->y = -1;
			return (0);
		}
	}


	return (0);	

}


/* int solve_tetris(t_tetris ***tetri)
{
	int minsize;
	t_point *start;
	start = (t_point *)malloc(sizeof(t_point));
	start->x = 0;
	start->y = 0;

	minsize = smallest(tetri);
	while(!solver(tetri, start))
	{
		minsize++;
	}
} */
