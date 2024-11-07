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
# include <stdio.h> //printf
# include <stdlib.h> //free, malloc
# include "../libft/libft.h"

typedef struct s_stack_node
{
	long				num;
	long				pos;
	char				stack[2];
	int					chunk;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_node;

// Functions in my src dir
// ---  --------------------
// push_swap.c
int		chunk_size_f(t_node *lst, int chunk);

// Logicfunk
void	sort_to_b(t_node **a, t_node **b);
int		check_pb_pos(t_node **a, t_node **b, int chunk);

int		check_lg_sm(t_node *lst, int compare, int chunk, int lg_small);
void	compare_bottom_num(t_node **a, t_node **b, int chunk, int lg_sm);
void	set_big_small(t_node **lst, t_node **big, t_node **small);
void	sort3(t_node **lst);
void	sort5(t_node **a, t_node **b);

int		get_chunk_number(t_node *lst);
int		compare_holds(t_node *lst, t_node *hold_a, t_node *hold_b, int chunk_div);
t_node	*hold_first(t_node *lst, int chunk_div);
t_node	*hold_second(t_node *lst, int chunk_div);
t_node	*get_midnode(t_node **lst, int chunk);

int		order_check(t_node **lst, int chunk);
int		make_chunk_circle(t_node **lst, t_node **old_next, int chunk);
int		pb_rot_push(t_node **a, t_node **b, int chunk);
int		pb_rev_push(t_node **a, t_node **b, int chunk);
void	cut_circle(t_node **lst, t_node *old_next, int cut);

void	rot_machine(t_node **lst, int n, int print);
void	rev_machine(t_node **lst, int n, int print);

// Lstfunk
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int num, int pos, char c);

void	fill_a(t_node **lst, char **arv);
void	ft_stackposupdate(t_node *node);
void	ft_lstclear(t_node **lst);
t_node	*get_head(t_node *lst);
t_node	*ft_nodedel(t_node *node);

int		if_swap(t_node *lst, int chunk, int descending);
int		neg_lst(t_node *lst, int chunk);
int		chunk_size(t_node *lst, int chunk);
t_node	*lstlast_chunk(t_node *lst, int chunk);
t_node	*get_node(t_node *lst, int index);

t_node	*copy_lst(t_node **lst);
t_node	*copy_lst_chunk(t_node **lst, int chunk);


// Sortfunk
int		sorted_des(t_node *lst, int chunk);
int		sorted_asc(t_node *lst, t_node *start, int chunk);
void	numswap(t_node *bigger, t_node *smaller);
void	print_lstnums(t_node *a, t_node *b);
t_node	*simple_sort(t_node *lst);

// Stackfunk
void	s(t_node **lst, int print);
void	r(t_node **lst, int print);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);

void	ss(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);
void	rrs(t_node **lst, int print);
void	rrr(t_node **a, t_node **b);

// Utils
void	ft_exit(int n);
void	error_check_arv(char **arv);

#endif
