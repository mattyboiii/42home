/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:50 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:48:48 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check user input
// create tokens, create commands
int	check_input(t_minishell *data)
{
	if (data->user_input == NULL)
		exit_builtin(data, NULL);
	else if (!ft_strcmp(data->user_input, "\0"))
		return (EXIT_FAILURE);
	add_history(data->user_input);
	if (create_token(data))
		return (EXIT_FAILURE);
	create_cmd(data, data->token);
	return (EXIT_SUCCESS);
}

// check tokens
// handle the variables and quotes in the token list
static int	check_token(t_minishell *data, int status)
{
	if (status != DEFAULT)
		return (put_errmsg(NULL, NULL, "Syntax error. No matching quote.",
				EXIT_FAILURE));
	if (data->token->type == END)
		return (EXIT_FAILURE);
	if (check_if_var(&data->token))
		return (EXIT_FAILURE);
	handle_variable(data, &data->token);
	handle_quotes(data->token);
	return (EXIT_SUCCESS);
}

// create tokens from user input
// loop through the input, check the status of the quotes
// and save the tokens during each loop
int	create_token(t_minishell *data)
{
	int		i;
	int		start;
	int		status;
	char	*str;

	str = data->user_input;
	i = 0;
	start = 0;
	status = DEFAULT;
	while (i <= (int)ft_strlen(str))
	{
		status = set_quote_status(status, str + i);
		if (status == DEFAULT)
			start = save_token(&i, str, start, data);
		i++;
	}
	return (check_token(data, status));
}
