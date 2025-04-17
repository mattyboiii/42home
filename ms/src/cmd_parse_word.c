/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:45:09 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 10:32:34 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if a string contains a space or not
static bool	contains_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (true);
	return (false);
}

// split the string into command and arguments
// the first word is the command and the rest are arguments
static void	split_token_str(t_cmd *last_cmd, char *cmd_str)
{
	t_token	*tk_lst;
	char	**strs;
	int		i;

	tk_lst = NULL;
	strs = ft_split(cmd_str, ' ');
	if (!strs || !strs[0])
		return ;
	last_cmd->cmd_str = ft_strdup(strs[0]);
	i = 1;
	while (strs[++i])
		lst_add_back_token(&tk_lst, lst_new_token(ft_strdup(strs[i]),
				WORD, DEFAULT));
	lst_add_back_token(&tk_lst, lst_new_token(NULL, END, DEFAULT));
	fill_args(&tk_lst, last_cmd);
	lst_clear_token(&tk_lst);
	dp_free(&strs);
}

// parse the word token	then fill the command and arguments
void	parse_word(t_cmd **cmd, t_token **token_lst)
{
	t_token		*temp;
	t_cmd		*last_cmd;

	temp = *token_lst;
	while (temp->type == WORD || temp->type == VAR)
	{
		last_cmd = lst_last_cmd(*cmd);
		if (!temp->prev || temp->prev->type == PIPE || !last_cmd->cmd_str)
		{
			if (temp->type == VAR && contains_space(temp->str))
				split_token_str(last_cmd, temp->str);
			else if (temp->str != NULL && temp->str[0] != '\0')
				last_cmd->cmd_str = ft_strdup(temp->str);
			temp = temp->next;
		}
		else
			fill_args(&temp, last_cmd);
	}
	*token_lst = temp;
}
