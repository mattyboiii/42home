/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:05 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/25 15:24:46 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bouns.h"

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
		ret = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (ret == -1)
	{
		err_mes = ft_strjoin("Error opening file: ", filename);
		perror(err_mes);
		null_free(&err_mes);
		exit(-1);
	}
	return (ret);
}

// Execute function
// first this needs to get the path of the cmd used looking inside of the env
// this function should execute the cmd used in arv[1] using
// execve(path, arv, env). If the execute errors out I should send the error
// to stderror and Free all of the memory used.  
// int execve(const char *path, char *const argv[], char *const envp[]);
void	cmd_exe(char *cmdarv, char **env)
{
	char	*cmd_pth;
	char	**cmd;

	cmd = ft_split(cmdarv, ' ');
	cmd_pth = get_cmdpath(*cmd, env);
	if (execve(cmd_pth, cmd, env) == -1)
	{
		perror(*cmd);
		dp_free(&cmd);
		null_free(&cmd_pth);
	}
}
/*
 ** By default, a child process inherits its standard input from the parent
 ** process. This means that if the parent process has redirected standard
 ** input to a specific source (like a file or another pipe), the child process
 ** will also be reading from that source unless it explicitly redirects its
 ** own standard input.
 */
void	piping_hot(char *cmd, char **arv)
{
	int	pfd[2];
	pid_t	fid;

	if(pipe(pfd) == -1)
		exit(-1);
	fid = fork();
	if (fid == 0)
	{
		close(pfd[0])
			dup2(pfd[1], 1);
		cmd_exe(cmd, env);
	}
	else
	{
		wait();
		close(pfd[1])
			dup2(pfd[0], 0);
	}
}

// pfd[1] = write
// pfd[0] = read
/*
 ** --I am the child--
 ** Process ID: 58025
 ** Parent ID: 58024
 ** fid: 0
 **
 ** --Parent Waited for child--
 ** Process ID: 58024
 ** Parent ID: 57222
 ** fid: 58025
 */
int	main(int arc, char **arv, char **env)
{
	int i;
	int infile;
	int outfile;

	if (arc < 5)
		ft_exit(5);

	if (ft_strcmp(arv[1], "here_doc") == 0)
	{
		i = 3;
	}
	else
	{
		i = 2;
		infile = openup(arv[1], 0);
		outfile = openup(arv[arc -1], 1);
		dup2(infile, 0);
	}
	while (i < arc - 2)
		piping_hot(av[i++], env);
	dup2(outfile, 1);
	cmd_exe(arv[arc -2], env);
}
