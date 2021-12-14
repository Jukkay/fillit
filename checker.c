/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:34:19 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/14 14:11:56 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* int	check_overlap(t_tetris in, t_tetris cmp)
{
	unsigned long long sandbox;

	sandbox = cmp.shape;

	return (0);
} */

int	validgrid(char *grid)
{
	int	i;
	int	connections;
	int	pos;

	pos = -1;
	connections = 0;
	i = 4;
	while (grid[++pos])
	{
		if (grid[pos] == '#')
		{
			if (grid[pos + 1] && grid[pos + 1] == '#')
				connections++;
			if (grid[pos + 4] && grid[pos + 4] == '#')
				connections++;
			if (grid[pos - 1] && grid[pos - 1] == '#')
				connections++;
			if (grid[pos - 4] && grid[pos - 4] == '#')
				connections++;
			i--;
		}
	}
	if (connections > 5 && i == 0)
		return (TRUE);
	return (FALSE);
}