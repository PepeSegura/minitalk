/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:02:25 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:54:57 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a list, applies a function to each element of the list, and returns 
 * a new list with the results of the function
 * 
 * @param lst A pointer to the first element of a linked list.
 * @param f a pointer to a function that takes a void pointer and returns a
 * void pointer
 * @param del a function that frees the memory of the content of a link.
 * 
 * @return A pointer to the first element of the new list. 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*puntero;

	if (!lst || !f)
		return (NULL);
	puntero = NULL;
	while (lst != NULL)
	{
		final = ft_lstnew(f(lst->content));
		if (final == NULL)
		{
			ft_lstclear(&puntero, del);
			return (NULL);
		}
		ft_lstadd_back(&puntero, final);
		lst = lst->next;
	}
	return (puntero);
}
