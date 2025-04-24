/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_with_capacity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:02 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 14:05:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecnew_with_capacity(size_t capacity, size_t elem_size)
{
	t_vector	*out;

	out = malloc(sizeof(t_vector));
	out->_elem_size = elem_size;
	out->length = 0;
	out->_capacity = capacity;
	out->data = malloc(out->_capacity * out->_elem_size);
	return (out);
}
