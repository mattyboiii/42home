/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:50 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:34:52 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// get a key value pair from the argument
static char	**get_key_value_pair(char *arg)
{
	char	**temp;
	char	*equal_idx;

	equal_idx = ft_strchr(arg, '=');
	temp = malloc(sizeof(char *) * 3);
	temp[0] = ft_substr(arg, 0, equal_idx - arg);
	temp[1] = ft_substr(equal_idx, 1, ft_strlen(equal_idx));
	temp[2] = NULL;
	return (temp);
}

// mimic the behavior of bash when using export without arguments
// output declare -x for each environment variable
static int	export_no_arg(t_minishell *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(data->env[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}

// export the environment variable
// create a new environment variable if it does not exist
int	export_builtin(t_minishell *data, char **args)
{
	int		i;
	char	**temp;

	i = 1;
	if (!args[i])
		return (export_no_arg(data));
	while (args[i])
	{
		if (!is_valid_env_var_key(args[i]))
			return (put_errmsg("export", args[i], "not a valid identifier",
					EXIT_FAILURE));
		else if (ft_strchr(args[i], '='))
		{
			temp = get_key_value_pair(args[i]);
			set_env_var(data, temp[0], temp[1]);
			dp_free(&temp);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
