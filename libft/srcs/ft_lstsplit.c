/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:47:24 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/24 19:36:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_list	*ft_lstsplit(const char *str, char c)
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
		word = ft_lstnew(ft_strnew((ft_wordlen((char *)str, c) + 1)), \
		(ft_wordlen((char *)str, c) + 1));
		if (!word)
		{
			ft_lstdel(&words, &ft_freeclr);
			return (NULL);
		}
		if (ft_wordlen((char *)str, c) > 0)
			ft_strncpy(word->content, str, ft_wordlen((char *)str, c));
		ft_lstput(&words, word);
		str = str + ft_wordlen((char *)str, c);
	}
	return (words);
}
