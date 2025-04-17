/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:12 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:49:54 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// clear user input, token list and command list
void	clean_data(t_minishell *data)
{
	if (data && data->user_input)
	{
		null_free(&(data->user_input));
		data->user_input = NULL;
	}
	if (data && data->token)
		lst_clear_token(&data->token);
	if (data && data->cmd)
		lst_clear_cmd(&data->cmd, &free);
}

// close pipe file descriptors in the command list
void	close_pipe_fds(t_cmd *cmds, t_cmd *skip_cmd)
{
	while (cmds)
	{
		if (cmds != skip_cmd && cmds->pipe_fd)
		{
			close(cmds->pipe_fd[0]);
			close(cmds->pipe_fd[1]);
		}
		cmds = cmds->next;
	}
}

// close the file descriptors in the command
void	close_fds(t_cmd *cmds, bool close_backups)
{
	if (cmds->io_fds)
	{
		if (cmds->io_fds->fd_in != -1)
			close(cmds->io_fds->fd_in);
		if (cmds->io_fds->fd_out != -1)
			close(cmds->io_fds->fd_out);
		if (close_backups)
			restore_io(cmds->io_fds);
	}
	close_pipe_fds(cmds, NULL);
}

// free the io_fds structure
void	free_io(t_io_fds *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->hd_delimiter)
	{
		unlink(io->infile);
		null_free(&io->hd_delimiter);
	}
	if (io->infile)
		null_free(&io->infile);
	if (io->outfile)
		null_free(&io->outfile);
	if (io)
		free(io);
}
