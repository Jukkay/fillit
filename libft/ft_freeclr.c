/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:51:06 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/29 23:26:39 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeclr(void *ptr, size_t n)
{
	if (ptr)
	{
		ft_bzero(ptr, n);
		ft_memdel(&ptr);
	}
}
