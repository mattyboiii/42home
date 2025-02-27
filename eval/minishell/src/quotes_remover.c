/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:38 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 16:44:47 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// count the length of the string without quotes
// plus one for the null terminator
static int	strlen_without_quotes(char *str)
{
	int	status;
	int	count;
	int	i;

	count = 0;
	i = -1;
	status = DEFAULT;
	while (str[++i])
	{
		if (status == DEFAULT)
		{
			if (str[i] == '\'')
				status = SQUOTE;
			else if (str[i] == '\"')
				status = DQUOTE;
			else
				count++;
		}
		else if ((str[i] == '\'' && status == SQUOTE)
			|| (str[i] == '\"' && status == DQUOTE))
			status = DEFAULT;
		else
			count++;
	}
	return (count + 1);
}

// change the quoting status of the token 
// depending on the current character 
static void	change_status_to_quote(t_token **tk, int *i)
{
	if ((*tk)->str[*i] == '\'')
		(*tk)->quoting = SQUOTE;
	else if ((*tk)->str[*i] == '\"')
		(*tk)->quoting = DQUOTE;
	(*i)++;
}

// check if the current character is a quote
// and the quoting status is DEFAULT
static bool	if_quotes_and_default(t_token **tk, int i)
{
	if ((is_quote((*tk)->str[i])) && (*tk)->quoting == DEFAULT)
		return (true);
	else
		return (false);
}

// change the quoting status back to DEFAULT
// if the current character is the same as the quoting status
// meaning the quote is closed correctly
static bool	change_back_to_default(t_token **tk, int *i)
{
	if (((*tk)->str[*i] == '\'' && (*tk)->quoting == SQUOTE)
		|| ((*tk)->str[*i] == '\"' && (*tk)->quoting == DQUOTE))
	{
		(*tk)->quoting = DEFAULT;
		(*i)++;
		return (true);
	}
	else
		return (false);
}

// remove quotes from the string in one token
// the if condition is too long, so created separate functions for them
int	remove_quotes(t_token **token)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * strlen_without_quotes((*token)->str));
	if (!new_str)
		return (EXIT_FAILURE);
	while ((*token)->str[i])
	{
		if (if_quotes_and_default(token, i))
		{
			change_status_to_quote(token, &i);
			continue ;
		}
		else if (change_back_to_default(token, &i))
			continue ;
		new_str[j++] = (*token)->str[i++];
	}
	new_str[j] = '\0';
	ft_free((*token)->str);
	(*token)->str = new_str;
	(*token)->join = true;
	return (EXIT_SUCCESS);
}
