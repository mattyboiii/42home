/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:58:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/27 12:33:53 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h> //dup, dup2, access
# include <stdlib.h> //free, malloc
# include "../libft/libft.h"

// Functions in my pipex_utils.c
// ---  ------------------------
void	ft_exit(int n);

typedef struct s_stack_node
{
	int	num;
	int	pos;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}		node;
#endif
