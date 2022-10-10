/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:57:04 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 13:36:52 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

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
