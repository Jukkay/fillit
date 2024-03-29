/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:21:22 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/16 12:57:55 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\f' || c == '\r' || c == '\v' )
		return (TRUE);
	return (FALSE);
}
