/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:25 by mexu              #+#    #+#             */
/*   Updated: 2024/11/22 12:23:35 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// show usage of the program
static int	show_usage(void)
{
	ft_putendl_fd("use ./minishell or ./minishell -c <command>", 2);
	return (EXIT_FAILURE);
}

// start check for the program
// check arg number and arg format
static int	start_check(t_minishell *ms, int ac, char **av)
{
	if (ac != 1 && ac != 3)
		return (show_usage());
	if (ac == 3)
	{
		if (!av[1] || (av[1] && ft_strcmp(av[1], "-c") != 0))
			return (show_usage());
		else if (!av[2] || (av[2] && av[2][0] == '\0'))
			return (show_usage());
		ms->interactive = false;
	}
	else
		ms->interactive = true;
	return (EXIT_SUCCESS);
}

// interactive mode of minishell
// read user input and process it in a loop
void	interactive(t_minishell *ms)
{
	while (true)
	{
		signal_in_prompt();
		ms->user_input = readline(PROMPT);
		signal_in_execution();
		if (check_input(ms))
			ms->last_exit_code = 1;
		else
			ms->last_exit_code = execute(ms);
		clean_data(ms);
	}
}

// non interactive mode of minishell
// split the input by ';' and process each command
void	non_interactive(t_minishell *ms, char *arg)
{
	char	**user_inputs;
	int		i;

	user_inputs = ft_split(arg, ';');
	if (!user_inputs)
		exit_ms(ms, EXIT_FAILURE);
	i = 0;
	signal_in_execution();
	while (user_inputs[i])
	{
		ms->user_input = ft_strdup(user_inputs[i]);
		if (check_input(ms))
			ms->last_exit_code = 1;
		else
			ms->last_exit_code = execute(ms);
		i++;
		clean_data(ms);
	}
	dp_free(&user_inputs);
}

// main function
// initialize minishell and start the program
int	main(int ac, char **av, char **env)
{
	t_minishell	ms;

	ft_memset(&ms, 0, sizeof(t_minishell));
	if (start_check(&ms, ac, av) || init_ms(&ms, env))
		exit_ms(NULL, EXIT_FAILURE);
	if (ms.interactive)
		interactive(&ms);
	else
		non_interactive(&ms, av[2]);
	exit_ms(&ms, ms.last_exit_code);
	return (0);
}
