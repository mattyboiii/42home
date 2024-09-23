/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:27 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/23 12:40:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_exit(int n)
{
	if (n == 5)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		ft_putendl_fd("./pipex file1 cmd cmd file2", 2);
		exit(5);
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
