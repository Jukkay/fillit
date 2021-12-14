/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/14 19:01:02 by jylimaul         ###   ########.fr       */
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

int	ft_valifile(int fd, t_tetris *arr, int ln, int tetris)
{
	char	*line;
	char	*str;

	str = ft_strnew(20);
	while(ft_get_next_line(fd, &line) == 1)
	{
		if (ln < 4 && ft_check_line(line))
		{
			str = ft_strjoinfree(str, line, 3);
			ln++;
			continue ;
		}
		if ((ft_strlen(line) == 0) && ln == 4)
		{
			if (!(validgrid(str)))
				return (-1);
			printf("string to short: %s\n", str);
			arr->shape = savetoshort(str);
			printf("returned short: %hu\n", arr->shape);
			arr++;
			tetris++;
			ln = 0;
			ft_strclr(str);
			continue ;
		}
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int	ft_read_file(int argc, char **argv, t_tetris *arr)
{
	int		fd;
	int		ln;

	arr[26].shape = 0;
	if (argc != 2)
	{
		ft_putendl("Include ONE file name after the binary name.");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	ln = ft_valifile(fd, arr, 0, 0);
	close(fd);
	return (ln);
}

int	main(int argc, char **argv)
{
	int			ret;
	t_tetris	arr[27];
	t_tetris	*ptr;

	ptr = arr;
	ret = ft_read_file(argc, argv, ptr);
	printf("ret: %d\n", ret);
	if (ret < 0)
		return (-1);
	return (0);
}
