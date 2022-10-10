/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:57:04 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 13:33:19 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_round_up(size_t nb, size_t base);

t_vec	*v_alloc(t_vec *vec, t_alloc_opt option, size_t length)
{
	size_t	new_len;
	char	*new_buf;

	new_len = ft_round_up((size_t [])
		{length, vec->len + length}[option & TRUNC], vec->rate);
	if (new_len < vec->alloc_len)
		return (vec);
	new_buf = malloc(new_len * vec->size);
	if (!new_buf)
		return (NULL);
	ft_memset(new_buf, 0, new_len * vec->size);
	ft_memmove(new_buf, vec->buffer, vec->alloc_len * vec->size);
	vec->alloc_len = new_len;
	free(vec->buffer);
	vec->buffer = new_buf;
	return (vec);
}





// static t_vec	*vec_resize_strict(t_vec *vec, size_t rate)
// {
// 	char	*new_buffer;

// 	if (!vec)
// 		return (NULL);
// 	new_buffer = malloc((vec->alloc_len + rate) * vec->size);
// 	if (!new_buffer)
// 	{
// 		if (vec->exit_func)
// 			vec->exit_func();
// 		return (NULL);
// 	}
// 	ft_memset(new_buffer, 0, (vec->alloc_len + rate) * vec->size);
// 	ft_memmove(new_buffer, vec->buffer, vec->alloc_len * vec->size);
// 	vec->alloc_len += rate;
// 	free(vec->buffer);
// 	vec->buffer = new_buffer;
// 	return (vec);
// }

// t_vec	*vec_resize_round(t_vec *vec, size_t new_len)
// {
// 	if (vec->len + new_len + 1 > vec->alloc_len)
// 		return (vec_resize_strict(vec, ft_round_up(new_len, vec->rate)));
// 	return (vec);
// }

// t_vec	*vec_resize(t_vec *vec)
// {
// 	return (vec_resize_strict(vec, vec->rate));
// }