/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:56:03 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/18 10:29:53 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longcheck(unsigned long nbr, int sign)
{
	if (sign == -1 && nbr > 9223372036854775807)
		return (0);
	if (sign == 1 && nbr > 9223372036854775807)
		return (-1);
	return ((int)nbr * sign);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	value;

	value = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (ft_isdigit(*(str + 1)))
		{
			sign = 1 - 2 * (*str == '-');
			str++;
		}
	}
	while (ft_isdigit(*str))
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	return (ft_longcheck(value, sign));
}
