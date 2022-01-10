/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:44:30 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/10 13:53:03 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	size++;
	str = (char *)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	while (size > 0)
	{
		str[size - 1] = '\0';
		size--;
	}
	return (str);
}
