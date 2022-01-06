/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:57:35 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/06 10:48:56 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	puterror(char *error)
{
	ft_putendl(error);
	return (0);
}

void	init_array(t_tetris *arr)
{
	int		i;

	i = 0;
	while (i < 27)
	{
		arr[i].shape = 0;
		i++;
	}
}

void	free_array(t_tetris *arr)
{
	int	i;

	i = 0;
	if (arr[0].shape == 0)
		return ;
	while (arr[i].shape > 0)
	{
		free(arr[i].size);
		free(arr[i].pos);
		i++;
	}
}
