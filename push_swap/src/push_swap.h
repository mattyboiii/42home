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
	int					num;
	int					pos;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_node;

// Functions in my utils dir
// ---  --------------------
void	ft_exit(int n);

void	sa(t_node *node);
void	ra(t_node *node);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

t_node	*ft_nodedel(t_node *node);
void	ft_stackposupdate(t_node *node);

t_node	*fill_a(char **arv);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int num, int pos);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

#endif
