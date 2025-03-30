/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:56:54 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/06 12:42:34 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int n)
{
	if (n == 0)
		exit(0);
	if (n == 6)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
}

int	array_size(char **arv)
{
	int		i;

	i = 0;
	while (arv[i])
		i++;
	return (i);
}

int	set_iterations(int	size)
{
	if (size <= 100)
		return (10);
	else
		return (5);
}
int	main(int arc, char **arv)
{
	t_stacks	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	error_check_arv(arv);
	fill_a(&stack, arv);
	if (stack.asize <= 1)
		exit(0);
	if (sorted_asc(stack.a, stack.a) == 1)
		return (0);
	else if (stack.asize <= 3)
		sort3(&stack.a);
	else
		sort(&stack);
	ft_lstclear(&stack.a);
	ft_lstclear(&stack.b);
	return (0);
}

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
