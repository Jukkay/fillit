/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:41:40 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/20 19:04:41 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			tetriscount;
	t_tetris	arr[27];
	t_tetris	*ptr;
	int			size;
	int			i;

	ptr = arr;
	i = 0;
	if (argc != 2)
		return (ft_puterror("Include ONE file name after the binary name."));
	tetriscount = ft_read_file(argc, argv, ptr);
	if (!tetriscount)
		return (0);
	size = solve_tetris(arr);
	ft_print_square(arr, size, tetriscount);
	return (0);
}
