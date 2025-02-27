/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:11:19 by mexuCharlie       #+#    #+#             */
/*   Updated: 2024/11/07 09:59:05 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_free_str(char *s)
{
	ft_free(s);
	return (NULL);
}

char	**ft_free_str2d(char **s)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s[i] = ft_free_str(s[i]);
		i++;
	}
	ft_free(s);
	return (NULL);
}

char	***ft_free_str3d(char ***s)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s[i] = ft_free_str2d(s[i]);
		i++;
	}
	ft_free(s);
	return (NULL);
}
*/

char	*ft_free_str_and_null(char *s)
{
	ft_free(s);
	return (NULL);
}

void	ft_free_str2d(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_free(s[i]);
			s[i] = NULL;
			i++;
		}
		ft_free(s);
		s = NULL;
	}
}

void	ft_free_str3d(char ***s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_free_str2d(s[i]);
			s[i] = NULL;
			i++;
		}
		ft_free(s);
		s = NULL;
	}
}
