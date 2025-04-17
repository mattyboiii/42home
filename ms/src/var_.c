/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:23 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:47:24 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if the next character is a valid variable character
static bool	check_next(char c)
{
	if (c == '$' || c == ' ' || c == '=' || c == '\0')
		return (true);
	else
		return (false);
}

// All because of this if(i>0)!!!
static bool	var_between_dquotes(char *str, int i)
{
	if (i > 0)
	{
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (true);
		else
			return (false);
	}
	return (false);
}

// Expand the variable in the token
int	handle_variable(t_minishell *data, t_token **token_lst)
{
	t_token	*temp;
	int		i;

	temp = *token_lst;
	while (temp)
	{
		if (temp->type == VAR)
		{
			i = 0;
			while (temp->str[i])
			{
				temp->quoting = set_quote_status(temp->quoting, temp->str + i);
				if (temp->str[i] == '$'
					&& !(check_next(temp->str[i + 1]))
					&& !(var_between_dquotes(temp->str, i))
					&& (temp->quoting == DEFAULT || temp->quoting == DQUOTE))
					expand_var_token(&temp,
						get_var_value(temp, temp->str + i, data), i);
				else
					i++;
			}
		}
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}

// Expand the variable in the heredoc
char	*handle_variable_heredoc(t_minishell *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && !(check_next(str[i + 1]))
			&& !(var_between_dquotes(str, i)))
			str = expand_var_heredoc(str,
					get_var_value(NULL, str + i, data), i);
		else
			i++;
	}
	return (str);
}
