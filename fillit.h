/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:21 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/16 11:29:50 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_tetris
{
	unsigned short shape;
	t_point *size;
	t_point *pos;
}	t_tetris;

unsigned short		savetoshort(char *square);
int					validgrid(char *grid);
int					ft_read_file(int argc, char **argv, t_tetris *arr);
unsigned long long	sbshort(unsigned short i, int x, int y);
int					collisioncheck(int i, t_tetris **alltetri, int boxwidth);
void				print_bits(unsigned long long oct, unsigned long long size);
void				printstructs(t_tetris **all);
int					solver(t_tetris **alltetri, int boxwidth);
int					ft_strchrdist(char *str, int c);
int					ft_puterror(char *error);

#endif