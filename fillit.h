/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:21 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/04 15:03:56 by jylimaul         ###   ########.fr       */
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
int				read_file(int argc, char **argv, t_tetris *arr);
unsigned short	offsetshort(unsigned short i, int x, int y);
//void			print_bits(unsigned long long oct, unsigned long long size);
//void			printstructs(t_tetris **all);
int				puterror(char *error);
int				solve_tetris(t_tetris *tetri);
void			print_square(t_tetris *arr, int size, int tetriscount);
void			freearr(t_tetris *arr, int tetriscount);
void			freelst(t_list **alst);

#endif