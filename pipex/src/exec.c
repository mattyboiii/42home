/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:41:01 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/10 16:13:52 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main()
{
	char cmd[] = "/bin/ls";

	char *argvec[] = {"ls", NULL};
	char *envvec[] = {NULL};
	printf("start of execve call %s\n", cmd);
	printf("===============================================\n");
	if (execve(cmd, argvec, envvec) == -1)
	{
		perror("coud not execute execve");
	}
	printf("Oops, somthing went wrong!");
}
