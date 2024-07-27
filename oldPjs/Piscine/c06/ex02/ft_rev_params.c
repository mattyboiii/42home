/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 07:43:25 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/06 17:19:11 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	c;

	c = argc;
	if (argc > 1)
	{
		while (c > 1)
		{
			i = 0;
			while (argv[c - 1][i] != '\0')
			{
				write(1, &argv[c - 1][i], 1);
				i++;
			}
			write(1, "\n", 1);
			c--;
		}
	}
	return (0);
}
