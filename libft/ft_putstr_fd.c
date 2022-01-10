/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:45:48 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/16 12:57:24 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	bufsize;

	bufsize = 10;
	if (!s)
		return ;
	while (ft_strnlen((char *)s, bufsize) == bufsize)
	{
		write(fd, s, bufsize);
		s += bufsize;
	}
	write(fd, s, ft_strnlen((char *)s, bufsize));
}
