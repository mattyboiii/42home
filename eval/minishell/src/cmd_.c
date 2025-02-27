/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:10 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:32:37 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prep_command_without_arg(t_minishell *data)
{
	t_cmd	*cmd;

	if (!data || !data->cmd)
		return ;
	cmd = data->cmd;
	while (cmd && cmd->cmd_str)
	{
		if (!cmd->args)
		{
			cmd->args = malloc(sizeof * cmd->args * 2);
			cmd->args[0] = ft_strdup(cmd->cmd_str);
			cmd->args[1] = NULL;
		}
		cmd = cmd->next;
	}
}

void	create_cmd(t_minishell *data, t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp != NULL)
		lst_add_back_cmd(&data->cmd, lst_new_command(false));
	while (temp->next != NULL)
	{
		if (temp->type == WORD || (temp->type == VAR))
			parse_word(&data->cmd, &temp);
		else if (temp->type == INPUT)
			parse_input(&data->cmd, &temp);
		else if (temp->type == OUTPUT)
			parse_output(&data->cmd, &temp);
		else if (temp->type == HEREDOC)
			parse_heredoc(data, &data->cmd, &temp);
		else if (temp->type == APPEND)
			parse_append(&data->cmd, &temp);
		else if (temp->type == PIPE)
			parse_pipe(&data->cmd, &temp);
		else if (temp->type == END)
			break ;
	}
	prep_command_without_arg(data);
}
