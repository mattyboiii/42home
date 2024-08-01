/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:26:28 by mtripodi          #+#    #+#             */
/*   Updated: 2024/08/02 08:54:49 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// fork() assigns
// the child process ID, from the parent process is assigned to 'id'
// 0 to 'id' from the child process
int main()
{
	int id = fork();
	printf("Current ID: %d\nParent ID: %d\n", getpid(), getppid());
	printf("Int id: %d\n", id);
	if (id != 0)
		wait(NULL);
	return(0);
}j
