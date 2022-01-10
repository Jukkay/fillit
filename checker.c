/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:34:19 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/10 12:02:33 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//checks if given string includes a valid tetrimino shape
int	check_shape(char *grid)
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

int	check_lines(char *str, int i, int n, int ln)
{
	int	ch;

	ch = 0;
	while (i < n)
	{
		if (str[i] == '.' || str[i] == '#')
		{
			ch++;
			i++;
			continue ;
		}
		if (ch == 4 && str[i] == '\n')
		{
			ln++;
			i++;
			ch = 0;
			continue ;
		}
		i++;
		break ;
	}
	if (ln == 4 && str[i] == '\0')
		return (1);
	return (0);
}
