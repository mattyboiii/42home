/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:31 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 16:46:29 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the character is a quote or not
bool	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

// check if there are quotes in the string
static bool	is_quotes_in_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			return (true);
		i++;
	}
	return (false);
}

// process the token list
// remove the quotes from the string of the token
int	handle_quotes(t_token *token)
{
	while (token)
	{
		if (is_quotes_in_string(token->str)
			&& (!token->prev || (token->prev && token->prev->type != HEREDOC)))
			remove_quotes(&token);
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
