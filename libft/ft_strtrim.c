/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:04:11 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/15 13:30:20 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islimitedspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_islimitedspace((char)*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	len = ft_strlen((char *)s);
	while (ft_islimitedspace(s[len - 1]))
		len--;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
