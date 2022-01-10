/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:19:18 by htahvana          #+#    #+#             */
/*   Updated: 2021/12/03 17:05:04 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// pops out the link at the index, runs del on it and returns it.
t_list	*ft_lstpopi(t_list **lst, size_t index, void (*del)(void *, size_t))
{
	size_t	i;
	t_list	*head;
	t_list	*temp;

	i = 0;
	head = *lst;
	temp = head;
	if (*lst == NULL)
		return (NULL);
	while (i < index)
	{
		temp = head;
		if (head->next)
			head = head->next;
		else
			return (NULL);
		i++;
	}
	temp->next = head->next;
	if (index == 0)
		*lst = (*lst)->next;
	head->next = NULL;
	if (del)
		del(head, head->content_size);
	return (head);
}
