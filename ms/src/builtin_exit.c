/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:43 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:35:21 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// exit the minishell
// exit code 2 means not correct use of the exit command
int	exit_builtin(t_minishell *ms, char **args)
{
	if (!args || !args[1])
		exit_ms(ms, ms->last_exit_code);
	if (!ft_isnumber(args[1]))
		exit_ms(ms,
			put_errmsg("exit", args[1], "numeric argument required", 2));
	if (args[2])
		return (put_errmsg("exit", NULL, "too many arguments", EXIT_FAILURE));
	exit_ms(ms, (ft_atoi(args[1])) % 256);
	return (12345);
}
