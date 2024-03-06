/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:58:17 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/06 11:30:33 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
int main()
{
	printf("ft_isalpha A %d", ft_isalpha('A'));
	printf("\nft_isalpha a %d", ft_isalpha('a'));
	printf("\nft_isalpha 1 %d", ft_isalpha('1'));
	printf("\nft_isalpha 0 %d", ft_isalpha('0'));
	printf("\nisalpha A %d", isalpha('A'));
	printf("\nisalpha a %d", isalpha('a'));
	printf("\nisalpha 1 %d", isalpha('1'));
	printf("\nisalpha 0 %d", isalpha('0'));
}
*/
