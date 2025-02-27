/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:37 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:35:28 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print the environment variables
int	env_builtin(t_minishell *data, char **args)
{
	int	i;

	if (args && args[1])
		return (put_errmsg("env", NULL, "too many arguments", EXIT_FAILURE));
	i = 0;
	if (!data->env)
		return (EXIT_FAILURE);
	while (data->env[i])
		ft_putendl_fd(data->env[i++], STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
