/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 11:42:36 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector_template.h"

void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_round_up(size_t nb, size_t base);

static t_vec	*vec_resize_strict(t_vec *vec, size_t rate)
{
	char	*new_buffer;

	if (!vec)
		return (NULL);
	new_buffer = malloc((vec->len + rate) * vec->size);
	if (!new_buffer)
		return (NULL);
	ft_memset(new_buffer, 0, (vec->len + rate) * vec->size);
	ft_memmove(new_buffer, vec->buffer, vec->len * vec->size);
	vec->len += rate;
	free(vec->buffer);
	vec->buffer = new_buffer;
	return (vec);
}

t_vec	*vec_resize_round(t_vec *vec, size_t new_len)
{
	if (vec->content_len + new_len + 1 > vec->len)
		return (vec_resize_strict(vec, ft_round_up(new_len, vec->rate)));
	return (vec);
}

t_vec	*vec_resize(t_vec *vec)
{
	return (vec_resize_strict(vec, vec->rate));
}
