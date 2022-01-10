/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:42:23 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/16 16:09:20 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ssize;
	size_t	i;
	size_t	size;
	size_t	si;

	i = 0;
	si = 0;
	size = ft_strlen((char *)haystack);
	ssize = ft_strlen((char *)needle);
	if (ssize == 0)
		return ((char *)haystack);
	while (i < len && ssize <= size - i && i < size)
	{
		si = 0;
		while (i + si < len && haystack[i + si] == needle[si] \
		&& haystack[i + si] != '\0')
			si++;
		if (si >= ssize)
			return ((char *)&(haystack[i]));
		i++;
	}
	return (NULL);
}
