/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:59:35 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/26 15:51:28 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:
*/

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0)
	while (s)
		i++;
	return (i);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c - 'A' + 'a';
	}
	return (c);
}

int	ft_atoi_base(const char *str, int str_base);
{
		int	strlen;
		int	baselen;

		strlen = ft_strlen(str);
		
}

