/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:45:55 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 22:36:35 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// get the status (exit code) of the child process
static int	child_process_status(t_minishell *data)
{
	pid_t	wpid;
	int		status;
	int		save_status;

	close_fds(data->cmd, false);
	save_status = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == data->pid)
			save_status = status;
		continue ;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	return (status);
}

// create the child process for the commands
static int	create_children(t_minishell *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	while (data->pid != 0 && cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (put_errmsg("fork", NULL, strerror(errno), EXIT_FAILURE));
		else if (data->pid == 0)
			child_process_exe(data, cmd);
		cmd = cmd->next;
	}
	return (child_process_status(data));
}

// prepare for the execution of the command
static int	prep_for_exec(t_minishell *data)
{
	if (!data || !data->cmd)
		return (EXIT_SUCCESS);
	if (!data->cmd->cmd_str)
	{
		if (data->cmd->io_fds && !is_files_set(data->cmd->io_fds))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (create_pipes(data))
		return (EXIT_FAILURE);
	return (CMD_NOT_FOUND);
}

// main function to execute the command
int	execute(t_minishell *data)
{
	int	ret;

	ret = prep_for_exec(data);
	if (ret != CMD_NOT_FOUND)
		return (ret);
	if (!data->cmd->pipe_output && !data->cmd->prev
		&& is_files_set(data->cmd->io_fds))
	{
		redirect_io(data->cmd->io_fds);
		ret = execute_builtin(data, data->cmd);
		restore_io(data->cmd->io_fds);
	}
	if (ret != CMD_NOT_FOUND)
		return (ret);
	return (create_children(data));
}
