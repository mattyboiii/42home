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

/* this print function was used to display the code
*/
void	print_stacks2(t_stacks *stack)
{
	int		a = 0;
	int		b = 0;
	int		b_nl;
	int		nl;
	int		a_empty = 2;
	int		sizea = stack->asize;
	int		sizeb = stack->bsize;
	t_node	*list_a = stack->a;
	t_node	*list_b = stack->b;


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
						ft_printf("   ");   // 2 spaces after negative single di
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
					ft_printf("-----  b  [%d]: %d", b,
							list_b->num);
				else if (b < 100)
					ft_printf("-----  b [%d]: %d", b,
							list_b->num);
				else
					ft_printf("-----  b[%d]: %d", b,
							list_b->num);
				b_nl = 1;
			}
			else if (list_b && sizeb > 30)
			{
				if (b <= 14 || b > (sizeb - 15))
				{
					// Print 'b' list
					if (b < 10)
						ft_printf("-----  b  [%d]: %d", b,
							list_b->num);
					else if (b < 100)
						ft_printf("-----  b [%d]: %d", b,
							list_b->num);
					else
						ft_printf("-----  b[%d]: %d", b,
							list_b->num);
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
