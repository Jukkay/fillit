/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:21 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/10 11:19:16 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef unsigned short	t_uint16;
typedef struct s_tetris
{
	t_uint16		shape;
	t_point			*size;
	t_point			*pos;
}	t_tetris;

t_uint16		save_short(char *square);
int				check_shape(char *grid);
int				check_lines(char *str, int i, int n, int ln);
int				check_tetrimino(t_tetris **arr, char **str);
int				read_file(char **argv, t_tetris *arr);
t_uint16		offsetshort(t_uint16 i, int x, int y);
int				solve_tetris(t_tetris *tetri);
void			print_square(t_tetris *arr, int size);
int				collisionmap(int i, t_tetris *alltetri, t_uint16 *map);
void			rmofmap(int i, t_tetris *alltetri, t_uint16 *map);
void			printtomap(int i, t_tetris *alltetri, t_uint16 *map);

#endif