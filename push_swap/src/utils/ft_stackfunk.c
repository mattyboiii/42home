/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:15:49 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/29 12:16:15 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

s_node **fill_a(int arc, char **arv)
{
    s_node **lst;
    s_node *node;
    int i;

    i = 1;
    lst = NULL;
    while (arv[i])
    {
        node = ft_lstnew(ft_atoi(arv[i]), i - 1);
        if (node == NULL)
            return (NULL);
        ft_lstadd_back(lst, node);
        i++;
    }
    return (lst);
}