/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:34:19 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/10 12:09:39 by ubuntu           ###   ########.fr       */
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

// checks for correct chars and amount of lines and chars
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
	free(str);
	return (0);
}

// measures tetrimino's dimensions and assigns size and position
static void	get_tetrimino_size(t_tetris **arr, char *str)
{
	t_point	size;
	t_point	min;
	t_point	max;
	int		i;

	i = 0;
	ft_setpoint(&min, 3, 3);
	ft_setpoint(&max, 0, 0);
	while (str[i])
	{
		if (str[i] == '#' && i % 4 < min.x)
			min.x = i % 4;
		if (str[i] == '#' && i % 4 > max.x)
			max.x = i % 4;
		if (str[i] == '#' && i / 4 < min.y)
			min.y = i / 4;
		if (str[i] == '#' && i / 4 > max.y)
			max.y = i / 4;
		i++;
	}
	size.x = max.x - min.x + 1;
	size.y = max.y - min.y + 1;
	(*arr)->size = ft_newpoint(size.x, size.y);
	(*arr)->pos = ft_newpoint(-1, -1);
}

// checks tetrimino validity
int	check_tetrimino(t_tetris **arr, char **str)
{
	if (!(check_shape(*str)))
		return (0);
	(*arr)->shape = save_short(*str);
	get_tetrimino_size(arr, *str);
	ft_strclr(*str);
	free(*str);
	return (1);
}
