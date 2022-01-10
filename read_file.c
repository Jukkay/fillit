/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:13 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/10 11:38:43 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// creates a new list item and frees memory allocated for content
static t_list	*lstnewfree(void *content, size_t content_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = malloc(content_size);
		if (!new->content && content_size)
			return (NULL);
		if (!content)
		{
			new->content = NULL;
			new->content_size = (size_t)0;
		}
		else
		{
			ft_memmove(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
	}
	else
		return (NULL);
	free(content);
	return (new);
}

// checks for index of char c
static size_t	ft_wordlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

// splits string into a list to remove newlines
static t_list	*lstsplit(const char *str, char c)
{
	t_list	*words;
	t_list	*word;

	words = NULL;
	if (!str)
		return (NULL);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		word = lstnewfree(ft_strnew((ft_wordlen((char *)str, c) + 1)), \
		(ft_wordlen((char *)str, c) + 1));
		if (!word)
		{
			ft_lstdel(&words, &ft_freeclr);
			return (NULL);
		}
		if (ft_wordlen((char *)str, c) > 0)
			ft_memmove(word->content, str, ft_wordlen((char *)str, c));
		ft_lstput(&words, word);
		str = str + ft_wordlen((char *)str, c);
	}
	return (words);
}

// checks file validity
static int	validate_file(int fd, t_tetris *arr, int tetris, int last)
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

// opens and closes files and prints errors
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
		ft_putendl("error");
		return (0);
	}
	return (ret);
}
