/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:17:03 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 12:28:24 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdio.h>

t_vec	*vec_resize(t_vec *vec);

int	is_zero(void *mem_raw, int size)
{
	unsigned char	*mem;
	int				i;

	mem = (unsigned char *) mem_raw;
	i = 0;
	while (i < size)
	{
		if (mem[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief [internal] Get the first writable character inside the vector and will
 * expand the vector if needed
 */
static int	get_start_vec(t_vec *vec)
{
	int	res;

	if (!vec->buffer)
		vec_resize(vec);
	res = vec->len - 1;
	while (res > 0 && is_zero(vec->buffer, vec->size))
		res--;
	while (vec->len < res)
		vec_resize(vec);
	return (res);
}

t_vec	*vec_add(t_vec *vec)
{
	// printf("=> %d\n", get_start_vec(vec));
	return (vec);
}
