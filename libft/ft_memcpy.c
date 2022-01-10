/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:00:58 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/10 15:08:52 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	void	*ptr;

	ptr = dst;
	if (!dst && !src && n > 0)
		return (NULL);
	while (n > 0)
	{
		*(char *)ptr = *(char *)src;
		ptr++;
		src++;
		n--;
	}
	return (dst);
}
