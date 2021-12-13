/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:20:46 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/11 10:15:08 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nulist;

	if (!lst)
		return (NULL);
	nulist = f(lst);
	if (nulist == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (nulist);
	else
	{
		nulist->next = ft_lstmap(lst->next, f);
		if (nulist->next == NULL)
		{
			free(nulist);
			return (NULL);
		}
	}
	return (nulist);
}
