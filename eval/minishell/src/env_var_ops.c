/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:45:44 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 22:42:25 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**realloc_env_vars(t_minishell *data, int size)
{
	char	**new_env;
	int		i;

	new_env = ft_calloc(size + 1, sizeof * new_env);
	if (!new_env)
		return (NULL);
	i = 0;
	while (data->env[i] && i < size)
	{
		new_env[i] = ft_strdup(data->env[i]);
		ft_free(data->env[i]);
		i++;
	}
	free(data->env);
	return (new_env);
}

bool	remove_env_var(t_minishell *data, int idx)
{
	int	i;
	int	count;

	if (idx > ft_str_arr_len(data->env))
		return (false);
	ft_free(data->env[idx]);
	i = idx;
	count = idx;
	while (data->env[i + 1])
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		ft_free(data->env[i + 1]);
		count++;
		i++;
	}
	data->env = realloc_env_vars(data, count);
	if (!data->env)
		return (false);
	return (true);
}

// set the environment variable with the key and value
bool	set_env_var(t_minishell *data, char *key, char *value)
{
	int		idx;
	char	*tmp;

	idx = env_var_index(data->env, key);
	if (value == NULL)
		value = "";
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (false);
	if (idx != -1 && data->env[idx])
	{
		ft_free(data->env[idx]);
		data->env[idx] = ft_strjoin(key, tmp);
	}
	else
	{
		idx = ft_str_arr_len(data->env);
		data->env = realloc_env_vars(data, idx + 1);
		if (!data->env)
			return (false);
		data->env[idx] = ft_strjoin(key, tmp);
	}
	ft_free(tmp);
	return (true);
}
