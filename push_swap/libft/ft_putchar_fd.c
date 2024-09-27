/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:27:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/23 14:35:10 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putchar_fd
** -----------------------------
** Prototype: void ft_putchar_fd(char c, int fd);
**
** Parameters:
**    c: The character to output.
**    fd: The file descriptor on which to write.
**
** Return value: None
**
** External functions: write
**
** Description:
**    Outputs the character 'c' to the given file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
