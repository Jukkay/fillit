/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/21 18:28:48 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '.' || line[i] == '#' || line[i] == '\n')
		{
			i++;
			continue ;
		}
		return (0);
	}
	if (ft_strlen(line) != 5 || line[4] != '\n')
		return (0);
	return (1);
}

void	ft_get_size(t_tetris **arr, char *str)
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

int	ft_check_tetris(t_tetris **arr, char **str, int *ln, int *tetris)
{
	int		i;
	char	**ret;

	i = 0;
	ret = ft_strsplit(*str, '\n');
	ft_strclr(*str);
	while (ret[i])
	{
		*str = ft_strjoinfree(*str, ret[i], 3);
		i++;
	}
	free(ret);
	if (!(validgrid(*str)))
		return (0);
	(*arr)->shape = savetoshort(*str);
	ft_get_size(arr, *str);
	*arr += 1;
	*tetris += 1;
	*ln = 0;
	ft_strclr(*str);
	return (1);
}

int	ft_validfile(int fd, t_tetris *arr, int ln, int tetris)
{
	char	*line;
	char	*str;

	str = ft_strnew(1);
	while (ft_get_next_line(fd, &line) == 1)
	{
		if (ln < 4 && ft_check_line(line))
		{
			str = ft_strjoinfree(str, line, 1);
			ln++;
			continue ;
		}
		if ((ft_strlen(line) == 1) && ln == 4)
		{
			if (ft_check_tetris(&arr, &str, &ln, &tetris))
				continue ;
			return (0);
		}
		return (0);
	}
	if (!(ft_check_tetris(&arr, &str, &ln, &tetris)))
		return (0);
	if (tetris > 0 && tetris < 27)
		return (tetris);
	return (0);
}

int	ft_read_file(int argc, char **argv, t_tetris *arr)
{
	int		fd;
	int		ret;

	arr[26].shape = 0;
	if (argc != 2)
		return (ft_puterror("Include ONE file name after the binary name."));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ret = ft_validfile(fd, arr, 0, 0);
	close(fd);
	if (!ret)
		return (ft_puterror("error"));
	return (ret);
}
