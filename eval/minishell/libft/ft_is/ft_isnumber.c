/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:56:39 by mexu              #+#    #+#             */
/*   Updated: 2024/11/07 09:57:06 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	if (s[i] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_iswhitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}
