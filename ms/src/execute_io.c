/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:02 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:17:26 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// restore the standard input and output from the backup
void	restore_io(t_io_fds *io)
{
	if (!io)
		return ;
	if (io->stdin_backup != -1)
	{
		dup2(io->stdin_backup, STDIN_FILENO);
		close(io->stdin_backup);
		io->stdin_backup = -1;
	}
	if (io->stdout_backup != -1)
	{
		dup2(io->stdout_backup, STDOUT_FILENO);
		close(io->stdout_backup);
		io->stdout_backup = -1;
	}
}

// set the fd_in and fd_out to the standard input and output
void	redirect_io(t_io_fds *io)
{
	if (!io)
		return ;
	io->stdin_backup = dup(STDIN_FILENO);
	if (io->stdin_backup == -1)
		put_errmsg("dup", "stdin backup", strerror(errno), EXIT_FAILURE);
	io->stdout_backup = dup(STDOUT_FILENO);
	if (io->stdout_backup == -1)
		put_errmsg("dup", "stdout backup", strerror(errno), EXIT_FAILURE);
	if (io->fd_in != -1 && dup2(io->fd_in, STDIN_FILENO) == -1)
		put_errmsg("dup2", io->infile, strerror(errno), EXIT_FAILURE);
	if (io->fd_out != -1 && dup2(io->fd_out, STDOUT_FILENO) == -1)
		put_errmsg("dup2", io->outfile, strerror(errno), EXIT_FAILURE);
}

// check if the input and output files are set
bool	is_files_set(t_io_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (true);
	if ((io->infile && io->fd_in == -1)
		|| (io->outfile && io->fd_out == -1))
		return (false);
	return (true);
}

// create the pipe fds for the commands in the list
int	create_pipes(t_minishell *data)
{
	int			*fd;
	t_cmd		*tmp;

	tmp = data->cmd;
	while (tmp)
	{
		if (tmp->pipe_output || (tmp->prev && tmp->prev->pipe_output))
		{
			fd = malloc(sizeof(int) * 2);
			if (!fd || pipe(fd) != 0)
			{
				clean_data(data);
				return (EXIT_FAILURE);
			}
			tmp->pipe_fd = fd;
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

// fd[0] is for reading, fd[1] is for writing
void	set_pipe_fds(t_cmd *cmds, t_cmd *c)
{
	if (c->prev && c->prev->pipe_output)
		dup2(c->prev->pipe_fd[0], STDIN_FILENO);
	if (c->pipe_output)
		dup2(c->pipe_fd[1], STDOUT_FILENO);
	close_pipe_fds(cmds, c);
}
