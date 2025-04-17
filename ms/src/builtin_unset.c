/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:03 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:33:04 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// unset the environment variable
// remove the environment variable from the environment list
int	unset_builtin(t_minishell *data, char **args)
{
	int	i;
	int	idx;

	i = 1;
	while (args[i])
	{
		if (!is_valid_env_var_key(args[i]) || ft_strchr(args[i], '='))
			return (put_errmsg("unset", args[i], "not a valid identifier",
					EXIT_FAILURE));
		else
		{
			idx = env_var_index(data->env, args[i]);
			if (idx != -1)
				remove_env_var(data, idx);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
