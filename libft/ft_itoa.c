/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:22:15 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/15 12:51:43 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	stringer(int n, char *str)
{
	if (!(str[ft_intdigits(n) - 1]))
		str[ft_intdigits(n) - 1] = (n % 10) + '0';
	if (n / 10 == 0)
		return ;
	stringer(n / 10, str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;

	negative = 0;
	if (n < 0)
		negative = 1;
	str = ft_strnew(ft_intdigits(n) + negative);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648 && n++ < 0)
			str[10] = '8';
		stringer(n * -1, (str + 1));
	}
	else
		stringer(n, str);
	return (str);
}
