/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:40:37 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 15:26:43 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);

/**
 * @brief Set all buffer to `\0`.
 */
void	vec_delete(t_vec *vec)
{
	ft_memset(vec->buffer, 0, vec->size * vec->len);
	vec->content_len = 0;
}

/**
 * @brief Free the vector and set `vec->len` to `0`.
 */
void	vec_destroy(t_vec *vec)
{
	vec->len = 0;
	vec->content_len = 0;
	free(vec->buffer);
}
