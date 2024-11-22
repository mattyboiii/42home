/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 03:50:43 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-05 03:50:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	if_push(t_stacks stack, t_node *hold)
{
	t_stacks	stack_temp;

	if (stack.b == NULL || stack.b->next == NULL)
		return (1);
	stack_temp.a = copy_lst(stack.b);
	stack_temp.b = copy_node(hold);
	pb(&stack_temp, 0);

	if (order_check(&stack_temp.a, stack.a->chunk) == 1)
	{
		ft_lstclear(&stack_temp.a);
		ft_lstclear(&stack_temp.b);
		return (1);
	}
	else
	{
		ft_lstclear(&stack_temp.a);
		ft_lstclear(&stack_temp.b);
		return (0);
	}
}

// counts the numbers at the bottom of b with the current chunk
int		n_chunk_bot(t_node *b, int	chunk)
{
	int		count;
	t_node	*last;

	last = ft_lstlast(b);
	count = 0;
	if (!b || chunk == 1)
		return (0);
	while(last && last->chunk == chunk)
	{
		count++;
		last = last->prev;
	}
	return (count);
}

int		rot_large(t_node **b, t_node *hold, int chunk)
{
	int		num;
	int		rotate;

	num = hold->num;
	rotate = 0;
	while ((*b)->num > num)
	{
		r(b, 1);
		rotate++;
	}
	return (rotate);
}

void	rot_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		r(lst, print);
		n--;
	}
}

void	rev_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		rrs(lst, print);
		n--;
	}
}
