/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:36 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:47:37 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if the variable exists in the environment
static bool	var_exists(t_minishell *ms, char *var)
{
	int	i;

	i = -1;
	while (ms->env[++i])
		if (ft_strncmp(ms->env[i], var, ft_strlen(var)) == 0)
			return (true);
	return (false);
}

// Get the value of the variable from the environment
static char	*get_env_var_value(t_minishell *ms, char *var)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(var);
	while (ms->env[++i])
		if (ft_strncmp(ms->env[i], var, len) == 0)
			break ;
	str = ft_strdup(ms->env[i] + len);
	return (str);
}

// get the variable in the string
// plus a '=' to identify the variable
static char	*identify_var(char *str)
{
	int		start;
	int		len;
	char	*var;
	char	*tmp;

	start = 0;
	while (str[start] && str[start] != '$')
		start++;
	if (str[start] == '\0')
		return (NULL);
	start++;
	len = var_length(str);
	var = ft_substr(str, start, len);
	if (!var)
		return (NULL);
	tmp = ft_strjoin(var, "=");
	null_free(&var);
	return (tmp);
}

// get the value of the variable
char	*get_var_value(t_token *token, char *str, t_minishell *ms)
{
	char	*value;
	char	*var;

	var = identify_var(str);
	if (var && var_exists(ms, var))
	{
		if (token != NULL)
			token->var_exists = true;
		value = get_env_var_value(ms, var);
	}
	else if (var && var[0] == '?' && var[1] == '=')
		value = ft_itoa(ms->last_exit_code);
	else
		value = NULL;
	null_free(&var);
	return (value);
}
