/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savetoshort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:33:28 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/19 12:39:00 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//TEST FUNCTION print bits in a grid
void	print_bits(unsigned long long oct, unsigned long long size)
{
	unsigned long long i;
	int z = 1;
	i = 1;
	i = i << size;
	while(i > 0)
	{
		if(oct & i )
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1;
		if(size == 15)
		{
			if(z%4 == 0)
				write(1, "\n", 1);
		}
		else if(size == 63)
		{
			if(z%8 == 0)
			write(1, "\n", 1);
		}
		z++;
	}
}

//flip specified bit
static unsigned short flipbit(unsigned short i, int s)
{
	i |= 1 << s;
	return (i);
}

//make sandbox long long from given short and offset coordinates
unsigned short sbshort(unsigned short i, int x, int y)
{
	unsigned short result;

	if(x < 0)
		result = (15 & ((i & 15) << abs(x))) |
				(240 & ((i & 240) << abs(x))) |
				(3840 & ((i & 3840) << abs(x))) |
				(61440 & ((i & 61440) << abs(x)));
	else
		result = (15 & ((i & 15) >> x)) |
				(240 & ((i & 240) >> x)) |
				(3840 & ((i & 3840) >> x)) |
				(61440 & ((i & 61440) >> x));
	i = result;
 	if(y < 0)
		result = (15 & ((i & 15) << (abs(y) * 4))) |
				(240 & ((i & 240) << (abs(y) * 4))) |
				(3840 & ((i & 3840) << (abs(y) * 4))) |
				(61440 & ((i & 61440) << (abs(y) * 4)));

	else
		result = (15 & ((i & 15) >> (y * 4))) |
				(240 & ((i & 240) >> (y * 4))) |
				(3840 & ((i & 3840) >> (y * 4))) |
				(61440 & ((i & 61440) >> (y * 4))); 
	return (result);
}

//move bits top left
static unsigned short movetopleft(unsigned short i)
{
	while(i < 4096)
		i = i << 4;
	while(!(i & 34952))
	{
		i =  i << 1;
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
	//print_bits(grid, 15);
	grid = movetopleft(grid);
/* 	ft_putendl("");
	print_bits(grid, 15);
	ft_putendl("");
	print_bits(sbshort(grid, 1, 1), 63);
	ft_putendl(""); */
	return (grid);
}