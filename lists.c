/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:08:58 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/06 16:51:26 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	assing_val(t_list *new, void const *content, size_t content_size)
{
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

t_list	*lstnewfree(void *content, size_t content_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = malloc(content_size);
		if (!new->content && content_size)
		{
			free(new->content);
			free(new);
			return (NULL);
		}
	}
	else
		return (NULL);
	assing_val(new, content, content_size);
	free(content);
	return (new);
}

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

t_list	*lstsplit(const char *str, char c)
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
