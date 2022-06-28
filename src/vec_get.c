/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:33:19 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 13:58:37 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

int	get_index(int index, int len);

/**
 * @brief Returns the elem in the vector that exists.
 */
void	*vec_get(t_vec *vec, int index)
{
	if (!vec && get_index(index, vec->len) == -1)
		return (NULL);
	return (vec->buffer + get_index(index, vec->len) * vec->size);
}

/**
 * @brief Returns the spot in the memory of the vector.
 */
void	*vec_get_raw(t_vec *vec, int index)
{
	return (vec->buffer + index * vec->size);
}
