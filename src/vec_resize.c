/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:55 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 16:31:26 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector-lib.h"

void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

t_vec	*vecResizeStrict(t_vec *vec, int len){
	char	*newBuffer;

	if (!vec)
		return (NULL);
	if (len < vec->len)
		return (vec);
	newBuffer = malloc((vec->len + len) * vec->size);
	if (!newBuffer)
		return (NULL);
	ft_memset(newBuffer, 0, (vec->len + len) * vec->size);
	ft_memmove(newBuffer, vec->buffer, vec->len * vec->size);
	vec->len += len; 
	return (vec);
}

t_vec	*vecResize(t_vec *vec){
	return (vecResizeStrict(vec, vec->len + VECTOR_SIZE));
}