/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:51:35 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/23 14:26:07 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_striteri
** ---------------------------
** Prototype: void ft_striteri(char *s, void (*f)(unsigned int, char*));
**
** Parameters:
**    s: The string on which to iterate.
**    f: The function to apply to each character.
**
** Return value: None
**
** External functions: None
**
** Description:
**    Applies the function 'f' on each character of the string passed as an
**    argument, passing its index as the first argument. Each character is
**    passed by address to 'f' to be modified if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
