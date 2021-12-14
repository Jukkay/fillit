/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savetoshort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:33:28 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/14 15:18:37 by htahvana         ###   ########.fr       */
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
unsigned long long sandboxshort(unsigned short i, int x, int y)
{
	unsigned long long sandbox;
	unsigned long long mask;

	sandbox = i;
	sandbox = sandbox << 12;
	mask = (16777215 & sandbox);
	mask >>= 4;
	sandbox = sandbox & 251658240;
	sandbox |= mask;
	mask = (65535 & sandbox);
	mask >>= 4;
	sandbox = sandbox & 252641280;
	sandbox |= mask;
	mask = (255 & sandbox);
	mask >>= 4;
	sandbox = sandbox & 252645120;
	sandbox |= mask;

	sandbox =  sandbox << ft_abs(x);
	sandbox =  sandbox << ft_abs(y * 8);

	return (sandbox);
}


//move bits top left
static unsigned short movetopleft(unsigned short i)
{
	while(i < 2048)
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
	//ft_putendl("");
	//print_bits(grid, 15);
	//ft_putendl("");
	//print_bits(movebits(grid, -1, -1), 63);
	//ft_putendl("");
	//ft_putnbr((int)sizeof(unsigned short));
	return (grid);
}