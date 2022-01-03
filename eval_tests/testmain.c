/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:58:11 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 11:27:47 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int main(int argc, char **argv)
{
	t_tetris	arr[27];
	t_tetris	*ptr;
	int size;
	int tetriscount;

	ptr = arr;
	tetriscount = ft_read_file(argc, argv, ptr);
	printstructs(&ptr);
	size = solve_tetris(ptr);
	ft_print_square(ptr,size,tetriscount);
}
/*
ABBBB.
ACCCEE
AFFCEE
A.FFGG
HHHDDG
.HDD.G
*/