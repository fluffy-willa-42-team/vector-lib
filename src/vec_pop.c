/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:13:39 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/28 11:30:22 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stddef.h>

int		get_index(int index, int len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/**
 * Will pop one element in the buffer.
 * [abcde] -> pop(2) -> [abde\0]
 *
 * @param index negative numbre are supported so if vec_pop(-1) will remove the
 * last element.
 * @return t_vec * Return the `vec` ptr, `NULL` if the content len is `0`.
 */
t_vec	*vec_pop(t_vec *vec, int index)
{
	int		mem_index;
	void	*src;
	void	*dst;

	if (!vec->content_len)
		return (NULL);
	mem_index = get_index(index, vec->content_len) * vec->size;
	vec->content_len--;
	src = vec->buffer + mem_index;
	dst = vec->buffer + mem_index + vec->size;
	ft_memmove(src, dst, (vec->content_len * vec->size) - mem_index);
	ft_memset(vec->buffer + vec->content_len * vec->size, '\0', vec->size);
	return (vec);
}
