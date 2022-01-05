/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:41:40 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/05 13:05:43 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			tetriscount;
	t_tetris	arr[27];
	t_tetris	*ptr;
	int			size;

	ptr = arr;
	if (argc != 2)
		return (puterror("Include ONE file name. \"./fillit <filename>\""));
	tetriscount = read_file(argc, argv, ptr);
	if (!tetriscount)
		return (0);
	size = solve_tetris(arr);
	print_square(arr, size, tetriscount);
	freearr(arr, tetriscount);
	return (0);
}
