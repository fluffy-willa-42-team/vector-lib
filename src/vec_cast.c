/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 11:26:38 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

t_vec	*vec_resize_cast(t_vec *vec, size_t new_size)
{
	char	*new_buffer;

	if ((vec->content_len + 1) * new_size > vec->len * vec->size)
	{
		if (!vec)
			return (NULL);
		new_buffer = malloc(vec->len * new_size);
		if (!new_buffer)
			return (NULL);
		ft_memset(new_buffer, 0, vec->len * new_size);
		ft_memmove(new_buffer, vec->buffer, vec->content_len * vec->size);
		free(vec->buffer);
		vec->buffer = new_buffer;
	}
	else
		vec->len = (vec->len * vec->size) / new_size;
	vec->size = new_size;
	return (vec);
}

t_vec	*vec_cast(t_vec *vec, size_t new_size, int casting_function())
{
	const size_t	old_size = vec->size;
	long			i;

	if (!vec_resize_cast(vec, new_size))
		return (NULL);
	i = (int []){vec->content_len - 1, 0}[new_size <= old_size];
	while ((int []){i >= 0, i < (long) vec->content_len}[new_size <= old_size])
	{
		if (!casting_function(vec->buffer + i * old_size,
				vec->buffer + i * new_size))
			return (NULL);
		i += (int []){-1, 1}[new_size <= old_size];
	}
	if (new_size <= old_size)
		ft_memset(vec->buffer + vec->content_len * new_size, 0,
			vec->content_len * (old_size - new_size));
	return (vec);
}
