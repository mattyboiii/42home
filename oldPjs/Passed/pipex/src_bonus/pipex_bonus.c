/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:05 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/27 10:32:06 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	make_heredoc(char **arv, int *pfd)
{
	char	*str;

	close(pfd[0]);
	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, arv[2], ft_strlen(arv[2]) - 1) == 0)
		{
			null_free(&str);
			exit(0);
		}
		ft_putstr_fd(str, pfd[1]);
		free(str);
	}
}

void	here_doc(char **arv)
{
	int	pfd[2];
	int	fid;

	if (pipe(pfd) == -1)
		exit(-2);
	fid = fork();
	if (fid == 0)
		make_heredoc(arv, pfd);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		wait(NULL);
	}
}

/*
 ** By default, a child process inherits its standard input from the parent
 ** process. This means that if the parent process has redirected standard
 ** input to a specific source (like a file or another pipe), the child process
 ** will also be reading from that source unless it explicitly redirects its
 ** own standard input.
 */
void	piping_hot(char *cmd, char **env)
{
	int		pfd[2];
	pid_t	fid;

	if (pipe(pfd) == -1)
		exit(-1);
	fid = fork();
	if (fid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		cmd_exe(cmd, env);
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
	}
}

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
	int		i;
	int		infile;
	int		outfile;

	if (arc < 5)
		ft_exit(5);
	if (ft_strcmp(arv[1], "here_doc") == 0)
	{
		if (arc < 6)
			ft_exit(6);
		i = 3;
		outfile = openup(arv[arc - 1], 2);
		here_doc(arv);
	}
	else
	{
		i = 2;
		infile = openup(arv[1], 0);
		outfile = openup(arv[arc - 1], 1);
		dup2(infile, 0);
	}
	while (i < arc - 2)
		piping_hot(arv[i++], env);
	dup2(outfile, 1);
	cmd_exe(arv[arc - 2], env);
}
