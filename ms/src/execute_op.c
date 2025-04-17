/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:08 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 16:51:08 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// triage of the builtin commands
int	execute_builtin(t_minishell *data, t_cmd *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->cmd_str, "cd", 3) == 0)
		ret = cd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd_str, "echo", 5) == 0)
		ret = echo_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd_str, "env", 4) == 0)
		ret = env_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd_str, "export", 7) == 0)
		ret = export_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd_str, "pwd", 4) == 0)
		ret = pwd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd_str, "unset", 6) == 0)
		ret = unset_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd_str, "exit", 5) == 0)
		ret = exit_builtin(data, cmd->args);
	return (ret);
}

// execute the system binary
// using the full path of the command
static int	execute_sys_bin(t_minishell *data, t_cmd *cmd)
{
	if (!cmd->cmd_str || cmd->cmd_str[0] == '\0')
		return (CMD_NOT_FOUND);
	if (cmd_is_dir(cmd->cmd_str))
		return (CMD_NOT_FOUND);
	cmd->path = get_cmd_path(data, cmd->cmd_str);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		put_errmsg("execve", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

// execute the local binary without using the path from the environment
static int	execute_local_bin(t_minishell *data, t_cmd *cmd)
{
	int	ret;

	ret = check_command_not_found(data, cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->cmd_str, cmd->args, data->env) == -1)
		return (put_errmsg("execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

// main function to execute the child process
int	child_process_exe(t_minishell *data, t_cmd *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (!cmd || !cmd->cmd_str)
		exit_ms(data, put_errmsg("child", NULL,
				"parsing error: no command to execute!", EXIT_FAILURE));
	if (!is_files_set(cmd->io_fds))
		exit_ms(data, EXIT_FAILURE);
	set_pipe_fds(data->cmd, cmd);
	redirect_io(cmd->io_fds);
	close_fds(data->cmd, false);
	if (ft_strchr(cmd->cmd_str, '/') == NULL)
	{
		ret = execute_builtin(data, cmd);
		if (ret == CMD_NOT_FOUND)
			ret = execute_sys_bin(data, cmd);
	}
	if (ret == CMD_NOT_FOUND)
		ret = execute_local_bin(data, cmd);
	exit_ms(data, ret);
	return (ret);
}
