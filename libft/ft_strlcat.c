/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:53:53 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/16 14:30:03 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	value;

	i = ft_strlen(dst);
	if (i > dstsize)
		i = dstsize;
	value = ft_strlen((char *)src) + i;
	while (*src && dstsize - 1 > i && dstsize != 0)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	if (dstsize != 0 && (dstsize - 1 >= i))
	{
		dst[i] = '\0';
	}
	return (value);
}
