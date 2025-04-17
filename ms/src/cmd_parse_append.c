/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:38 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:24:41 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	open_outfile(t_io_fds *io, char *file)
{
	if (remove_outfile_ref(io))
		return ;
	io->outfile = ft_strdup(file);
	if (io->outfile && io->outfile[0] == '\0' && file)
	{
		put_errmsg(file, NULL, "ambiguous redirect", EXIT_FAILURE);
		return ;
	}
	io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (io->fd_out == -1)
		put_errmsg(io->outfile, NULL, strerror(errno), EXIT_FAILURE);
}

// parse the append token
void	parse_append(t_cmd **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_cmd		*cmd;

	temp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	init_io(cmd);
	open_outfile(cmd->io_fds, temp->next->str);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}
