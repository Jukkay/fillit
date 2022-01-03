/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:21 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 14:41:56 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct s_tetris
{
	unsigned short	shape;
	t_point			*size;
	t_point			*pos;
}	t_tetris;

unsigned short	savetoshort(char *square);
int				validgrid(char *grid);
int				ft_read_file(int argc, char **argv, t_tetris *arr);
unsigned short	sbshort(unsigned short i, int x, int y);
//void			print_bits(unsigned long long oct, unsigned long long size);
//void			printstructs(t_tetris **all);
int				ft_strchrdist(char *str, int c);
int				ft_puterror(char *error);
int				solve_tetris(t_tetris *tetri);
void			ft_print_square(t_tetris *arr, int size, int tetriscount);

#endif