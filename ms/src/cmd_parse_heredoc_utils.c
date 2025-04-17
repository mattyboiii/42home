/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_heredoc_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:44:43 by mexu              #+#    #+#             */
/*   Updated: 2024/11/22 12:27:02 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// combine a string array into a single string
static char	*combine_str_arr(char **arr)
{
	char	*str;
	char	*tmp;
	int		i;

	str = ft_strdup(arr[0]);
	i = 0;
	while (arr[++i])
	{
		tmp = str;
		str = ft_strjoin(str, arr[i]);
		null_free(&tmp);
		if (arr[i + 1])
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			null_free(&tmp);
		}
	}
	dp_free(&arr);
	return (str);
}

// handle the variables in the line
// will combine all the variables into a single string
static char	*handle_variables_in_line(t_minishell *data, char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	if (!words)
		return (NULL);
	i = -1;
	while (words[++i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = handle_variable_heredoc(data, words[i]);
			if (!words[i])
				return (NULL);
		}
	}
	return (combine_str_arr(words));
}

// process the line from the input
// if there's a variable in the line, it will be handled
static bool	process_line(t_minishell *data, char **line,
	t_io_fds *io, bool *ret)
{
	if (*line == NULL)
	{
		put_errmsg("warning", "heredoc delimited by end-of-file: wanted",
			io->hd_delimiter, EXIT_FAILURE);
		*ret = true;
		return (false);
	}
	if (ft_strcmp(*line, io->hd_delimiter) == 0)
	{
		*ret = true;
		return (false);
	}
	if (io->heredoc_quotes == false && ft_strchr(*line, '$'))
	{
		*line = handle_variables_in_line(data, *line);
		if (!(*line))
		{
			null_free(&(*line));
			*ret = false;
			return (false);
		}
	}
	return (true);
}

// fill the heredoc
bool	fill_heredoc(t_minishell *data, t_io_fds *io, int fd)
{
	char	*line;
	bool	ret;

	ret = false;
	while (1)
	{
		signal_in_prompt();
		line = readline(">");
		signal_in_execution();
		if (!process_line(data, &line, io, &ret))
		{
			null_free(&line);
			break ;
		}
		ft_putendl_fd(line, fd);
		null_free(&line);
	}
	return (ret);
}
