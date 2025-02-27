/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:57 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:46:58 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if this token is consecutive with the previous one
static bool	is_consecutive(t_token *token_node)
{
	if (token_node->prev)
	{
		if (token_node->type == PIPE && token_node->prev->type == PIPE)
			return (true);
		if (token_node->type > PIPE && token_node->prev->type > PIPE)
			return (true);
		if (token_node->type == END && token_node->prev->type >= PIPE)
			return (true);
	}
	return (false);
}

// check if there are consecutive tokens
int	check_consecutives(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	while (temp)
	{
		if (is_consecutive(temp))
		{
			if (temp->type == END && temp->prev && temp->prev->type > PIPE)
				put_errmsg(NULL, "syntax error near unexpected token",
					"newline", EXIT_FAILURE);
			else if (temp->type == END && temp->prev)
				put_errmsg(NULL, "syntax error near unexpected token",
					temp->prev->str, EXIT_FAILURE);
			else
				put_errmsg(NULL, "syntax error near unexpected token",
					temp->str, EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}

// set the token type to VAR if it contains a '$'
static void	set_token_type_var(t_token **token_node)
{
	int	i;

	i = 0;
	while ((*token_node)->str[i])
	{
		if ((*token_node)->str[i] == '$')
		{
			if ((*token_node)->prev && (*token_node)->prev->type == HEREDOC)
				break ;
			(*token_node)->type = VAR;
			return ;
		}
		i++;
	}
}

// check if there are variables in the tokens
// and check if there are consecutive tokens
int	check_if_var(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	if (temp->type == PIPE)
		return (put_errmsg(NULL, "syntax error near unexpected token",
				temp->str, EXIT_FAILURE));
	while (temp)
	{
		set_token_type_var(&temp);
		if (check_consecutives(&temp))
			return (EXIT_FAILURE);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
