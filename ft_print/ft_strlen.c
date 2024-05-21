/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:26:53 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 08:36:06 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_strlen
** ----------------------------
** Prototype: size_t ft_strlen(const char *s);
**
** Parameters:
**    s: pointer to a string.
**
** Return value: size_t that is the length of the string
**
** External functions: none
**
** Description:
**    returns the length of the string passed in as an argument. 
*/

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

