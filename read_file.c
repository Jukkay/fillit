/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/13 15:51:36 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

int	ft_check_file_validity(int fd, char **line, char **str)
{
	int		lines;
	int		tetriminos;
	int		ret;

	lines = 0;
	tetriminos = 0;
	while (1)
	{
		ret = ft_get_next_line(fd, line);
		if (ret <= 0)
		{
			if (tetriminos > 26)
			{
				ft_putendl("error");
				return (0);
			}
			printf("string to short: %s\n", *str);
			// savetoshort(*str);
			return (1);
		}
		if (lines < 4 && ft_check_line(*line))
		{
			*str = ft_strjoinfree(*str, *line, 3);
			lines++;
			continue ;
		}
		if ((ft_strlen(*line) == 0) && lines == 4)
		{
			// if (!(ft_check_tetrimino_validity(str))
				// return (-1);
			tetriminos++;
			lines = 0;
			free(*line);
			continue ;
		}
		ft_putendl("error");
		free(*line);
		return (0);
	}
}

int	ft_read_file(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*str;

	if (argc != 2)
	{
		ft_putendl("Include ONE file name after the binary name.");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	str = ft_strnew(1);
	return (ft_check_file_validity(fd, &line, &str));
}

int	main(int argc, char **argv)
{
	int	ret;

	ret = ft_read_file(argc, argv);
	printf("ret: %d\n", ret);
	if (ret < 0)
		return (-1);
	return (0);
}