/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:23:58 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/15 13:28:49 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
