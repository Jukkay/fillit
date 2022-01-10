/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:45:40 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/03 12:39:43 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*orig;

	orig = s1;
	s1 = s1 + ft_strlen(s1);
	while (*s2 && n > 0)
	{
		*s1 = *s2;
		n--;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (orig);
}
