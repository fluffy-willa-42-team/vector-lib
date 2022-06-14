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
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

t_vec	*vec_cast(t_vec *vec, size_t new_size, int casting_function())
{
	const size_t old_size = vec->size;
	
	(void) casting_function;
	printf("old [%lu]   new [%lu]\n", old_size, new_size);
	if (vec->content_len * new_size >= vec->len * old_size){
		printf("%lu >= %lu\n", vec->content_len * new_size, vec->len * old_size);
		// vec_resize_strict(vec, vec->content_len * new_size + 1);
	}
	// vec->size = new_size;
	// if (new_size > old_size)
	// {
	// 	for (size_t i = vec->content_len - 1; i > 0; i++)
	// 		if (!casting_function(vec->buffer + i * old_size, vec->buffer + i * new_size))
	// 			return (NULL);
	// }
	// else
	// {
	// 	for (size_t i = 0; i < vec->content_len; i++)
	// 		if (!casting_function(vec->buffer + i * old_size, vec->buffer + i * new_size))
	// 			return (NULL);
	// 	ft_memset(vec->buffer + vec->content_len * new_size, 0, vec->content_len * (old_size - new_size));
	// }
	// vec->len = vec->len * old_size / new_size;
	return (vec);
}
