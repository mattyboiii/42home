/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:21 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:49:14 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// -n or -nnnnnn
// not -n123 or -abc
static bool	is_n_option(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] != '-')
		return (false);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		return (true);
	return (false);
}

static void	output_args(char **args, bool n_flag, int i)
{
	if (!args[i])
	{
		if (!n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	while (args[i])
	{
		if (is_n_option(args[i]))
		{
			i++;
			continue ;
		}
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		else if (!args[i + 1] && !n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

int	echo_builtin(t_minishell *data, char **args)
{
	int		i;
	bool	n_flag;

	(void)data;
	n_flag = false;
	i = 1;
	if (args[i] && is_n_option(args[i]))
	{
		n_flag = true;
		i++;
	}
	output_args(args, n_flag, i);
	return (EXIT_SUCCESS);
}
