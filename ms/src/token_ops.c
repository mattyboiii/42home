/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:08 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:47:09 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// save a separator token
int	save_separator(t_token **token_lst, char *str, int index, int type)
{
	int		i;
	char	*sep;

	i = 0;
	if (type == APPEND || type == HEREDOC)
	{
		sep = malloc(sizeof(char) * 3);
		if (!sep)
			return (EXIT_FAILURE);
		while (i < 2)
			sep[i++] = str[index++];
		sep[i] = '\0';
		lst_add_back_token(token_lst, lst_new_token(sep, type, DEFAULT));
	}
	else
	{
		sep = malloc(sizeof(char) * 2);
		if (!sep)
			return (EXIT_FAILURE);
		while (i < 1)
			sep[i++] = str[index++];
		sep[i] = '\0';
		lst_add_back_token(token_lst, lst_new_token(sep, type, DEFAULT));
	}
	return (EXIT_SUCCESS);
}

// save a word token
int	save_word(t_token **token_lst, char *str, int index, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (EXIT_FAILURE);
	while (start < index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	lst_add_back_token(token_lst, lst_new_token(word, WORD, DEFAULT));
	return (EXIT_SUCCESS);
}

// check if the character is a separator
static int	is_separator(char *str, int i)
{
	if (ft_isspace(str[i]))
		return (SPACES);
	else if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (APPEND);
	else if (str[i] == '<')
		return (INPUT);
	else if (str[i] == '>')
		return (OUTPUT);
	else if (str[i] == '\0')
		return (END);
	else
		return (EXIT_SUCCESS);
}

// set the quote status based on the character
int	set_quote_status(int status, char *str)
{
	if (*str == '\'' && status == DEFAULT)
		status = SQUOTE;
	else if (*str == '\"' && status == DEFAULT)
		status = DQUOTE;
	else if (*str == '\'' && status == SQUOTE)
		status = DEFAULT;
	else if (*str == '\"' && status == DQUOTE)
		status = DEFAULT;
	return (status);
}

// save a token
// move the index while save the token
int	save_token(int *i, char *str, int start, t_minishell *data)
{
	int	type;

	type = is_separator(str, (*i));
	if (type)
	{
		if ((*i) != 0 && is_separator(str, (*i) - 1) == 0)
			save_word(&data->token, str, (*i), start);
		if (type == APPEND || type == HEREDOC || type == PIPE
			|| type == INPUT || type == OUTPUT || type == END)
		{
			save_separator(&data->token, str, (*i), type);
			if (type == APPEND || type == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}
