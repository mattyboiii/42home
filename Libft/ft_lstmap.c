/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:13:41 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/31 13:01:02 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstmap
** -------------------------
** Prototype: t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
**                              void (*del)(void *));
**
** Parameters:
**    lst: The address of a pointer to a node.
**    f: The address of the function used to iterate on the list.
**    del: The address of the function used to delete the content of a node if
**         needed.
**
** Return value:
**    The new list.
**    NULL if the allocation fails.
**
** External functions: malloc, free
**
** Description:
**    Iterates the list 'lst' and applies the function 'f' on the content of
**    each node. Creates a new list resulting from the successive applications
**    of the function 'f'. The 'del' function is used to delete the content of a
**    node if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	if (!lst)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}
