/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:47:20 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 13:52:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

int	get_index(int index, int len);

/**
 * @brief Returns the elem in the vector that exists.
 */
void	*v_get(t_vec *vec, int index)
{
	if (!vec || vec->len == 0)
		return (NULL);
	return (vec->buffer + get_index(index, vec->len) * vec->size);
}

/**
 * @brief Returns the spot in the memory of the vector.
 */
void	*v_getr(t_vec *vec, int index)
{
	if (!vec || index < 0 || vec->len <= (size_t) index)
		return (NULL);
	return (vec->buffer + index * vec->size);
}
