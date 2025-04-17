/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill_args_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:16 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:26:43 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_args(t_token **token, t_cmd *last_cmd)
{
	int		i;
	int		count;
	t_token	*temp;

	temp = *token;
	count = count_args(temp, false);
	last_cmd->args = malloc(sizeof(char *) * (count + 2));
	if (!last_cmd->args)
		return (EXIT_FAILURE);
	last_cmd->args[0] = ft_strdup(last_cmd->cmd_str);
	i = 1;
	while (temp->type == WORD || temp->type == VAR)
	{
		last_cmd->args[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	last_cmd->args[i] = NULL;
	*token = temp;
	return (EXIT_SUCCESS);
}

static int	add_args(t_token **token, t_cmd *last_cmd)
{
	int		count;
	int		len;
	char	**new_args;
	t_token	*temp;

	temp = *token;
	count = count_args(temp, false);
	len = dp_len(last_cmd->args);
	new_args = malloc(sizeof(char *) * (count + len + 1));
	if (!new_args)
		return (EXIT_FAILURE);
	new_args = copy_to_new_arr(len, new_args, last_cmd, temp);
	free(last_cmd->args);
	last_cmd->args = new_args;
	*token = temp;
	return (EXIT_SUCCESS);
}

static int	create_args_echo(t_token **token_node, t_cmd *last_cmd)
{
	int		count;
	t_token	*temp;
	int		i;

	remove_empty_var_args(token_node);
	temp = *token_node;
	count = count_args(temp, true);
	last_cmd->args = malloc(sizeof(char *) * (count + 2));
	if (!last_cmd->args)
		return (EXIT_FAILURE);
	last_cmd->args[0] = ft_strdup(last_cmd->cmd_str);
	i = 1;
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->join == true)
			last_cmd->args[i] = join_vars(&temp);
		else
			last_cmd->args[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	last_cmd->args[i] = NULL;
	*token_node = temp;
	return (EXIT_SUCCESS);
}

static int	add_args_echo(t_token **token_node, t_cmd *last_cmd)
{
	int		len;
	int		count;
	char	**new_args;
	t_token	*temp;

	remove_empty_var_args(token_node);
	temp = *token_node;
	count = count_args(temp, true);
	len = dp_len(last_cmd->args);
	new_args = malloc(sizeof(char *) * (count + len + 1));
	if (!new_args)
		return (EXIT_FAILURE);
	new_args = copy_to_new_arr_join(len, new_args, last_cmd, temp);
	free(last_cmd->args);
	last_cmd->args = new_args;
	while (temp->type == WORD || temp->type == VAR)
		temp = temp->next;
	*token_node = temp;
	return (EXIT_SUCCESS);
}

// fill the command arguments
// if the command is echo, use different functions
int	fill_args(t_token **token, t_cmd *last_cmd)
{
	if (!ft_strcmp(last_cmd->cmd_str, "echo"))
	{
		if (!(last_cmd->args))
			return (create_args_echo(token, last_cmd));
		else
			return (add_args_echo(token, last_cmd));
	}
	else
	{
		if (last_cmd && !(last_cmd->args))
			return (create_args(token, last_cmd));
		else
			return (add_args(token, last_cmd));
	}
	return (EXIT_SUCCESS);
}
