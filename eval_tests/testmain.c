/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:58:11 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/17 15:22:31 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int main(int argc, char **argv)
{
	t_tetris	arr[27];
	t_tetris	*ptr;
	
	ptr = arr;
	ft_read_file(argc, argv, ptr);
	//printstructs(&ptr);
	ft_putnbr(solve_tetris(ptr));
	ft_putendl("==-==");
	printstructs(&ptr);
}
/*
ABBBB.
ACCCEE
AFFCEE
A.FFGG
HHHDDG
.HDD.G
*/