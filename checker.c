/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:34:19 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 14:13:22 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* void	printstructs(t_tetris **all)
{
	int	i;

	i = 0;
	while ((*all)[i].shape > 0)
	{
		print_bits((*all)[i].shape,15);
		ft_putstr("pos:");
		ft_putnbr((*all)[i].pos->x);
		ft_putchar('-');
		ft_putnbr((*all)[i].pos->y);
		ft_putstr(";size:");
		ft_putnbr((*all)[i].size->x);
		ft_putchar('-');
		ft_putnbr((*all)[i].size->y);
		ft_putendl("========");

		i++;
	}
			ft_putendl("");
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
			if (pos < 16 && grid[pos + 1] && grid[pos + 1] == '#')
				connections++;
			if (pos < 12 && grid[pos + 4] && grid[pos + 4] == '#')
				connections++;
			if (pos > 0 && grid[pos - 1] && grid[pos - 1] == '#')
				connections++;
			if (pos > 3 && grid[pos - 4] && grid[pos - 4] == '#')
				connections++;
			i--;
		}
	}
	if (connections > 5 && i == 0)
		return (TRUE);
	return (FALSE);
}
