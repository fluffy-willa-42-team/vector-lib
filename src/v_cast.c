/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:21:31 by awillems          #+#    #+#             */
/*   Updated: 2022/10/12 11:20:23 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdio.h>

t_vec	*v_alloc(t_vec *vec, t_alloc_opt option, size_t length);

t_vec	*v_cast(t_vec *vec, size_t new_size, int casting_function())
{
	const size_t	old_size = vec->size;
	long	i;

	if (!vec || !casting_function)
		return (NULL);
	if (new_size > old_size)
		v_alloc(vec, SET, new_size / old_size * vec->len);
	i = (int []){vec->len - 1, 0}[new_size <= old_size];
	while ((int []){i >= 0, i < (long) vec->len}[new_size <= old_size])
	{
		if (!casting_function(vec->buffer + i * old_size, vec->buffer + i * new_size))
			return (NULL);
		i += (int []){-1, 1}[new_size <= old_size];
	}
	vec->alloc_len = vec->alloc_len * old_size / new_size;
	vec->size = new_size;
	return (vec);
}
