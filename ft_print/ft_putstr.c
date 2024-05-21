/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:41:13 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 08:39:03 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putstr
** ----------------------------
** Prototype: void ft_putstr(char *s);
**
** Parameters:
**    s: The string to output.
**
** Return value: the number of bytes written to fd.
**
** External functions: write
**
** Description:
**    Outputs the string 's' to the given file descriptor.
*/

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	bytes;
	bytes = 0;
	if (s)
		bytes = write(1, s, ft_strlen(s));
	return (bytes);
}
