/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:26:28 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/10 14:23:54 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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


// fork() assigns
// the child process ID, from the parent process is assigned to 'id'
// 0 to 'id' from the child process
// wre = wait result
int main()
{
	int fid = fork();
	int wre;

	if (fid != 0)
	{
		wre = wait(NULL);
		if (wre != -1)
			printf("--Parent Waited for child--\n");
		else 
			printf("Error in wait()\n");
	}
	else
		printf("--I am the child--\n");
	printf("Process ID: %d\nParent ID: %d\n", getpid(), getppid());
	printf("fid: %d\n\n", fid);
	return(0);
}
