/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:16:17 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/02 11:26:21 by mtripodi         ###   ########.fr       */
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

// somthing to add is the fact that *new needs to be a valid pointer before
// being passed into ft_lstadd_back. Meaning it is properly null terminated
// already. If you try and null terminate new inside this function, it will
// cause SIGFAULTS.

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (*lst == NULL) {
        *lst = new;
        new->prev = NULL;
        new->next = NULL;
        return;
    }

    last = ft_lstlast(*lst);
    last->next = new;
    new->prev = last;
    new->next = NULL;
}
