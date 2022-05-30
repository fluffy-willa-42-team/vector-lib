/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:52:26 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 13:56:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

void	*ft_memmove(void *dst, const void *src, size_t len);
t_vec	*vec_resize_round(t_vec *vec, int new_len);

t_vec	*vec_add_len(t_vec	*vec, void *new_content, int new_len)
{
	vec_resize_round(vec, new_len);
	ft_memmove(vec->buffer + vec->size * vec->content_len, new_content,
		vec->size * new_len);
	vec->content_len += new_len;
	return (vec);
}

t_vec	*vec_add(t_vec	*vec, void *new_content)
{
	return (vec_add_len(vec, new_content, 1));
}
