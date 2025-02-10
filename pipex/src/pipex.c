/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:05 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/23 12:48:10 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

// CHILD a function for when the child process is called. The child process
// will have an fid of 0.
// It will need to take in the first set of arguments arv[1] then open the
// file. if the file does not exist, it should be created. Apply this to
// a fd. Take the new fd and link it to the stdin. link the write end of
// the pipe to the stdout
void	child(char **arv, int *pfd, char **env)
{
	int		fid;

	fid = openup(arv[1], 0);
	dup2(fid, 0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	cmd_exe(arv[2], env);
}

// PARENT a funciton for when the parent process is called. The parent
// process will have a fid greater than 0. It will take in the second
// argument of arv[3] open this file. If it does not exist it should
// be created. using the open function. Take the new fd and link it to
// the stdout
void	parent(char **arv, int *pfd, char **env)
{
	int		fid;

	fid = openup(arv[4], 1);
	dup2(fid, 1);
	dup2(pfd[0], 0);
	close(pfd[1]);
	cmd_exe(arv[3], env);
}

// main function should
// create a pipe and apply its ids to an int array.
// create a child and a parent process using fork
// check for failures or -1 returns for both fork and pipe
// if its child, run child process
// Parent PROCESS will always run first.
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
	int		pfd[2];
	pid_t	pid;

	if (arc != 5)
		ft_exit(5);
	if (pipe(pfd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(arv, pfd, env);
	waitpid(pid, NULL, 0);
	parent(arv, pfd, env);
}
