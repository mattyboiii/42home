/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 03:50:43 by mtripodi          #+#    #+#             */
/*   Updated: 2025/03/07 13:01:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posnum(int num)
{
	if (num < 0)
		return (num *= -1);
	else
		return (num);
}

/**
 * @brief this function is used to get the number of digits, for the
 * number with the most digits. I use it in the print_stacks. So assuming
 * the project is working, this bigdig num wont actually get used and may
 * not be in the main function (which is the only place I use it)
 */
int		set_bigdig(t_stacks *stack)
{
	t_node		*big;
	t_node		*small;
	int			bignum;
	int			smallnum;
	int			i;

	i = 0;
	set_big_small(stack->a, &big, &small);
	if (big->num < 0 && small->num < 0)
		i = 1;
	bignum = posnum(big->num);
	smallnum = posnum(small->num);
	if (bignum < smallnum)
	{
		if (small->num < 0)
			i = 1;
		bignum = smallnum;
	}
	while (bignum >= 10)
	{
		i++;
		bignum /= 10;
	}
	return (i);
}


/**
 * @brief this funciton simply prints out both stacks in a nice format which
 * also shows their position
 */
void print_stacks(t_stacks *stack)
{
    int num_width = stack->bigdig + 1;     // Include space for negative sign
    int a_col_width = 10 + stack->bigdig;  // Width for "a [X]: " + number
	int	sizea = stack->asize;
	int	sizeb = stack->bsize;
	int	top = 15;
	int	abot = sizea - 15;
	int	bbot = sizeb - 15;
    t_node *list_a = stack->a;
    t_node *list_b = stack->b;

    while (list_a || list_b)
    {
        // Print Stack A entry
        if (list_a && (list_a->pos <= top || list_a->pos >= abot))
            printf("a [%3ld]: %*ld", list_a->pos, num_width, list_a->num);
		else if (list_a && list_a->pos == 16)
            printf("%*s", num_width + 9, "[...]");
        else if (list_b && (list_b->pos <= top + 1 || list_b->pos >= bbot))
            printf("%*s", a_col_width, ""); // Blank space if no more elements in A
		if (list_a)
        	list_a = list_a->next;
        if (list_b && (list_b->pos <= top + 1 || list_b->pos >= bbot))
		{
			while (list_a && list_a->pos < abot)
			//make list_a go straight to the number where it can print.
			//fuck it make both go straight to the list it can print. 
		}

        // Print separator
        if (list_b && (list_b->pos <= top + 1 || list_b->pos >= bbot))
        	printf("  -----  ");

        // Print Stack B entry
        if (list_b && (list_b->pos <= top || list_b->pos >= bbot))
            printf("b [%3ld]: %*ld\n", list_b->pos, num_width, list_b->num);
		else if (list_b && list_b->pos == 16)
            printf("%*s\n", num_width + 9, "[...]");
        else if (list_b && (list_b->pos <= top || list_b->pos >= bbot))
            printf("\n");
		if (list_b)
        	list_b = list_b->next;
    }
}
