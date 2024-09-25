/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:27 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/25 17:48:16 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// openupV
// int openup(char *file, 
// if the file exists, it should open it using 
// int open(const char *path, int oflag, ...);
// if the file does not exist, it should create it using open() with the
// right oflags if the file has an error opening it should handle this. 
/*
 ** mode: The access mode to check, which can be one or more of the
 **        following flags combined with a bitwise OR (|):
 **
 **
 **   F_OK: Check if the file exists.
 **   R_OK: Check if the file is readable.
 **   W_OK: Check if the file is writable.
 **   X_OK: Check if the file is executable.
 */

int	openup(char *filename, int read_write)
{
	int		ret;
	char	*err_mes;

	if (read_write == 0)
		ret = open(filename, O_RDONLY, 0777);
	if (read_write == 1)
		ret = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (read_write == 2)
		ret = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (ret == -1)
	{
		err_mes = ft_strjoin("Error opening file: ", filename);
		perror(err_mes);
		null_free(&err_mes);
		exit(-1);
	}
	return (ret);
}

void	ft_exit(int n)
{
	if (n == 5)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		ft_putendl_fd("./pipex file1 cmd cmd file2", 2);
		exit(5);
	}
	if (n == 6)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		ft_putendl_fd("./pipex here_doc LIMITER cmd cmd1 file", 2);
		exit(6);
	}
}

// Function to collect the path of the variable at argument name. It will 
// Search though the environment variables till it finds a match, then 
// it will return a double pointer with each of the dir paths referenced
// by the name argument. I used this to find everthing after "PATH="
char	**ft_getenv(char *name, char **env)
{
	int		i;
	char	**split_paths;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == name[0])
		{
			if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
			{
				split_paths = ft_split(env[i] + ft_strlen(name)
						+ 1, ':');
				return (split_paths);
			}
		}
		i++;
	}
	return (NULL);
}

// Funciton to check the path from ft_getenv. The file at this path needs
// to be checked to ensure its available and does not cause errors. I will
// need to use F_OK | X_OK 
// F_OK: This flag checks if the file exists.
// X_OK: This flag checks if the file is executable by the current process.
char	*get_cmdpath(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*exec;

	i = 0;
	exec = NULL;
	paths = ft_getenv("PATH", env);
	paths = dp_strcat(paths, ft_strjoin("/", cmd));
	while (paths[i])
	{
		if (access(paths[i], F_OK | X_OK) == 0)
		{
			exec = ft_strdup(paths[i]);
			dp_free(&paths);
			return (exec);
		}
		i++;
	}
	dp_free(&paths);
	return (exec);
}
