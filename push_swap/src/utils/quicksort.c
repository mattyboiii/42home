/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2024-09-30 12:48:08 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	is_sorted(int *array, int start, int size)
{
	int		i;

	if (size == start)
		return (1);
	i = start;
	if (size <= 1)
		return (1);
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*node_to_array(t_node *lst)
{
	int		i;
	int		*numa;
	t_node	*head;

	if (lst == NULL)
		return (NULL);
	head = lst;
	numa = malloc(sizeof(int) * ((ft_lstlast(lst))->pos + 1));
	i = 0;
	while (lst)
	{
		numa[i] = lst->num;
		i++;
		lst = lst->next;
	}
	lst = head;
	return (numa);
}

void	numswap(int *big, int *small)
{
	int		swap;

	swap = *big;
	*big = *small;
	*small = swap;
}

void	print_array(int *array, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_printf("numa[%d] = %d\n", i, array[i]);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int	*quicksort(int *numa, int size, int pivot)
{
	int		i;
	int		big;

	i = 0;
	big = 0;
	if (pivot == 0)
		pivot = numa[size - 1];
	print_array(numa, size);
	while (i < size - 1)
	{
		if (numa[i] < pivot)
		{
			numswap(&numa[big], &numa[i]);
			big++;
			print_array(numa, size);
		}
		i++;
	}
	if (numa[big] > pivot)
		numswap(&numa[big], &numa[size - 1]);
	if (numa[big] == numa[0])
		big++;
	print_array(numa, size);
	while (is_sorted(numa, 0, size) == 0)
		quicksort_pivot(numa, size, numa[big]);
	return (numa);
}

void	short_sort(int *numa, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (numa[j] > numa[j + 1])
			{
				temp = numa[j];
				numa[j] = numa[j + 1];
				numa[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}


void	quicksort_pivot(int *numa, int size, int pivot)
{
	int		i;
	int		newp;

	if (numa[size - 1] == pivot)
		pivot = numa[size / 2];
	i = 0;
	while (numa[i] != pivot)
		i++;
	if (i < 5)
		short_sort(numa, size);
	if(is_sorted(
	{
			newp = numa[i / 2];
			numa = quicksort(numa, i, newp);
	}
}
