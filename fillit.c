/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:41:40 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/06 10:06:15 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetris	arr[28];
	t_tetris	*ptr;
	int			size;

	ptr = arr;
	if (argc != 2)
		return (puterror("Include ONE file name. \"./fillit <filename>\""));
	if (read_file(argc, argv, ptr))
	{
		size = solve_tetris(arr);
		print_square(arr, size);
	}
	freearr(arr);
	return (0);
}
