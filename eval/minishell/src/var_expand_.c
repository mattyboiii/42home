/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:30 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:49:40 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// update the token string with the variable value
static int	update_var_str(t_token **token, char *str, char *value, int index)
{
	char	*new_str;
	int		new_size;

	if (value == NULL)
	{
		new_size = ft_strlen(str) - var_length(str + index);
		new_str = get_new_string(str, "", new_size, index);
	}
	else
	{
		new_size = ft_strlen(str) - var_length(str + index) + ft_strlen(value);
		new_str = get_new_string(str, value, new_size, index);
	}
	if (!new_str)
		return (EXIT_FAILURE);
	ft_free((*token)->str);
	(*token)->str = new_str;
	return (EXIT_SUCCESS);
}

// expand the variable in the token
int	expand_var_token(t_token **token, char *value, int index)
{
	if (update_var_str(token, (*token)->str, value, index))
	{
		ft_free(value);
		return (EXIT_FAILURE);
	}
	ft_free(value);
	return (EXIT_SUCCESS);
}

// expand the variable in the heredoc
char	*expand_var_heredoc(char *str, char *value, int index)
{
	char	*new_str;
	int		new_size;

	if (!value)
	{
		*str = '\0';
		return (str);
	}
	new_size = ft_strlen(str) - var_length(str + index) + ft_strlen(value);
	new_str = get_new_string(str, value, new_size, index);
	if (!new_str)
	{
		ft_free(value);
		return (NULL);
	}
	ft_free(str);
	ft_free(value);
	return (new_str);
}
