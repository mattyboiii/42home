/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:56:54 by mtripodi          #+#    #+#             */
/*   Updated: 2025/04/01 09:54:51 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief loops through the lst, comparing the number which appears after
 * to the current number. If the next number is bigger, it will return 0.
 * meaning the lst is not sorted in ascending order.
 *
 * @return int 1 = sorted, 0 = not sorted.
 */
int	sorted_asc(t_node *lst, t_node *start)
{
	t_node	*head;

	head = lst;
	while (lst != start)
		lst = lst->next;
	while (lst->next != NULL)
	{
		if (lst->num > lst->next->num)
		{
			lst = head;
			return (0);
		}
		lst = lst->next;
	}
	lst = head;
	return (1);
}

/**
 * @brief handing in 0 will exit(0) handing in 6 will exit with
 * an "Error" message. I use this function to differnciate when I want the
 * Error message to appear.
 */
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

/**
 * main function controlls the program in the following order.
 * 1. creats the stack.
 * 2. checks if enough arguments have been given, then applys the arguments
 * to arv using ft_split.
 * 3. checks for errors in arguments.
 * 4. fills the stack.a with nodes whos number matches the argumentsassuming
 * program hasnt exited in error_check_arv();
 * 5. finds the number with the most digits, and applys it to stack.bigdig.
 * 6. checks if stack is less than 1
 * 7. checks if the stack is sorted already
 * 8. if stack is size 3, runs sort3
 * 9. runs "sort" on the &stack. To initiate the logic
 * 10. Clears and exits program.
 *
 * step 5 -- STACK.BIGDIG is only used in print_stacks() function, which is
 * used when debugging. print_stacks() is most likely commented out in utils.c
 */
int	main(int arc, char **arv)
{
	t_stacks	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	error_check_arv(arv);
	fill_a(&stack, arv);
	if (arc >= 2)
		dp_free(&arv);
	stack.bigdig = set_bigdig(&stack);
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
