/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:58:12 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/06 15:28:08 by mtripodi         ###   ########.fr       */
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

typedef struct s_stack
{
	t_node		*a;
	t_node		*b;
	int			div;
	int			asize;
	int			bsize;
}	t_stacks;

typedef struct s_holds
{
	t_node		*fh;
	t_node		*sh;
	t_node		*gold;
	t_node		*temp;
	int			iterations;
	int			ops_fh;
	int			ops_sh;
	int			ops;
	int			rotate;
	int			gold_rotate;
	int			compare;
}	t_hold;

// functions in my src dir
// ---  --------------------
// push_swap.c
int			array_size(char **arv);
void		ft_exit(int n);
void		print_stacks(t_stacks stack);

// BasicSort.c
void		set_big_small(t_node *lst, t_node **big, t_node **small);
void		sort3(t_node **lst);
void		sort5(t_stacks stack);
t_node		*get_midnode(t_node *lst);

// logicfunk
int			compare_logic(t_stacks *stack, int iterations, int skip);
int			sort_to_a(t_stacks *stack, int last_melon, int rr);
int			sort_to_b(t_stacks *stack, int iterations);
void		set_holds(t_hold *hold, t_node *gold_hold, int iterations);

// logicfunk2
int			check_lg_sm(t_node *lst, int compare, int chunk, int lg_small);
int			get_chunk_number(t_stacks stack);
int			closest_hold(t_stacks stack, t_hold *hold, int future);
t_node		*hold_first(t_stacks stack, int chunk_div, int future);
t_node		*hold_second(t_stacks stack, int chunk_div, int future);

// logicfunk3
int			rotate_prep(t_stacks stack, t_node *hold, int chunk);
int			order_rev_push(t_stacks stack, t_node **b, t_node *hold, int chunk);
int			order_rot_push(t_stacks stack, t_node **b, t_node *hold, int chunk);
int			order_check(t_node **lst);
void		check_rotate_value(t_stacks stack, t_hold *hold);

// logicfunk4
int			make_circle(t_node **lst);
void		cut_circle(t_node **lst, int cut);
int			rot_checks_rotate(t_stacks *stk, t_node *hold, int out);
int			rev_checks_rotate(t_stacks *stk, t_node *hold, int out);
int			if_push(t_stacks stack, t_node *hold);

// logicfunk5
int			pos_greater_than_ops(t_hold hold, t_node node);
int			posnum(int num);
void		rot_machine(t_node **lst, int n, int print);
void		rev_machine(t_node **lst, int n, int print);

// force_rotate
int			force_rotate_check(t_stacks stack, t_node *hold, int rotate);
int			force_loop(t_stacks stack, t_hold *hold, t_node **gold_hold,
				int loop);
int			force_rotate(t_stacks stack, t_node **fr_hold, int loop, int skip);
int			rotate_run(t_stacks *stack, t_node *hold, int rotate);
t_node		*ops_force(t_stacks stack, t_hold *hold, t_node *hold_a,
				t_node *hold_b);
// force_rotate2
int			check_rrr_rr(t_stacks stack, t_node *fr_hold, t_hold *hold);

// manual_rotate
int			least_ops_man(t_stacks stack, t_node *hold_a, t_node *hold_b,
				t_node	**gold_hold);
int			manual_loop(t_stacks stack, t_hold *hold, t_node **gold_hold,
				int loop);
int			manual_rotate(t_stacks stack, t_node **man_hold, int loop,
				int skip);
int			manual_run(t_stacks *stack, t_node *hold);

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

// lstfunk3
int			update_chunk_div(t_node *lst, int chunk_div, int chunk);
t_node		*get_node(t_node *lst, int index);
t_node		*copy_node(t_node *node);
t_node		*copy_lst(t_node *lst);

// sortfunk
int			sorted_des(t_node *lst, int chunk);
int			sorted_asc(t_node *lst, t_node *start, int chunk);
void		numswap(t_node *bigger, t_node *smaller);
t_node		*simple_sort(t_node *lst);

// stackfunk
int			r(t_node **lst, int print);
int			pa(t_stacks *stack, int print);
int			pb(t_stacks *stack, int print);
void		stacklst_del(t_stacks *stack);
t_stacks	stacklst_dup(t_stacks stack);

int			s(t_node **lst, int print);
int			ss(t_stacks *stack, int print);
int			rr(t_stacks *stack, int print);
int			rrs(t_node **lst, int print);
int			rrr(t_stacks *stack, int print);

// error_checks
void		error_check_arv(char **arv);

#endif
