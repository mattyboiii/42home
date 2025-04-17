/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:02 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:48:39 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// create a new token
t_token	*lst_new_token(char *str, int type, int status)
{
	t_token	*new;

	new = malloc(sizeof(t_token) * 1);
	if (!(new))
		return (NULL);
	new->str = str;
	new->var_exists = false;
	new->type = type;
	new->quoting = status;
	new->join = false;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

// add a new token to the end of the list
void	lst_add_back_token(t_token **lst, t_token *new)
{
	t_token	*temp;

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

// delete a token
void	lst_delone_token(t_token *lst)
{
	if (!lst)
		return ;
	if (lst->str)
	{
		null_free(&(lst->str));
		lst->str = NULL;
	}
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free(lst);
	lst = NULL;
}

void	lst_clear_token(t_token **lst)
{
	t_token	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		lst_delone_token(*lst);
		*lst = tmp;
	}
}
