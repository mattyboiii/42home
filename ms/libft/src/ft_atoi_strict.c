/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 06:25:29 by mtripodi          #+#    #+#             */
/*   Updated: 2025-04-08 06:25:29 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief like atoi ecxept if it hits any non-digit number, it iwll exit and set
 * the "error" to one. Aboiding overflow
 */
int	ft_atoi_err(int *err)
{
	*err = 1;
	return (0);
}

int	ft_atoi_strict(const char *str, int *err)
{
	int	out;
	int	chkof;
	int	sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (ft_atoi_err(err));
	out = 0;
	while (ft_isdigit(*str))
	{
		chkof = out;
		out = (out * 10) + (*(str++) - 48);
		if (out / 10 != chkof && (sign == 1 || !(out < 0 && out - 1 > 0)))
			return (ft_atoi_err(err));
	}
	if (*str)
		return (ft_atoi_err(err));
	return (sign * out);
}
