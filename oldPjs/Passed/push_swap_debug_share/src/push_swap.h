/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 01:15:25 by mtripodi          #+#    #+#             */
/*   Updated: 2025-03-30 01:15:25 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h> //write
# include <stdio.h>
# include <stdlib.h> //free, malloc
# include <stdbool.h> //bool
# include <limits.h> //LONG_MAX
# include "../libft/libft.h"

typedef struct s_stack_node
{
	long				num;
	long				pos;
	int					push_price;
	struct s_stack_node	*target;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	bool				mid_h;
	char				stack[2];
}	t_node;

typedef struct s_stack
{
	t_node		*a;
	t_node		*b;
	int			asize;
	int			bsize;
	int			bigdig;
}	t_stacks;

// functions in my src dir
// ---  --------------------

// BasicSort.c
t_node		*get_smallest(t_node *lst);
void		set_big_small(t_node *lst, t_node **big, t_node **small);
void		sort3(t_node **lst);

// error_checks
void		error_check_arv(char **arv);

// lstfunk
int			ft_lstsize(t_node *lst);
void		ft_lstadd_front(t_node **lst, t_node *new);
void		ft_lstadd_back(t_node **lst, t_node *new);
t_node		*ft_lstlast(t_node *lst);
t_node		*ft_lstnew(int num, char c);

// lstfunk2
void		fill_a(t_stacks *stack, char **arv);
void		ft_stackposupdate(t_node *node);
void		ft_lstclear(t_node **lst);
t_node		*ft_nodedel(t_node *node);

// push_swap.c
int			sorted_asc(t_node *lst, t_node *start);
void		ft_exit(int n);
/*			int main(int arc, char **arv) */

// rot_rev_push.c
void		force_rot_push(t_stacks *stack, t_node *push);
void		force_rev_push(t_stacks *stack, t_node *push);
void		man_push(t_stacks *stack, t_node *push);
void		push_cheapest(t_stacks *stack, t_node *cheap);
void		smallest_on_top(t_stacks *stack);

// rot_rev_push2.c
void		set_rr_rrr_push_price(t_stacks stack, t_node *b);
void		rot_machine(t_node **lst, int n, int print);
void		rev_machine(t_node **lst, int n, int print);

// sort.c
void		sort(t_stacks *stack);
void		set_targets(t_node *a, t_node *b);
void		set_mid_h(t_stacks *stack);
void		set_push_price(t_stacks *stack);

// stackfunk.c
int			r(t_node **lst, int print);
int			pa(t_stacks *stack, int print);
int			pb(t_stacks *stack, int print);

// stackfunk2.c
int			s(t_node **lst, int print);
int			ss(t_stacks *stack, int print);
int			rr(t_stacks *stack, int print);
int			rrs(t_node **lst, int print);
int			rrr(t_stacks *stack, int print);
// utils
t_node		*get_node(t_node *lst, int index);
int			set_bigdig(t_stacks *stack);
int			posnum(int num);
void		print_stacks(t_stacks *stack);

#endif
