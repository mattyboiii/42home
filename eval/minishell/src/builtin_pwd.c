/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:58 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:33:11 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print the current working directory
int	pwd_builtin(t_minishell *data, char **args)
{
	char	*cwd;

	(void)args;
	(void)data;
	cwd = getcwd(NULL, 0);
	if (cwd)
		return (ft_putendl_fd(cwd, STDOUT_FILENO), EXIT_SUCCESS);
	else
		return (put_errmsg("pwd", NULL, strerror(errno), errno));
}
