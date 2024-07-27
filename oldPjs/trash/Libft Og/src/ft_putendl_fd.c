/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:45:09 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/23 14:59:53 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putendl_fd
** -----------------------------
** Prototype: void ft_putendl_fd(char *s, int fd);
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
**    Outputs the string 's' to the given file descriptor followed by a newline.
*/

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
