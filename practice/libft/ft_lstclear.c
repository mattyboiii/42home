/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:30:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/31 11:57:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstclear
** ---------------------------
** Prototype: void ft_lstclear(t_list **lst, void (*del)(void *));
**
** Parameters:
**    lst: The address of a pointer to a node.
**    del: The address of the function used to delete the content of the node.
**
** Return value: None
**
** External functions: free
**
** Description:
**    Deletes and frees the given node and every successor of that node, using
**    the function 'del' and free(3). Finally, the pointer to the list must be
**    set to NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
	*lst = NULL;
}
