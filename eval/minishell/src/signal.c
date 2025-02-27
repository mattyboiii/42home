/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:46:44 by mexu              #+#    #+#             */
/*   Updated: 2024/11/26 16:42:24 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// reset the prompt when ctrl+c is pressed
static void	reset_prompt(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_in_prompt(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, reset_prompt);
}

// put the prompt back to the beginning of the line
static void	signal_newline(int signal)
{
	(void)signal;
	rl_on_new_line();
}

void	signal_in_execution(void)
{
	signal(SIGINT, signal_newline);
	signal(SIGQUIT, signal_newline);
}
