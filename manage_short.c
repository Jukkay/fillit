/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:33:28 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/10 12:23:00 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//TEST FUNCTION print bits in a grid
/* void	print_bits(unsigned long long oct, unsigned long long size)
{
	unsigned long long	i;
	int z = 1;
	i = 1;
	i = i << size;
	while (i > 0)
	{
		if (oct & i )
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1;
		if (size == 15)
		{
			  if (z%4 == 0)
				write(1, "\n", 1);
		}
		else if (size == 63)
		{
			if (z%8 == 0)
			write(1, "\n", 1);
		}
		z++;
	}
} */

//offset given short in the short grid
unsigned short	offsetshort(unsigned short i, int x, int y)
{
	unsigned short	result;

	result = 0;
	if (x >= 0)
		result = (15 & ((i & 15) << x))
			| (240 & ((i & 240) << x))
			| (3840 & ((i & 3840) << x))
			| (61440 & ((i & 61440) << x));
	else
		result = (15 & ((i & 15) >> ft_abs(x)))
			| (240 & ((i & 240) >> ft_abs(x)))
			| (3840 & ((i & 3840) >> ft_abs(x)))
			| (61440 & ((i & 61440) >> ft_abs(x)));
	if (y >= 0)
		while (y-- > 0)
			result = result << 4;
	else
		while (y++ < 0)
			result = result >> 4;
	return (result);
}

//returns given string grid as a short number.
unsigned short	save_short(char *line)
{
	int				i;
	unsigned short	grid;
	char			*str;

	i = 0;
	str = line;
	grid = 0;
	while (str)
	{
		i = i + ft_strclen(str, '#');
		grid |= 1 << (15 - i);
		i++;
		str = ft_strchr(str, '#');
		if (str)
			str++;
	}
	while (grid < 4096)
		grid <<= 4;
	while (!(grid & 34952))
		grid <<= 1;
	return (grid);
}
