/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:59 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:41:12 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// remove the old file reference
// then open the new file to a file descriptor
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
	io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io->fd_out == -1)
		put_errmsg(io->outfile, NULL, strerror(errno), EXIT_FAILURE);
}

// parse the output token
void	parse_output(t_cmd **last_cmd, t_token **token_lst)
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

// remove the old output file reference
int	remove_outfile_ref(t_io_fds *io)
{
	if (io->outfile)
	{
		if (io->fd_out == -1 || (io->infile && io->fd_in == -1))
			return (EXIT_FAILURE);
		null_free(&(io->outfile));
		close(io->fd_out);
	}
	return (EXIT_SUCCESS);
}
