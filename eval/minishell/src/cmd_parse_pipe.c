/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:45:04 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:00:56 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// parse the pipe token
// set the pipe_output flag to true
void	parse_pipe(t_cmd **cmd_lst, t_token **token_lst)
{
	t_cmd	*last_cmd;

	last_cmd = lst_last_cmd(*cmd_lst);
	last_cmd->pipe_output = true;
	lst_add_back_cmd(&last_cmd, lst_new_command(false));
	*token_lst = (*token_lst)->next;
}
