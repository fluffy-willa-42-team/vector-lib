/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:17:03 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 11:58:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdio.h>

t_vec	*vec_resize(t_vec *vec);

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
	while (res > 0 && vec->buffer[res - 1]) //TODO 
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
