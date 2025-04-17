/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:54 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:23:50 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// remove the oldd input file reference
// then open the new file to a file descriptor
static void	open_infile(t_io_fds *io, char *file)
{
	if (remove_infile_ref(io))
		return ;
	io->infile = ft_strdup(file);
	if (io->infile && io->infile[0] == '\0')
	{
		put_errmsg(file, NULL, "ambiguous redirect", EXIT_FAILURE);
		return ;
	}
	io->fd_in = open(io->infile, O_RDONLY);
	if (io->fd_in == -1)
		put_errmsg(io->infile, NULL, strerror(errno), EXIT_FAILURE);
}

// parse the input token
void	parse_input(t_cmd **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_cmd		*cmd;

	temp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	init_io(cmd);
	open_infile(cmd->io_fds, temp->next->str);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}

// remove the old input file reference
int	remove_infile_ref(t_io_fds *io)
{
	if (io->infile)
	{
		if (io->fd_in == -1 || (io->outfile && io->fd_out == -1))
			return (EXIT_FAILURE);
		if (io->hd_delimiter != NULL)
		{
			null_free(&(io->hd_delimiter));
			io->hd_delimiter = NULL;
			unlink(io->infile);
		}
		null_free(&(io->infile));
		close(io->fd_in);
	}
	return (EXIT_SUCCESS);
}
