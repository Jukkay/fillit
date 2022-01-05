/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:57:35 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/05 11:16:24 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	puterror(char *error)
{
	ft_putendl(error);
	return (0);
}

void	freearr(t_tetris *arr, int tetriscount)
{
	int	i;

	i = 0;
	while (i < tetriscount)
	{
		free(arr[i].size);
		free(arr[i].pos);
		i++;
	}
}
