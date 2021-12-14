/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:21 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/14 15:16:49 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include "ft_point.h"

typedef struct s_tetris
{
	unsigned short shape;
	t_point *pos;

}	t_tetris;

unsigned short		savetoshort(char *square);
int					validgrid(char *grid);
int					ft_read_file(int argc, char **argv);
unsigned long long	sandboxshort(unsigned short i, int x, int y);

#endif