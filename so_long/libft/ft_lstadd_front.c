/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:33:34 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/31 10:55:41 by mtripodi         ###   ########.fr       */
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

//**lst = *200
//*lst = 101
//*lst->next = 102
//*new = 103
//*new->next = 104

//*new->next = lst
//*lst = new;

//*lst = 103
//*lst->next = 101
//*lst->next->next = 102.

// its next value to be the thing to put after

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		(*lst) = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
