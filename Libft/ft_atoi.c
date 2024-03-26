/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:38:14 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 10:30:38 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//     The atoi() function converts the initial portion of the string
//     pointed to by str to int representation.
//
//     It is equivalent to:
//
//           (int)strtol(str, (char **)NULL, 10);
//
//    While the atoi() function uses the current locale, the atoi_l()
//    function may be passed a locale directly. See xlocale(3) for more
//    information.
//
// IMPLEMENTATION NOTES
//     The atoi() and atoi_l() functions are thread-safe and async-cancel-
//     safe.
//
//     The strtol() and strtol_l() functions are recommended instead of
//     atoi() and atoi_l() functions, especially in new code.

// Recommendation:
// To recreate the atoi() function, you would essentially need to implement
// a function that takes a string as input, parses it, and converts it into
// an integer. You can follow the approach of strtol(), parsing the string
// and converting it into an integer based on your requirements.

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	ft_ctod(const char num)
{
	return ((int)num - '0');
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!ft_isdigit(*str))
		while (!ft_isdigit(*str))
			str++;
	else
	{
		res = 0;
		while (ft_isdigit(*str))
			res = res * 10 + (ft_ctod(*str++));
	}
	return (res *= sign);
}
