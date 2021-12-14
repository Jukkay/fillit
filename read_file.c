/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/14 17:46:12 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"


// output to struct array. 26 slots. savetoshor returns short that goes in the struct.
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

int	ft_check_tetris(char *line, char **str, int ln, short a)
{
	if ((ft_strlen(line) == 0) && ln == 4)
	{
		if (!(validgrid(*str)))
			return (-1);
		printf("string to short: %s\n", *str);
		a = savetoshort(*str);
		printf("returned short: %hu\n", a);
		ft_strclr(*str);
		return (1);
	}
	return (0);
}

int	ft_valifile(int fd, char **str, int ln, int tetris)
{
	int		ret;
	char	*line;
	int		check;
	short	a;

	a = 0;
	ret = ft_get_next_line(fd, &line);
	printf("gnl returned: %d\n", ret);
	if (ret <= 0)
	{
		if (ret < 0)
			return (-1);
		if (tetris > 0 && tetris < 27)
			return (1);
		ft_putendl("error");
		return (0);
	}
	if (ln < 4 && ft_check_line(line))
	{
		*str = ft_strjoinfree(*str, line, 3);
		return (ft_valifile(fd, str, ln + 1, tetris));
	}
	check = ft_check_tetris(line, str, ln, a);
	if (check > 0)
		return (ft_valifile(fd, str, ln = 0, tetris + 1));
	if (check < 0)
		return (-1);
	ft_putendl("error");
	return (0);
}

// char	*ft_write_arr()
// {

// }

int	ft_read_file(int argc, char **argv, t_tetris *arr)
{
	int		fd;
	char	*str;
	int		ln;

	ln = 0;
	arr[26].shape = 0;
	if (argc != 2)
	{
		ft_putendl("Include ONE file name after the binary name.");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	str = ft_strnew(1);
	ln = ft_valifile(fd, &str, ln, 0);
	// if (!ft_write_arr())
	// 	return (-1);
	close(fd);
	return (ln);
}

int	main(int argc, char **argv)
{
	int			ret;
	t_tetris	arr[27];

	arr[26].shape = 0;
	ret = ft_read_file(argc, argv, arr);
	printf("ret: %d\n", ret);
	if (ret < 0)
		return (-1);
	return (0);
}

// call read_file from main
// 	check file validity (recursive)
// 		fd
// 		str
// 		ln
// 		tetris
// 	write content to arr
// 		fd
// 		arr

// handle tetriminos in the arr