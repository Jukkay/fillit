/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:16:33 by jylimaul          #+#    #+#             */
/*   Updated: 2021/12/08 07:44:57 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, char c)
{
	const char	*chrpos;

	chrpos = ft_strchr(s, (int)c);
	if (chrpos)
		return (chrpos - s);
	return (-1);
}
