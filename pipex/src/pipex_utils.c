/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:27 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/13 17:28:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

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
				split_paths = ft_split(env[i] +
					ft_strlen(name) + 1, ':');
				return (split_paths);
			}
		}
		i++;
	}
	
	return (NULL);
}

// Function to free memory, but most importanly set the pointers to NULL after
// freeing. This helps me debug my programs. That is why this one is a triple
// ptr eg ***ptr. As i want to set **ptr to NULL.
void dp_free(char ***dp)
{
	int i;

	i = 0;
	while ((*dp)[i])
	{
		null_free(&(*dp)[i]);
		i++;
	}
	free(*dp);
	*dp = NULL;
}

char **dp_strcat(char **paths, char *str)
{
	int	i;
	char **dp_strcat;

	i = 0;
	while (paths[i])
		i++;
	dp_strcat = malloc((sizeof(char *) * (i + 1)));
	if (dp_strcat == NULL)
		exit(-1);
	i = 0;
	while (paths[i])
	{
		dp_strcat[i] = ft_strjoin(paths[i], str);
		i++;
	}
	dp_strcat[i] = NULL;
	dp_free(&paths);
	return (dp_strcat);
}
char *get_cmdpath(char *cmd, char **env)
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
		if(access(paths[i], F_OK | X_OK) == 0)
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

int main(int arc, char **arv, char **env)
{
	char cmd[10];
	char *path;

	printf("%d\n", arc);
	printf("%s\n", arv[0]);

	printf("which cmd are you looking for?\n");
	scanf("%s", cmd);
	path = get_cmdpath(cmd, env);
	printf("%s\n", path);
}

//need a function which looks in all of the paths, for a file which matches 
//the name of cmd
// and finds it, then appends it to the end of the path, returning the path. 
// This function has to look in all of the locations. this function might 
// use access.
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

