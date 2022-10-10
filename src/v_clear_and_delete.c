/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_clear_and_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:36:43 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 13:37:25 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);

/**
 * @brief Set all buffer to `\0`.
 */
void	v_clear(t_vec *vec)
{
	ft_memset(vec->buffer, 0, vec->size * vec->alloc_len);
	vec->len = 0;
}

/**
 * @brief Free the vector and set `vec->alloc_len` to `0`.
 */
void	v_delete(t_vec *vec)
{
	vec->alloc_len = 0;
	vec->len = 0;
	free(vec->buffer);
}