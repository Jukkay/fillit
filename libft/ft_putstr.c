/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:46:48 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/16 12:57:34 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t	bufsize;

	bufsize = 10;
	if (!s)
		return ;
	while (ft_strnlen((char *)s, bufsize) == bufsize)
	{
		write(1, s, bufsize);
		s += bufsize;
	}
	write(1, s, ft_strnlen((char *)s, bufsize));
}
