/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:42 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/20 11:17:49 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}
/*
int main()
{
	printf("ft_isalnum A %d", ft_isalnum('A'));
	printf("\nft_isalnum ; %d", ft_isalnum(';'));
	printf("\nft_isalnum ( %d", ft_isalnum('('));
	printf("\nft_isalnum 0 %d", ft_isalnum('0'));
	printf("\nisalnum A %d", isalnum('A'));
	printf("\nisalnum ; %d", isalnum(';'));
	printf("\nisalnum ( %d", isalnum('('));
	printf("\nisalnum 0 %d", isalnum('0'));
}
*/
