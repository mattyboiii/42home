/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:20 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 22:42:28 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// init environment variables
// duplicate env variables to ms->env
static int	init_env(t_minishell *ms, char **env)
{
	int	i;

	ms->env = ft_calloc(ft_str_arr_len(env) + 1, sizeof * ms->env);
	if (!ms->env)
		return (EXIT_FAILURE);
	i = -1;
	while (env[++i])
	{
		ms->env[i] = ft_strdup(env[i]);
		if (!ms->env[i])
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// initialize minishell
int	init_ms(t_minishell *ms, char **env)
{
	if (init_env(ms, env))
		return (put_errmsg(NULL, NULL, "Can't init environment.",
				EXIT_FAILURE));
	ms->token = NULL;
	ms->user_input = NULL;
	ms->cmd = NULL;
	ms->pid = -1;
	ms->last_exit_code = 0;
	return (EXIT_SUCCESS);
}

// init io_fds in cmd
void	init_io(t_cmd *cmd)
{
	if (!cmd->io_fds)
	{
		cmd->io_fds = malloc(sizeof * cmd->io_fds);
		if (!cmd->io_fds)
			return ;
		cmd->io_fds->infile = NULL;
		cmd->io_fds->outfile = NULL;
		cmd->io_fds->hd_delimiter = NULL;
		cmd->io_fds->heredoc_quotes = false;
		cmd->io_fds->fd_in = -1;
		cmd->io_fds->fd_out = -1;
		cmd->io_fds->stdin_backup = -1;
		cmd->io_fds->stdout_backup = -1;
	}
}
