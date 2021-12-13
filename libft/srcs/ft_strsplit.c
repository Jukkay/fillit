/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:20:13 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/19 15:35:31 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c && *(s + 1) == '\0')
			return (i + 1);
		if (*s != c && *(s + 1) == c)
			i++;
		s++;
	}
	return (i);
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

static void	*ft_freewords(char **words, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (ft_wordcount((char *)s, c) + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		words[i] = ft_strnew((ft_wordlen((char *)s, c) + 1));
		if (!words[i])
			return (ft_freewords(words, i));
		if (ft_wordlen((char *)s, c) > 0)
		{
			ft_strncpy(words[i], s, ft_wordlen((char *)s, c));
			i++;
		}
		s = s + ft_wordlen((char *)s, c);
	}
	words[i] = NULL;
	return (words);
}
