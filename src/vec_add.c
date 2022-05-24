/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:17:03 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 13:12:22 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdio.h>

int		is_zero(void *mem_raw, int size);
void	*ft_memmove(void *dst, const void *src, size_t len);

t_vec	*vec_resize(t_vec *vec);
void	*vec_get(t_vec *vec, int index);

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
	while (res > 0 && is_zero(vec_get(vec, res - 1), vec->size))
		res--;
	while (vec->len < res)
		vec_resize(vec);
	return (res);
}

t_vec	*vec_add(t_vec *vec, void *elem)
{
	int	start;

	start = get_start_vec(vec);
	ft_memmove(vec->buffer + (start * vec->size), elem, vec->size);
	return (vec);
}
