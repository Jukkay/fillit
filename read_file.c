/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/15 12:42:26 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

// tetrimino size to t_point

int	ft_puterror(char *error)
{
	ft_putendl(error);
	return (0);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '.' || line[i] == '#')
			i++;
		else
			return (0);
	}
	if (ft_strlen(line) != 4)
		return (0);
	return (1);
}

int	ft_check_tetris(t_tetris **arr, char **str, int *ln, int *tetris)
{
	if (!(validgrid(*str)))
		return (ft_puterror("error"));
	printf("string to short: %s\n", *str);
	(*arr)->shape = savetoshort(*str);
	printf("returned short: %hu\n", (*arr)->shape);
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
			str = ft_strjoinfree(str, line, 3);
			ln++;
			continue ;
		}
		if ((ft_strlen(line) == 0) && ln == 4)
		{
			if (ft_check_tetris(&arr, &str, &ln, &tetris))
				continue ;
			return (0);
		}
		return (ft_puterror("error"));
	}
	if (!(ft_check_tetris(&arr, &str, &ln, &tetris)))
		return (0);
	if (tetris > 0 && tetris < 27)
		return (tetris);
	return (ft_puterror("error"));
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
	return (ret);
}

int	main(int argc, char **argv)
{
	int			tetriscount;
	t_tetris	arr[27];
	t_tetris	*ptr;

	ptr = arr;
	tetriscount = ft_read_file(argc, argv, ptr);
	printf("tetriscount: %d\n", tetriscount);
	return (0);
}
