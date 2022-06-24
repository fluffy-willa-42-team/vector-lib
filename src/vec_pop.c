/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:13:39 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/24 16:43:30 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

int		get_index(int index, int len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/**
 * Will pop one element in the buffer.
 *
 * @param index negative numbre supported so if vec_pop(-1) will remove the last
 *              element.
 * 
 *   [abcde]
 * pop(2)
 *   [abde\0]
 * 
 *   [0]: aaa
 *   [1]: bbb
 *   [2]: ccc
 *   [3]: ddd
 * pop(1)
 *   [0]: aaa
 *   [1]: ccc
 *   [2]: ddd
 *   [3]: \0\0\0
 * 
 */
t_vec	*vec_pop(t_vec *vec, int index)
{
	int		mem_index;
	void	*src;
	void	*dst;

	if (!vec->content_len)
		return (vec);
	mem_index = get_index(index, vec->content_len) * vec->size;
	vec->content_len--;
	src = &vec->buffer[mem_index];
	dst = &vec->buffer[mem_index + vec->size];
	ft_memmove(src, dst, vec->content_len - (mem_index));
	ft_memset(&vec->buffer[vec->content_len * vec->size], '\0', vec->size);
	return (vec);
}
