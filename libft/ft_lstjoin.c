/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:43:24 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/06 12:14:40 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//joins given linkedlist as a single string for return.
char	*ft_lstjoin(t_list *lst, char limit)
{
	size_t	size;
	char	*str;

	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	if (limit)
		size = size + ft_lstlen(lst);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	while (lst)
	{
		ft_memcpy((str + ft_strlen(str)), lst->content, lst->content_size);
		if (limit && lst->next)
			(str)[ft_strlen(str)] = limit;
		lst = lst->next;
	}
	return (str);
}
