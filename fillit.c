/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:41:40 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/06 10:38:52 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetris	arr[27];
	t_tetris	*ptr;

	ptr = arr;
	if (argc != 2)
		return (puterror("Include ONE file name. \"./fillit <filename>\""));
	init_array(arr);
	if (read_file(argv, ptr))
		print_square(arr, solve_tetris(arr));
	free_array(arr);
	return (0);
}
