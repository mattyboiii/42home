/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-17 01:39:44 by mtripodi          #+#    #+#             */
/*   Updated: 2025-04-17 01:39:44 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_heredoc(char *word, int *pfd)
{
	char	*str;
	int		wordlen;

	wordlen = ft_strlen(word);
	close(pfd[0]);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			printf("warning: here-document delimited by end-of-file\n");
				break ;
		}
		if (str && !(ft_strncmp(str, word, wordlen - 1) == 0)
				&& str[wordlen] == '\n')
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, pfd[1]);
		free(str);
	}
	close(pfd[1]);
}

int	here_doc(char *word)
{
	int		pfd[2];
	int		fid;
	int		status;

	if (pipe(pfd) == -1)
		exit(-2);
	fid = fork();
	if (fid == 0)
		make_heredoc(word, pfd);
	else
	{
		close(pfd[1]);
		waitpid(fid, &status, 0);
		return (pfd[0]);
	}
	return (-1);
}
