/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:20:10 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/15 13:29:58 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (ssize <= size - i && i < size)
	{
		si = 0;
		while (haystack[i + si] == needle[si] && haystack[i + si] != '\0')
			si++;
		if (si == ssize)
		{
			return ((char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}
