/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:14 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:29:10 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack_node **a)
{
	ssize_t	bytes_written;

	free_stack(*a);
	bytes_written = write(2, "Error\n", 6);
	(void)bytes_written;
	exit(1);
}

int	checkdup(t_stack_node *head_a)
{
	t_stack_node	*tmp;

	while (head_a)
	{
		tmp = head_a->next;
		while (tmp)
		{
			if (head_a->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		head_a = head_a->next;
	}
	return (0);
}

int	invalid_input_check(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	is_sorted(t_stack_node *head_a)
{
	t_stack_node	*temp;

	temp = head_a;
	if (!head_a)
		return (1);
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
