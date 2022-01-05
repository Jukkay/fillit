/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/05 12:24:19 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	get_tetrimino_size(t_tetris **arr, char *str)
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

int	check_tetrimino(t_tetris **arr, char **str)
{
	if (!(validgrid(*str)))
		return (0);
	(*arr)->shape = savetoshort(*str);
	get_tetrimino_size(arr, *str);
	ft_strclr(*str);
	free(*str);
	return (1);
}

int	validate_file(int fd, t_tetris *arr, int tetris, int last)
{
	char	buf[21];
	char	*str;
	t_list	*temp;
	int		n;

	n = read(fd, buf, 21);
	if (n == 21 || n == 20)
	{
		str = ft_strsub(buf, 0, n);
		if (!(check_lines(str, 0, n, 0)))
			return (0);
		temp = lstsplit(str, '\n');
		free(str);
		str = ft_lstjoin(temp, 0);
		ft_lstdel(&temp, &ft_freeclr);
		last = n;
		if (check_tetrimino(&arr, &str))
			return (validate_file(fd, arr + 1, tetris + 1, last));
		return (0);
	}
	if (last == 20 && tetris > 0 && tetris < 27)
		return (tetris);
	return (0);
}

int	read_file(int argc, char **argv, t_tetris *arr)
{
	int		fd;
	int		ret;
	int		i;

	i = 0;
	while (i < 26)
	{
		arr[i].shape = 0;
		i++;
	}
	if (argc != 2)
		return (puterror("Include ONE file name after the binary name."));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ret = validate_file(fd, arr, 0, 0);
	close(fd);
	if (!ret)
		return (puterror("error"));
	return (ret);
}
