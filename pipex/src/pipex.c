/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:05 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/11 18:24:02 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "pipex.h"
#include <stdio.h>

//Execute function
//first this needs to get the path of the cmd used looking inside of the env
//this function should execute the cmd used in arv[1] using execve(path, arv, env)
//if the execute errors out I should send the error to stderror.
//free all of the memory used.  

//CHILD a function for when the child process is called. The child process will have an fid
//of 0
//it will need to take in the first set of arguments arv[1]. open this file. if the file does not exist, it should be created. Apply this to a fd. 
//take the new fd and link it to the stdin. 
//link the write end of the pipe to the stdout

void child(char **arv, int *pfd, char **env)
{
	int		fid;

	fid = openup(arv[2], 0);
}

//PARENT a funciton for when the parent process is called. The parent process will have a fid
//greater than 0
//it will take in the second argument of arv[3] open this file. If it does not exist it should
//be created. using the open function. 
//take the new fd and link it to the stdout

void parent(char **arv, int *pfd, char **env)
{
	int		fid;
}


//openup
//int openup(char *file, 
//if the file exists, it should open it using  int open(const char *path, int oflag, ...);
//if the file does not exist, it should create it using open() with the right oflags
//if the file has an error opening it should handle this. 
int openup(char *filename, int read_write)
{
	int		ret;

	if(read_write == 0)
		ret = open(filename, 0_RDONLY, 0777);
	if read_write == 1)
		ret = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (ret == -1)
	{
		ret = -1;
	}
}

//main function should
//create a pipe and apply its ids to an int array. 
//create a child and a parent process using fork
//check for failures or -1 returns for both fork and pipe
//if its child, run child process
//if parent run the parent after child.

	//pfd[1] = write
	//pfd[0] = read
int main(int arc, char **arv, char **env)
{
	int		pfd[2];
	pid_t fid; 

	if(pipe(pfd) == -1)
		exit(-1);
	fid = fork();
	if (fid == -1)
		exit(-1);
	if (fid == 0)
		child(arv, pfd, env);
	parent(arv[2], pfd, env);
}

/*
 ** SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.7jfxMsFT5n/Listeners
 ** LC_TERMINAL_VERSION=3.4.4
 ** COLORFGBG=7;0
 ** ITERM_PROFILE=Default
 ** XPC_FLAGS=0x0
 ** LANG=en_US.UTF-8
 ** PWD=/Users/mtripodi/desktop/42home/pipex/src
 ** SHELL=/bin/zsh
 ** SECURITYSESSIONID=18805
 ** TERM_PROGRAM_VERSION=3.4.4
 ** TERM_PROGRAM=iTerm.app
 ** PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
 ** :/Library/Frameworks/Mono.framework/Versions/Current/Commands
 ** LC_TERMINAL=iTerm2
 ** COLORTERM=truecolor
 ** COMMAND_MODE=unix2003
 ** TERM=xterm-256color
 ** HOME=/Users/mtripodi
 ** TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n000cgv80033yt/T/
 ** USER=mtripodi
 ** XPC_SERVICE_NAME=0
 */

