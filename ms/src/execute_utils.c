/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:42:38 by njackson          #+#    #+#             */
/*   Updated: 2024/09/11 18:20:10 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ms_split_alloc(const char *line, char c)
{
	size_t	i;
	size_t	count;

	if (!line)
		return (0);
	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] && line[i] == c)
			i++;
		if (line[i] && line[i] != c)
			count++;
		while (line[i] && line[i] != c)
			i++;
	}
	return (malloc((count + 1) * sizeof(char *)));
}

/**
 * @brief if the line is valid, it will put the word inside of **out.
 *
 * Two important features seperating it from ft_split
 * 1. finish_quote();
 * 2. if substr returns (NULL); it will free **out completely. Inside
 * of a looping shell environment, it ensures clean memory handlind.
 *
 *
 * @return length of a word
 */
static int	get_word(const char *line, char c, char **out, size_t count)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != c)
	{
		if (line[i] == '\'' || line[i] == '"')
			finish_quote(line, &i);
		else
			++i;
	}
	out[count] = ft_substr(line, 0, i);
	if (!out[count])
	{
		while (count > 0)
			free(out[--count]);
		free(out);
		return (-1);
	}
	return (i);
}

/**
 * @brief this function splits the words into a double pointer. It works like
 * ft_split, but it takes use of functons such as ft_substr/free. Substr
 * allows the function to not have to call malloc itself. It also handles
 * errors and memory allocation cleaner.
 *
 * @return a pointer array filled with arguments.
 */
char	**ms_split(const char *line, char c)
{
	char	**out;
	int		i;
	size_t	count;

	out = ms_split_alloc(line, c);
	if (!out)
		return (0);
	count = 0;
	while (*line)
	{
		if (*line != c)
		{
			i = get_word(line, c, out, count);
			if (i < 0)
				return (0);
			line += i;
			count++;
		}
		else
			line++;
	}
	out[count] = 0;
	return (out);
}

/**
 * @brief finishe quote allows for everything inside of " " to be
 * considered as one argument, instead of splitting them.
 */
void	finish_quote(const char *line, int *i)
{
	int	s;

	if (line[*i] != '\'' && line[*i] != '"')
	{
		++(*i);
		return ;
	}
	s = *i;
	++(*i);
	while (line[*i] && line[*i] != line[s])
		++(*i);
	if (line[*i] != '\0')
		++*i;
	else
		*i = s + 1;
}

/**
 * @brief free all memory inside of the t_com. It does not specify but
 * this functoin will only work correclty when you pass in a t_comm. Void
 * is set as a parameter type so it can be handed into other funcitons.
 */
void	free_command(void *raw)
{
	t_comm	*comm;

	comm = (t_comm *)raw;
	if (comm->command && comm->command != comm->args[0])
		free(comm->command);
	free(comm->infile);
	free(comm->outfile);
	dp_free(&comm->args);
	free(comm);
}
