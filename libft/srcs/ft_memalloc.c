/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:29:43 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/01 12:34:18 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*addr;

	addr = (void *)malloc(size);
	if (!addr)
		return (NULL);
	ft_bzero(addr, size);
	return (addr);
}
