/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:27:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/18 11:35:06 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putchar
** ------------------------
** Prototype: int ft_putcharchar c);
**
** Parameters:
**    c: The character to output.
**
** Return value: integer of the amount of bytes written.
**
** External functions: write
**
** Description:
**    Outputs the character 'c' to the given file descriptor. Then
**    returns the amount of bytes. On write error, i have made it return -1
**    to display the error.
*/

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	bytes;

	bytes = write(1, &c, 1);
	if (bytes == -1)
		return (-1);
	return (bytes);
}
