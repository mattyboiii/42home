/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:19:05 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:19:41 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_base	stacks;

	stacks.head_a = NULL;
	stacks.head_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_start(&stacks.head_a, argv);
	}
	else
		stack_start(&stacks.head_a, argv + 1);
	if (!is_sorted(stacks.head_a))
	{
		if (stack_size(stacks.head_a) == 2)
			rotate_until_sorted(&stacks);
		if (stack_size(stacks.head_a) == 3)
			sort_three(&stacks);
		else
			big_sort(&stacks);
	}
	free_stack(stacks.head_a);
	free_stack(stacks.head_b);
	return (0);
}

#include <stdio.h>
#include "push_swap.h"

void print_stacks(t_stack_base stacks)
{
    t_stack_node *a = stacks.head_a;
    t_stack_node *b = stacks.head_b;
    int total_a = 0, total_b = 0;
    t_stack_node *temp;

    temp = a;
    while (temp)
    {
        total_a++;
        temp = temp->next;
    }
    temp = b;
    while (temp)
    {
        total_b++;
        temp = temp->next;
    }

    int max_lines = (total_a > 30 || total_b > 30) ? 31 : (total_a > total_b ? total_a : total_b);
    int top = (total_a > 30 || total_b > 30) ? 15 : max_lines;
    int bottom = (total_a > 30 || total_b > 30) ? 15 : (total_a > total_b ? total_a : total_b) - top;
    int i = 0;

    while (i < top)
    {
        if (a) { printf("%10d", a->data); a = a->next; }
        else printf("          ");
        if (b) { printf("     %10d", b->data); b = b->next; }
        else printf("          ");
        printf("\n");
        i++;
    }
    if (total_a > 30 || total_b > 30)
        printf("      [...]\n");
    i = 0;
    while (i < bottom)
    {
        if (total_a > 30) a = stacks.head_a;
        if (total_b > 30) b = stacks.head_b;
        int j = 0;
        while (j < (total_a - bottom + i) && a)
        {
            a = a->next;
            j++;
        }
        j = 0;
        while (j < (total_b - bottom + i) && b)
        {
            b = b->next;
            j++;
        }
        if (!a && !b) break;
        if (a) { printf("%10d", a->data); a = a->next; }
        else printf("          ");
        if (b) { printf("     %10d", b->data); b = b->next; }
        else printf("          ");
        printf("\n");
        i++;
    }
    printf("__________a     __________b\n");
}
