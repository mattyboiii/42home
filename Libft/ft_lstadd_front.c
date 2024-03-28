/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:33:34 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/28 13:43:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstadd_front
** --------------------------------
** Prototype: void ft_lstadd_front(t_list **lst, t_list *new);
**
** Parameters:
**    lst: The address of a pointer to the first link of a list.
**    new: The address of a pointer to the node to be added to the list.
**
** Return value: None
**
** External functions: None
**
** Description:
**    Adds the node 'new' at the beginning of the list.
*/

// new->content  new->next = NULL        

	//*200 100
	//*100
	//*200 = 101
	//*200 101
	// new = 101
	//*lst->next = 103

// its next value to be the thing to put after

void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	node = new;
	node->next = *lst;
	*lst = node;
}
