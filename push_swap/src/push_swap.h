/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:58:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/29 12:15:18 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h> //dup, dup2, access
# include <stdlib.h> //free, malloc
# include "../ps_libft/libft.h"

typedef struct s_stack_node
{
	long				num;
	long				pos;
	char				stack[2];
	struct s_stack_node	**head;
	struct s_stack_node	**foot;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_node;

// Functions in my utils dir
// ---  --------------------
void	ft_exit(int n);
void	error_check_arv(char **arv);

void	sort3(t_node **a);

void	s(t_node **lst, int print);
void	r(t_node **lst, int print);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);

void	check_logic(char *cur_act);
void	ss(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);
void	rrs(t_node **lst, int print);
void	rrr(t_node **a, t_node **b);

t_node	*get_head(t_node *lst);
void	fill_a(t_node **lst, char **arv);
t_node	*ft_nodedel(t_node *node);
void	ft_stackposupdate(t_node *node);
t_node	*get_node(t_node *lst, int index);

void	numswap(t_node *bigger, t_node *smaller);
int		is_sorted(t_node *lst, t_node *start, t_node *stop);
t_node	*simple_sort(t_node *lst);
t_node	*quicksort(t_node *lst, t_node *pivot, t_node *prev_pivot,
			t_node *start, t_node *stop);
void	quicksort_pivot(t_node *lst, t_node *start, t_node *prev_pivot);
void	print_lstnums(t_node *lst);

t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int num, int pos, char c);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
// t_node	*copy_addback(t_node **lst, t_node *node);

#endif
