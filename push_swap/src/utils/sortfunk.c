/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2024-09-30 12:48:08 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted_des(t_node *lst, int chunk)
{
	lst = lstlast_chunk(lst, chunk);
	if (lst == NULL)
		return (1);
	if (lst->chunk != chunk)
		return (0);
	while (lst->chunk == chunk && lst->prev != NULL)
	{
		if (lst->prev->num < lst->num)
			return (0);
		lst = lst->prev;
	}
	return (1);
}

int	sorted_asc(t_node *lst, t_node *start, int chunk)
{
	t_node	*head;

	head = lst;
	while (lst != start && lst->chunk == chunk)
		lst = lst->next;
	while (lst->next != NULL && lst->chunk == chunk)
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


void	numswap(t_node *bigger, t_node *smaller)
{
	int		swap;

	swap = bigger->num;
	bigger->num = smaller->num;
	smaller->num = swap;
}

void	print_stacks(t_stacks stack)
{
	int		a = 0;
	int		b = 0;
	int		b_nl;
	int		nl;
	int		a_empty = 2;
	int		sizea = stack.asize;
	int		sizeb = stack.bsize;
	t_node	*list_a = stack.a;
	t_node	*list_b = stack.b;


	while (list_a || list_b)
	{
		nl = 0;
		b_nl = 0;
		if (list_a)
		{
			if (sizea < 30)
				ft_printf("");
			if (list_a && (list_a->pos == 15) && !list_b)
					ft_printf("a [...]\n");
			else if (list_a && list_a->pos == 15 && list_b && sizea >= 30)
				ft_printf("a [...]      ");
			if (list_a && a > 15 && sizea > 30)
			{
				while (a < (sizea - 14))
				{
					list_a = list_a->next;
					a++;
				}
			}
			if (list_a && sizea <= 30)
			{
				// Print 'a' list
				if (a < 10)
					ft_printf("a  [%d]: %d", a, list_a->num);
				else if (a < 100)
					ft_printf("a [%d]: %d", a, list_a->num);
				else
					ft_printf("a[%d]: %d", a, list_a->num);

				// Handle spacing based on number size
				if (list_a->num < 10 && list_a->num >= 0)
					ft_printf("    ");  // 3 spaces after single digit
				else if (list_a->num < 100 && list_a->num > 0)
					ft_printf("   ");   // 2 spaces after two digits
				else if (list_a->num < 1000 && list_a->num > 0)
					ft_printf("  ");    // 1 space after three digits
				else if (list_a->num < 10000 && list_a->num > 0)
					ft_printf(" ");    // 1 space after larger numbers
				else if (list_a->num < 0 && list_a->num > -10)
					ft_printf("   ");   // 2 spaces after negative single digit
				else if (list_a->num < 0 && list_a->num > -100)
					ft_printf("  ");   // 1 space after negative two digits
				else if (list_a->num < 0 && list_a->num > -1000)
					ft_printf(" ");   // 1 space after negative three digits
			}
			else if (list_a && sizea > 30)
			{
				if (a <= 14 || a >= (sizea - 15))
				{
					// Print 'a' list
					if (a < 10)
						ft_printf("a  [%d]: %d", a, list_a->num);
					else if (a < 100)
						ft_printf("a [%d]: %d", a, list_a->num);
					else
						ft_printf("a[%d]: %d", a, list_a->num);

					// Handle spacing based on number size
					if (list_a->num < 10 && list_a->num >= 0)
						ft_printf("    ");  // 3 spaces after single digit
					else if (list_a->num < 100 && list_a->num > 0)
						ft_printf("   ");   // 2 spaces after two digits
					else if (list_a->num < 1000 && list_a->num > 0)
						ft_printf("  ");    // 1 space after three digits
					else if (list_a->num < 10000 && list_a->num > 0)
						ft_printf(" ");    // 1 space after larger numbers
					else if (list_a->num < 0 && list_a->num > -10)
						ft_printf("   ");   // 2 spaces after negative single digit
					else if (list_a->num < 0 && list_a->num > -100)
						ft_printf("  ");   // 1 space after negative two digits
					else if (list_a->num < 0 && list_a->num > -1000)
						ft_printf(" ");   // 1 space after negative three digits
				}
			}
			list_a = list_a->next;
			a++;
		}
		if (!list_b)
			nl = 1;
		if (list_b)
		{
			if (sizea == 70 && sizeb == 30)
				ft_printf("");
			if (list_b && b > 15 && sizeb > 30)
			{
				while (b < (sizeb - 14))
				{
					list_b = list_b->next;
					b++;
				}
			}
			if (!list_a)
				a_empty--;
			if (!list_a && a_empty < 1)
				ft_printf("             ");
			if (list_b && (b == 15 && sizeb >= 30))
			{
				ft_printf("-----  b [...]\n");
			}
			else if (list_b && sizeb <= 30)
			{
				if (b >= 16 && a < (sizea - 15))
					ft_printf("             ");
				// Print 'b' list
				if (b < 10)
					ft_printf("-----  b  [%d-%d]: %d", b, list_b->chunk, list_b->num);
				else if (b < 100)
					ft_printf("-----  b [%d-%d]: %d", b, list_b->chunk, list_b->num);
				else
					ft_printf("-----  b[%d-%d]: %d", b, list_b->chunk, list_b->num);
					b_nl = 1;
			}
			else if (list_b && sizeb > 30)
			{
				if (b <= 14 || b > (sizeb - 15))
				{
					// Print 'b' list
					if (b < 10)
						ft_printf("-----  b  [%d-%d]: %d", b, list_b->chunk, list_b->num);
					else if (b < 100)
						ft_printf("-----  b [%d-%d]: %d", b, list_b->chunk, list_b->num);
					else
						ft_printf("-----  b[%d-%d]: %d", b, list_b->chunk, list_b->num);
					b_nl = 1;
				}
			}
			list_b = list_b->next;
			b++;
		}
		if (b >= 16 && (a <= 15 || a > (sizea - 15)))
			ft_printf("");
		if (a > 15 && b > 15 && sizeb >= 29)
			ft_printf("");
		if (b_nl == 1 || (nl == 1 && (a <= 15 || a > (sizea - 15))))
			ft_printf("\n");
	}
	ft_printf("\n");
}

t_node	*simple_sort(t_node *lst)
{
	t_node	*current;
	t_node	*next_node;
	t_node	*head;

	head = lst;
	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->num > next_node->num)
				numswap(current, next_node);
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (head);
}
