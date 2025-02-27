/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:17 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 16:40:48 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// clean up and exit the minishell
void	exit_ms(t_minishell *data, int exit_code)
{
	if (data)
	{
		if (data->cmd && data->cmd->io_fds)
			close_fds(data->cmd, true);
		if (data->env)
			ft_free_str2d(data->env);
		clean_data(data);
	}
	rl_clear_history();
	exit(exit_code);
}

// print an error message
// there are 3 strings that can be passed to this function
// the error number will be returned
int	put_errmsg(char *s1, char *s2, char *s3, int err_nb)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (s1 != NULL)
	{
		ft_putstr_fd(s1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (s2 != NULL)
	{
		ft_putstr_fd(s2, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (s3 != NULL)
		ft_putstr_fd(s3, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (err_nb);
}
