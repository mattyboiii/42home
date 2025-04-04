/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:01:26 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/31 11:18:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_lstnew
 ** -------------------------
 ** Prototype: t_list *ft_lstnew(void *content);
 **
 ** Parameters:
 **    content: The content to create the node with.
 **
 ** Return value:
 **    The new node.
 **
 ** External functions: malloc
 **
 ** Description:
 **    Allocates (with malloc(3)) and returns a new node. The member variable
 **    'content' is initialized with the value of the parameter 'content'. The
 **    variable 'next' is initialized to NULL.
 */

// ft_lstnew(content);
// *new_node.content == node->content
// *new_node.next = NULL == node-next = NULL

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
