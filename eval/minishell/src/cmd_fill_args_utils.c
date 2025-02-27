/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill_args_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:22 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:27:53 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// remove the empty variable arguments
void	remove_empty_var_args(t_token **tokens)
{
	t_token	*temp;
	t_token	*next_token;

	temp = *tokens;
	while (temp)
	{
		if (temp->type != VAR && temp->type != WORD)
			break ;
		next_token = temp->next;
		if (temp->type == VAR && temp->str
			&& temp->str[0] == '\0' && temp->var_exists == false)
		{
			if (temp == *tokens)
				*tokens = next_token;
			lst_delone_token(temp);
		}
		temp = next_token;
	}
}

// count the number of arguments
int	count_args(t_token *temp, bool join_flag)
{
	int	count;

	count = 0;
	while (temp && (temp->type == WORD || temp->type == VAR))
	{
		if (join_flag && temp->type == VAR && temp->join == true)
		{
			while (temp->type == VAR && temp->join == true)
				temp = temp->next;
			count++;
		}
		else
		{
			temp = temp->next;
			count++;
		}
	}
	return (count);
}

char	*join_vars(t_token **token_node)
{
	t_token	*temp;
	char	*str;

	temp = *token_node;
	str = ft_strdup(temp->str);
	while (temp->type == VAR && temp->next->type == VAR
		&& temp->next->join == true)
	{
		str = ft_strjoin(str, temp->next->str);
		temp = temp->next;
	}
	*token_node = temp;
	return (str);
}

char	**copy_to_new_arr_join(int len, char **arr, t_cmd *last_cmd,
	t_token *tmp)
{
	int	i;

	i = -1;
	while (++i < len)
		arr[i] = last_cmd->args[i];
	while (tmp && (tmp->type == WORD || tmp->type == VAR))
	{
		if (tmp->join == true)
			arr[i] = join_vars(&tmp);
		else
			arr[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	**copy_to_new_arr(int len, char **arr, t_cmd *last_cmd,
	t_token *tmp)
{
	int	i;

	i = -1;
	while (++i < len)
		arr[i] = last_cmd->args[i];
	while (tmp && (tmp->type == WORD || tmp->type == VAR))
	{
		arr[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}
