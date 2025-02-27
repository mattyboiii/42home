/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:11 by mexu              #+#    #+#             */
/*   Updated: 2024/11/22 12:34:58 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_dir(t_minishell *data, char *path)
{
	char	*new_path;

	new_path = NULL;
	if (chdir(path) != 0)
		return (put_errmsg("cd", path, strerror(errno), EXIT_FAILURE));
	new_path = getcwd(NULL, 0);
	if (new_path)
	{
		set_env_var(data, "OLDPWD", env_var_value(data->env, "PWD"));
		set_env_var(data, "PWD", new_path);
		ft_free(new_path);
		return (EXIT_SUCCESS);
	}
	else
		return (put_errmsg("cd", path, strerror(errno), errno));
}

int	cd_builtin(t_minishell *data, char **args)
{
	char	*path;

	if (!args || !args[1] || ft_iswhitespace(args[1][0]) ||
		args[1][0] == '\0' || ft_strncmp(args[1], "--", 3) == 0)
	{
		path = env_var_value(data->env, "HOME");
		if (!path || *path == '\0' || ft_iswhitespace(*path))
			return (put_errmsg("cd", "HOME not set", NULL, EXIT_FAILURE));
		return (change_dir(data, path));
	}
	if (args[2])
		return (put_errmsg("cd", "too many arguments", NULL, EXIT_FAILURE));
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = env_var_value(data->env, "OLDPWD");
		if (!path)
			return (put_errmsg("cd", "OLDPWD not set", NULL, EXIT_FAILURE));
		return (change_dir(data, path));
	}
	return (change_dir(data, args[1]));
}
