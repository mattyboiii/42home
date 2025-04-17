/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-17 07:58:46 by mtripodi          #+#    #+#             */
/*   Updated: 2025-04-17 07:58:46 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}
