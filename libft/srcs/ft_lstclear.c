/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:00:11 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:54:47 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a pointer to a pointer to a linked list, and a pointer to a function
 * that takes a pointer to a void and returns nothing. It then iterates through
 * the linked list, deleting each node and setting the pointer to the next node
 * 
 * @param lst a pointer to the first element of a linked list
 * @param del a pointer to a function that takes a single void pointer argument 
 * and returns nothing. 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
