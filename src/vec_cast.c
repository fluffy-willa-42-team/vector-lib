/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 11:00:32 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include "stdio.h"

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

t_vec	*vec_cast(t_vec *vec, size_t new_size, void *casting_function(void *))
{
	(void) casting_function;
	if (vec->content_len * new_size >= vec->len)
		vec_resize_round(vec, vec->content_len * new_size);
	if (new_size > vec->size)
	{
		printf("%lu > %lu (<=)\n", new_size, vec->size);
		for (size_t i = 0; i < vec->content_len; i++)
		{
			ft_memmove(vec->buffer + (vec->content_len - i - 1) * new_size,
				casting_function(vec->buffer + i * vec->size),
				new_size);
		}
	}
	else
	{
		printf("%lu <= %lu (=>)\n", new_size, vec->size);
		for (size_t i = 0; i < vec->content_len; i++)
		{
			ft_memmove(vec->buffer + i * new_size,
				casting_function(vec->buffer + i * vec->size),
				new_size);
		}
	}
	return (vec);
}