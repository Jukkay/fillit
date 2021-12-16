/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:57:35 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/15 18:08:53 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_strchrdist(char *str, int c)
{
	char	*end;

	str = ft_strchr(str, c);
	end = ft_strrchr(str, c);
	return (end - str);
}

int	ft_puterror(char *error)
{
	ft_putendl(error);
	return (0);
}
