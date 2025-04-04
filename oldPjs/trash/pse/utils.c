/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:17:57 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:19:41 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_until_sorted(t_stack_base *lists)
{
	int				position;
	int				size;

	set_current_position(lists->head_a);
	position = (smallest_node(lists->head_a))->current_position;
	size = stack_size(lists->head_a);
	if (position == 0)
		return ;
	if (position <= size / 2)
	{
		while (position > 0)
		{
			rotate_a(lists);
			position--;
		}
	}
	else
	{
		position = size - position;
		while (position > 0)
		{
			reverse_rotate_a(lists);
			position--;
		}
	}
}

long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	correct_position(t_stack_base *lists, int num)
{
	int				smallest;
	int				largest;
	t_stack_node	*index;

	index = lists->head_a;
	smallest = find_min(lists->head_a);
	largest = find_max(lists->head_a);
	if (num <= smallest)
	{
		push_a(lists);
		return ;
	}
	if (num >= largest)
	{
		push_a(lists);
		rotate_a(lists);
		return ;
	}
	while (num >= index->data)
	{
		index = index->next;
		rotate_a(lists);
	}
	push_a(lists);
}

void	correct_push(t_stack_base *lists, int num)
{
	int				smallest;
	int				largest;
	t_stack_node	*index;

	index = lists->head_b;
	smallest = find_min(lists->head_a);
	largest = find_max(lists->head_a);
	if (num <= smallest)
	{
		push_b(lists);
		return ;
	}
	if (num >= largest)
	{
		push_b(lists);
		rotate_b(lists);
		return ;
	}
	while (num >= index->data)
	{
		index = index->next;
		rotate_b(lists);
	}
	push_b(lists);
}

int	stack_size(t_stack_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
