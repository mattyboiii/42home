/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:36:53 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/31 10:41:28 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstdelone
** ----------------------------
** Prototype: void ft_lstdelone(t_list *lst, void (*del)(void *));
**
** Parameters:
**    lst: The node to free.
**    del: The address of the function used to delete the content.
**
** Return value: None
**
** External functions: free
**
** Description:
**    Takes as a parameter a node and frees the memory of the node’s content
**    using the function 'del' given as a parameter and free the node. The
**    memory of 'next' must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
