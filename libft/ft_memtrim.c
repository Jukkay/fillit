/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:33:10 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/29 16:49:25 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memtrim(const void *src, void **dst, size_t contentsize)
{
	size_t	i;

	i = 0;
	while (!((unsigned char *)src)[i])
		i++;
	while (contentsize > i && !(((unsigned char *)src)[contentsize - 1]))
		contentsize--;
	dst = ft_memalloc(contentsize - i);
	if (!dst)
		return (0);
	ft_memcpy(dst, (src + i), contentsize - i);
	return (contentsize - i);
}
