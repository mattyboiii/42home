/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:45:37 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 22:49:26 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// get the index of the environment variable acording to the key
int	env_var_index(char **env, char *key)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (-1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
		{
			ft_free(temp);
			return (i);
		}
		i++;
	}
	ft_free(temp);
	return (-1);
}

// get the value of the environment variable acording to the key
char	*env_var_value(char **env, char *key)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
		{
			ft_free(temp);
			return (ft_strchr(env[i], '=') + 1);
		}
		i++;
	}
	ft_free(temp);
	return (NULL);
}

// check environment variable key(to the '=') is valid or not.
bool	is_valid_env_var_key(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	if (!ft_isalpha(*str) && *str != '_')
		return (false);
	while (*str && *str != '=')
	{
		if (ft_isalnum(*str) == 0 && *str != '_')
			return (false);
		str++;
	}
	return (true);
}
