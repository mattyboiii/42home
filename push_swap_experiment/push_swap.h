/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:08 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 15:14:50 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack_node
{
	int					data;
	struct t_stack_node	*next;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct t_stack_node	*target_node;
	struct t_stack_node	*prev;
}						t_stack_node;

typedef struct t_stack_base
{
	t_stack_node		*head_a;
	t_stack_node		*head_b;
}						t_stack_base;

void					print_stacks(t_stack_base stack);
//linked_list.c
t_stack_node			*create_node(int data);
void					append(t_stack_node **head, int data);
void					print_stack(t_stack_node *head, char stack_name);
void					free_stack(t_stack_node *head);
void					set_current_position(t_stack_node *head);

//linked_list_three
void					set_cheapest(t_stack_node *head);

void					rotate_target_to_top(t_stack_base *lists,
							t_stack_node *target);
void					rotate_b_to_top(t_stack_base *lists, int position,
							int size);
//linked_list_two
void					push_cheapest(t_stack_base *lists);
void					sort_three(t_stack_base *lists);
void					sort_five(t_stack_base *lists);
void					big_sort(t_stack_base *lists);
void					prepare_stack_a(t_stack_base *lists, int best_number);
void					push(t_stack_node **src, t_stack_node **dest);
void					push_b(t_stack_base *lists);
void					push_a(t_stack_base *lists);
void					swap_sa(t_stack_node *head);
void					reverse_rotate_a(t_stack_base *lists);
void					reverse_rotate_b(t_stack_base *lists);
void					rotate_a(t_stack_base *lists);
void					rotate_b(t_stack_base *lists);
void					rr(t_stack_base *lists);
void					rrr(t_stack_base *lists);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
char					**ft_split(char const *s, char c);
void					ft_putstr(char *str);
void					rotate_until_sorted(t_stack_base *lists);
long					ft_atol(const char *str);
int						ft_isdigit(int c);
void					correct_position(t_stack_base *lists, int num);
int						find_min(t_stack_node *head);
int						find_max(t_stack_node *head);
void					correct_push(t_stack_base *lists, int num);
int						stack_size(t_stack_node *head);
//mass_sort.c
void					find_target_node(t_stack_node *head_a,
							t_stack_node *head_b);
t_stack_node			*smallest_node(t_stack_node *head);
void					calculate_push_price(t_stack_node *a, t_stack_node *b);
int						checkdup(t_stack_node *head_a);
void					error_exit(t_stack_node **a);
int						invalid_input_check(char *str_nbr);
int						is_sorted(t_stack_node *head_a);
void					stack_start(t_stack_node **a, char **argv);
int						count_words(const char *str, char c);
char					*word_dup(const char *str, int start, int finish);
void					rotate_both(t_stack_base *l, t_stack_node *c,
							t_stack_node *t);
void					while_a(t_stack_base *l, t_stack_node *t, int ca);
void					while_b(t_stack_base *l, t_stack_node *t, int cb);

#endif
