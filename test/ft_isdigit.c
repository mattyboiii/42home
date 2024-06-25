/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:58:17 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/06 11:51:56 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int main()
{
	printf("ft_isdigit A %d", ft_isdigit('A'));
	printf("\nft_isdigit a %d", ft_isdigit('a'));
	printf("\nft_isdigit 1 %d", ft_isdigit('1'));
	printf("\nft_isdigit 0 %d", ft_isdigit('0'));
	printf("\nisdigit A %d", isdigit('A'));
	printf("\nisdigit a %d", isdigit('a'));
	printf("\nisdigit 1 %d", isdigit('1'));
	printf("\nisdigit 0 %d", isdigit('0'));
}
*/
