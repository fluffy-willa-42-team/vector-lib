/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_clear_and_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:36:43 by awillems          #+#    #+#             */
/*   Updated: 2022/10/14 10:15:17 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
void	*v_getr(t_vec *vec, int index);

/**
 * @brief Set all buffer to `\0`.
 */
int	v_clear(t_vec *vec)
{
	size_t	i;

	if (vec->clear)
	{
		i = -1;
		while (++i < vec->len)
			if (!vec->clear(v_getr(vec, i)))
				return (0);
		return (1);
	}
	ft_memset(vec->buffer, 0, vec->size * vec->alloc_len);
	vec->len = 0;
	return (1);
}

/**
 * @brief Free the vector and set `vec->alloc_len` to `0`.
 */
int	v_delete(t_vec *vec)
{
	size_t	i;

	if (vec->delete)
	{
		i = -1;
		while (++i < vec->len)
			vec->delete(v_getr(vec, i));
	}
	vec->alloc_len = 0;
	vec->len = 0;
	free(vec->buffer);
	vec->buffer = NULL;
	return (1);
}
