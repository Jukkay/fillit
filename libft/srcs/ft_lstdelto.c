/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelto.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:51:13 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/23 12:27:45 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstdelto(t_list **alst, t_list **lst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst == NULL)
		return (NULL);
	if (*alst == *lst)
		return (*alst);
	del((*alst)->content, (*alst)->content_size);
	temp = ft_lstdelto(&((*alst)->next), lst, del);
	free(*alst);
	*alst = NULL;
	if (temp)
		*alst = temp;
	return (temp);
}
