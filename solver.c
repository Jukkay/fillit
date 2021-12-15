/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:56:48 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/15 11:48:46 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/* int	shortcompare(t_tetris *t1, t_tetris *t2)
{
	return (!(sbshort(t1->shape, 0, 0)
	& (sbshort(t2->shape, t2->pos->x, t2->pos->y))));
} */

int collisioncheck(t_point curpos, t_tetris *current, t_tetris **alltetri, int boxwidth)
{
	int l;
	
	l = 0;
	if(curpos.x + current->size->x > boxwidth)
		return (0);
	if(curpos.y + current->size->y > boxwidth)
		return (0);
	while(alltetri[l] && alltetri[l]->pos->x >= 0)
	{
		if(sbshort(current, 0, 0) & sbshort(alltetri[l]->shape, \
			curpos.x - alltetri[l]->pos->x, curpos.y - alltetri[l]->pos->y))
			return (0);
		l++;
	}
	return (1);
}

/* int	solver(t_tetris ***tetri, t_point *start)
{

	int	result = 0;

	while(tetri with pos -1 is found)
	{
		if !collisioncheck(tetri to all tetri with a pos)
			set tetri pos
			continue;
		result = solver(tetri, start);
		if(result == 0)
			reset pos;

	}

	return (0)
}
 */
int solve_tetris(t_tetris ***tetri)
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
)

}