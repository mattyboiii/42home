/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:59:11 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:29:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lg_sm(t_node *lst, int compare, int lg_sm)
{
	t_node	*node;

	node = lst;
	if (lg_sm == 0)
	{
		while (node)
		{
			if (node->next != NULL)
				node = node->next;
			if (node && node->num < compare)
				return (1);
			node = node->next;
		}
	}
	else
	{
		while (node)
		{
			if (node->num > compare)
				return (1);
			node = node->next;
		}
	}
	return (0);
}
/*
void print_stacks(t_stacks stacks)
{
    t_node *a = stacks.a;
    t_node *b = stacks.b;
    int total_a = stacks.asize; // Use asize for stack A size
    int total_b = stacks.bsize; // Use bsize for stack B size

    int max_lines = (total_a > 30 || total_b > 30) ? 31 : (total_a > total_b ? total_a : total_b);
    int top = (total_a > 30 || total_b > 30) ? 15 : max_lines;
    int bottom = (total_a > 30 || total_b > 30) ? 15 : max_lines - top;

    // Print the top section of stacks
    int i = 0;
    while (i < top)
    {
        if (a) { printf("%10ld", a->num); a = a->next; }
        else printf("          ");
        if (b) { printf("     %10ld", b->num); b = b->next; }
        else printf("          ");
        printf("\n");
        i++;
    }

    // Print truncation indicator if stacks are too large
    if (total_a > 30 || total_b > 30)
        printf("      [...]\n");

    // Print the bottom section of stacks
    i = 0;
    while (i < bottom)
    {
        t_node *a_bottom = stacks.a;
        t_node *b_bottom = stacks.b;

        // Navigate to the starting point for printing bottom section
        int j = 0;
        while (j < (total_a - bottom + i) && a_bottom)
        {
            a_bottom = a_bottom->next;
            j++;
        }
        j = 0;
        while (j < (total_b - bottom + i) && b_bottom)
        {
            b_bottom = b_bottom->next;
            j++;
        }

        if (!a_bottom && !b_bottom) break;

        if (a_bottom) { printf("%10ld", a_bottom->num); }
        else printf("          ");
        if (b_bottom) { printf("     %10ld", b_bottom->num); }
        else printf("          ");
        printf("\n");
        i++;
    }

    // Print stack labels at the bottom with extended length for alignment
    printf("__________a     __________b\n");
}
*/
