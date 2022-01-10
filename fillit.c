/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:41:40 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/10 12:03:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetris	arr[27];
	t_tetris	*ptr;
	int			i;

	ptr = arr;
	if (argc != 2)
	{
		ft_putendl("Include ONE file name. \"./fillit <filename>\"");
		return (0);
	}
	i = -1;
	while (++i < 27)
		arr[i].shape = 0;
	if (read_file(argv, ptr))
		print_square(arr, solve_tetris(arr));
	i = -1;
	while (arr[++i].shape > 0)
	{
		free(arr[i].size);
		free(arr[i].pos);
	}
	return (0);
}
