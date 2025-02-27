/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:28 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:25:11 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// command list functions
// new, add back, last, delete one, clear
t_cmd	*lst_new_command(bool pipe_flag)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_cmd));
	new->pipe_output = pipe_flag;
	return (new);
}

void	lst_add_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst && new)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

t_cmd	*lst_last_cmd(t_cmd *cmd)
{
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

void	lst_delone_cmd(t_cmd *lst, void (*del)(void *))
{
	if (lst->cmd_str)
		(*del)(lst->cmd_str);
	if (lst->args)
		ft_free_str2d(lst->args);
	if (lst->pipe_fd)
		(*del)(lst->pipe_fd);
	if (lst->io_fds)
		free_io(lst->io_fds);
	(*del)(lst);
}

void	lst_clear_cmd(t_cmd **lst, void (*del)(void *))
{
	t_cmd	*temp;

	temp = NULL;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		lst_delone_cmd(*lst, del);
		*lst = temp;
	}
}
