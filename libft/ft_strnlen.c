/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:23:01 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/16 12:55:23 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (*str && i < maxlen)
	{
		i++;
		str++;
	}
	return (i);
}
