/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:41:13 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 16:30:22 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putstr_fd
** ----------------------------
** Prototype: void ft_putstr_fd(char *s, int fd);
**
** Parameters:
**    s: The string to output.
**    fd: The file descriptor on which to write.
**
** Return value: None
**
** External functions: write
**
** Description:
**    Outputs the string 's' to the given file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
