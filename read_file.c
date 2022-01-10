/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/10 12:02:34 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (!(check_shape(*str)))
		return (0);
	(*arr)->shape = save_short(*str);
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
	if ((n == 21 || n == 20) && tetris < 26)
	{
		str = ft_strsub(buf, 0, n);
		if (!(check_lines(str, 0, n, 0)))
			return (0);
		temp = lstsplit(str, '\n');
		ft_freeclr(str, n);
		str = ft_lstjoin(temp, 0);
		ft_lstdel(&temp, &ft_freeclr);
		last = n;
		ft_bzero(buf, 21);
		if (check_tetrimino(&arr, &str))
			return (validate_file(fd, arr + 1, tetris + 1, last));
		free(str);
		return (0);
	}
	if (last == 20 && tetris > 0 && tetris < 27)
		return (1);
	return (0);
}

int	read_file(char **argv, t_tetris *arr)
{
	int		fd;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ret = validate_file(fd, arr, 0, 0);
	close(fd);
	if (!ret)
	{
		ft_putendl_fd("error", 2);
		return (0);
	}
	return (ret);
}
