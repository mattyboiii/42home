/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:16:17 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/28 15:30:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstadd_back
** ------------------------------
** Prototype: void ft_lstadd_back(t_list **lst, t_list *new);
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
**    Adds the node 'new' at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	*lst = (ft_lstlast(*lst)->next);
	*lst = new;
	new->next = NULL;
}
