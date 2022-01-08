/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:21 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/08 02:54:12 by htahvana         ###   ########.fr       */
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

t_uint16		savetoshort(char *square);
int				validgrid(char *grid);
int				read_file(char **argv, t_tetris *arr);
t_uint16		offsetshort(t_uint16 i, int x, int y);
void			print_bits(unsigned long long oct, unsigned long long size);
void			printstructs(t_tetris **all);
int				puterror(char *error);
int				solve_tetris(t_tetris *tetri);
void			print_square(t_tetris *arr, int size);
void			init_array(t_tetris *arr);
void			free_array(t_tetris *arr);
t_list			*lstsplit(const char *str, char c);
t_list			*lstnewfree(void *content, size_t content_size);
int				collisioncheck(int i, t_tetris *alltetri, t_uint16 *map);
void			remofmap(int i, t_tetris *alltetri, t_uint16 *map);
void			printtomap(int i, t_tetris *alltetri, t_uint16 *map);

#endif