/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:34:17 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/23 10:06:02 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h> //dup, dup2, access
# include <sys/types.h> //pid_t
# include <stdlib.h> //free, malloc
# include <fcntl.h> //open, close
# include <sys/wait.h> //waitpid, wait
# include "../libft/libft.h"

// Functions in my pipex_utils.c
// ---  ------------------------
char	**ft_getenv(char *name, char **env);
void	dp_free(char ***dp);
char	**dp_strcat(char **paths, char *str);
char	*get_cmdpath(char *cmd, char **env);

#endif
