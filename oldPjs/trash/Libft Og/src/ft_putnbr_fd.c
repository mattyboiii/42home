/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:00:30 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/25 11:08:16 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_putnbr_fd
 ** ----------------------------
 ** Prototype: void ft_putnbr_fd(int n, int fd);
 **
 ** Parameters:
 **    n: The integer to output.
 **    fd: The file descriptor on which to write.
 **
 ** Return value: None
 **
 ** External functions: write
 **
 ** Description:
 **    Outputs the integer 'n' to the given file descriptor.
 */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -10)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(((n / 10) * -1), fd);
		ft_putchar_fd(((n % 10) * -1 + '0'), fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

