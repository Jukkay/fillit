/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:01:27 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/21 17:06:02 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_and_write_tail(char **tail, char *buf, char **line)
{
	int			len;

	if (!(*tail))
		*tail = ft_strnew(BUFF_SIZE);
	if (!(*tail))
		return (-1);
	ft_bzero(buf, BUFF_SIZE);
	if (ft_strchr(*tail, '\n'))
	{
		len = ft_strchri(*tail, '\n');
		*line = ft_strsub(*tail, 0, len + 1);
		if (!(*line))
			return (-1);
		*tail = ft_strsubfree(*tail, len + 1, (ft_strlen(*tail) - len));
		if (!(*tail))
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_check_and_write_buf(char *buf, char **tail, char **line, int n)
{
	int		len;
	char	*temp;

	if (ft_memchr(buf, '\n', n))
	{
		len = ft_strchri(buf, '\n');
		if (len < 0)
			return (-1);
		temp = ft_strsub(buf, 0, len + 1);
		if (!temp)
			return (-1);
		*line = ft_strjoinfree(*tail, temp, 3);
		*tail = ft_strsub(buf, len + 1, (n - len - 1));
		if (!(*line) || !(*tail))
			return (-1);
		return (1);
	}
	temp = ft_strsub(buf, 0, n);
	if (!temp)
		return (-1);
	*tail = ft_strjoinfree(*tail, temp, 3);
	if (!(*tail))
		return (-1);
	ft_bzero(buf, n);
	return (0);
}

static int	ft_final_tail_check(char **tail, char **line)
{
	if (ft_strlen(*tail))
	{
		*line = ft_strsub(*tail, 0, ft_strlen(*tail));
		if (!(*line))
			return (-1);
		ft_bzero(*tail, ft_strlen(*tail));
		return (1);
	}
	return (0);
}

static int	ft_process_fd(char *buf, char **tail, char **line, int fd)
{
	int	n;
	int	ret;

	while (!(ft_memchr(buf, '\n', BUFF_SIZE)))
	{
		n = read(fd, buf, BUFF_SIZE);
		if (n <= 0)
		{
			ret = ft_final_tail_check(&tail[fd], line);
			if (ret > 0)
				return (1);
			if (ret < 0)
				return (-1);
			if (!n)
				return (0);
			return (-1);
		}
		n = ft_check_and_write_buf(buf, &tail[fd], line, n);
		if (n > 0)
			return (1);
		if (n < 0)
			return (-1);
	}
	return (0);
}

int	ft_get_next_line(const int fd, char **line)
{
	int			n;
	char		buf[BUFF_SIZE];
	static char	*tail[12289];

	if (fd < 0 || fd > 12288 || !line || BUFF_SIZE <= 0)
		return (-1);
	n = ft_check_and_write_tail(&tail[fd], buf, line);
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	n = ft_process_fd(buf, tail, line, fd);
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	if (ft_strlen(tail[fd]))
		free(tail[fd]);
	return (0);
}
