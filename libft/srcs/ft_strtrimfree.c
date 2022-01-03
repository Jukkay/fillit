/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jylimaul <jylimaul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:28:03 by jylimaul          #+#    #+#             */
/*   Updated: 2022/01/03 15:30:50 by jylimaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_start(char const *s)
{
	int	i;
	int	ws;

	i = 0;
	ws = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
	{
		ws++;
		i++;
	}
	if (s[i] == '\0')
		ws = 0;
	return (ws);
}

static int	ft_check_end(char const *s)
{
	size_t	i;
	int		ws;

	i = ft_strlen(s) - 1;
	ws = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
	{
		ws++;
		i--;
	}
	return (ws);
}

char	*ft_strtrimfree(char *s)
{
	size_t	len;
	size_t	i;
	int		ws;
	char	*str;

	if (!s)
		return (NULL);
	ws = ft_check_start(s) + ft_check_end(s);
	len = ft_strlen(s) - ws;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	ws = ft_check_start(s);
	while (i < len)
	{
		str[i] = s[ws];
		i++;
		ws++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}
