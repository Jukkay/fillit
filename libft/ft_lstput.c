/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:38:46 by htahvana          #+#    #+#             */
/*   Updated: 2021/11/24 14:31:03 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstput(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (!new)
		return ;
	if (ptr == 0)
	{
		*alst = new;
		return ;
	}
	while (ptr->next != 0)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}
