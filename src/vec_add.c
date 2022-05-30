/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:52:26 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 15:21:59 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

void	*ft_memmove(void *dst, const void *src, size_t len);
t_vec	*vec_resize_round(t_vec *vec, int new_len);

t_vec	*vec_add_n(t_vec	*vec, void *new_content, int nb_elem)
{
	vec_resize_round(vec, nb_elem);
	ft_memmove(vec->buffer + vec->size * vec->content_len, new_content,
		vec->size * nb_elem);
	vec->content_len += nb_elem;
	return (vec);
}

t_vec	*vec_add(t_vec	*vec, void *new_content)
{
	return (vec_add_n(vec, new_content, 1));
}
