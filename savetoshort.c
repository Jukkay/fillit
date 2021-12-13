/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savetoshort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:33:28 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/13 15:22:17 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//TEST FUNCTION print bits in a grid
static void	print_bits(unsigned short octet)
{
	unsigned short oct;
	oct = octet;

	unsigned short i;
	int z = 1;
	i = 1 << 15;
	while(i > 0)
	{
		if(oct & i )
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1;
		if(z%4 == 0)
			write(1, "\n", 1);
		z++;

	}
}

//flip specified bit
static unsigned short flipbit(unsigned short i, int s)
{
	i |= 1 << s;
	return (i);
}

//move bits top left
static unsigned short movetopleft(unsigned short i)
{
	while(i < 2048)
		i = i << 4;
	while(!(i & 34952))
	{
		i =  i + ((61440 & i) << 0);
		i =  i + ((3840 & i) << 0);
		i =  i + ((240 & i) << 0);
		i =  i + ((15 & i) << 0);
	}
	return (i);
}

//returns given string grid as a short number.
unsigned short	savetoshort(char *square)
{
	int				i;
	unsigned short	grid;
	char			*str;

	i = 0;
	str = square;
	grid = 0;
	while(str)
	{
		i = i + ft_strclen(str, '#');
		grid = flipbit(grid, 15 - i);
		i++;
		str = ft_strchr(str, '#');
		if(str)
			str++;
	}
	//print_bits(grid);
	grid = movetopleft(grid);
	//print_bits(grid);

	return (grid);
}