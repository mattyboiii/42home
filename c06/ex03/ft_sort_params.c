/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:22:13 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/01 09:03:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>



int	main(int argc, *char argv)
{
	int i;
	int c;
	int l;
	char *temp;
	char order[];

	if (argc > 1)
	{
		l = 1;
		while (v < argc)
		{
			i = 0;
			c = 1;
			while (argv[c][i] != '\0' || argv[c + c][i] != '\0')
			{
				if (argv[c][i] < argv[c + c][i])
				{
					order[l` - 1] = *argv[c];
				}
				else
					order[l - 1] = *argv[c + c];

			}
		}
	}
	
}

