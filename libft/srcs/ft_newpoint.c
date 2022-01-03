/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:03:46 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 14:11:08 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	*ft_newpoint(int x, int y)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}
