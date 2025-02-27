/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:13 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 16:49:11 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the command is a directory
bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

// check if the command is ok or not
// return the error message and number respectively
int	check_command_not_found(t_minishell *data, t_cmd *cmd)
{
	if (!ft_strchr(cmd->cmd_str, '/') && env_var_index(data->env, "PATH") != -1)
		return (put_errmsg(cmd->cmd_str, NULL, "command not found",
				CMD_NOT_FOUND));
	if (cmd_is_dir(cmd->cmd_str))
		return (put_errmsg(cmd->cmd_str, NULL, "is a directory",
				CMD_NOT_EXECUTABLE));
	if (access(cmd->cmd_str, F_OK) != 0)
		return (put_errmsg(cmd->cmd_str, NULL, strerror(errno),
				CMD_NOT_FOUND));
	if (access(cmd->cmd_str, X_OK) != 0)
		return (put_errmsg(cmd->cmd_str, NULL, strerror(errno),
				CMD_NOT_EXECUTABLE));
	return (EXIT_SUCCESS);
}

// loop through the paths and find the executable path
static char	*find_executable_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		ft_free(cmd_path);
	}
	return (NULL);
}

// get the paths from the environment variable list
// paths are separated by ':'
static char	**get_paths_from_env(t_minishell *data)
{
	char	**env_paths;

	if (env_var_index(data->env, "PATH") == -1)
		return (NULL);
	env_paths = ft_split(env_var_value(data->env, "PATH"), ':');
	if (!env_paths)
		return (NULL);
	return (env_paths);
}

// get the full path of the command
char	*get_cmd_path(t_minishell *data, char *name)
{
	char	**env_paths;
	char	*cmd;
	char	*cmd_path;

	env_paths = get_paths_from_env(data);
	if (!env_paths)
		return (NULL);
	cmd = ft_strjoin("/", name);
	if (!cmd)
	{
		ft_free_str2d(env_paths);
		return (NULL);
	}
	cmd_path = find_executable_path(cmd, env_paths);
	if (!cmd_path)
	{
		ft_free(cmd);
		ft_free_str2d(env_paths);
		return (NULL);
	}
	return (cmd_path);
}
