/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:48 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:46:20 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	prepare_heredoc(t_minishell *data, t_io_fds *io)
{
	int		tmp_fd;
	bool	ret;

	ret = true;
	tmp_fd = open(io->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ret = fill_heredoc(data, io, tmp_fd);
	close(tmp_fd);
	return (ret);
}

// make sure that everytime this 
// function is called, the name is unique
static char	*get_heredoc_name(void)
{
	static int	i = 0;
	char		*name;
	char		*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin(HEREDOC_NAME, number);
	free(number);
	i++;
	return (name);
}

// set the delimiter for the heredoc
// and set the quotes flag in the struct
static char	*set_delimiter(char *delim, bool *quotes)
{
	int	len;

	len = ft_strlen(delim) - 1;
	if ((delim[0] == '\"' && delim[len] == '\"')
		|| (delim[0] == '\'' && delim[len] == '\''))
	{
		*quotes = true;
		return (ft_strtrim(delim, "\'\""));
	}
	return (ft_strdup(delim));
}

// parse the heredoc token
void	parse_heredoc(t_minishell *data, t_cmd **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_cmd		*cmd;
	t_io_fds	*io;

	temp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	init_io(cmd);
	io = cmd->io_fds;
	if (remove_infile_ref(io))
		return ;
	io->infile = get_heredoc_name();
	io->hd_delimiter = set_delimiter(temp->next->str, &(io->heredoc_quotes));
	if (prepare_heredoc(data, io))
		io->fd_in = open(io->infile, O_RDONLY);
	else
		io->fd_in = -1;
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}
