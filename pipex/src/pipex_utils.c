/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:27 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/12 18:48:36 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

//openup
//int openup(char *file, 
//if the file exists, it should open it using  int open(const char *path, int oflag, ...);
//if the file does not exist, it should create it using open() with the right oflags
//if the file has an error opening it should handle this. 

//need a function which can collect the path. Meaning look in the **env and get a
//string matching the evname. then get all the string after = sign. Eg take in. 
//PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/
//Frameworks/Mono.framework/Versions/Current/Commands and return
//"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Frameworks/Mono.framework/Versions/Current/Commands"
//
//ft_getenv(char *name, char **env)
char *ft_getenv(char *name, char **env)
{
	int	i;
	char *paths;
	
	i = 0;
	paths = ft_strstr(*env, name);
	while (paths[i] && paths[i] != '=')
		i++;
	return (paths);
	
}

int main(int arc, char **arv, char **env)
{
	char cmd[10];
	char *paths;

	printf("%d\n", arc);
	printf("%s\n", arv[0]);

	printf("which cmd are you looking for?\n");
	scanf("%s", cmd);
	paths = ft_getenv("PATH", env);
	printf("%s\n", paths);
}

//need a function which looks in all of the paths, for a file which matches the name of cmd
//and finds it, then appends it to the end of the path, returning the path. This function has to look in all of the locations. this function might use access.
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

