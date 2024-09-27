/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:17 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/27 10:32:38 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h> //dup, dup2, access
# include <stdio.h> //debug
# include <sys/types.h> //pid_t
# include <stdlib.h> //free, malloc
# include <fcntl.h> //open, close
# include <sys/wait.h> //waitpid, wait
# include "../libft/libft.h"

// Functions in my pipex_utils.c
// ---  ------------------------
int		openup(char *filename, int read_write);
void	ft_exit(int n);
char	**ft_getenv(char *name, char **env);
char	*get_cmdpath(char *cmd, char **env);

#endif
