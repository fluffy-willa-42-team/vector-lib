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

t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

t_vec	*vec_cast(t_vec *vec, size_t new_size, void *casting_function(void *))
{
	const size_t old_size = vec->size;
	(void) vec;
	(void) new_size;
	(void) casting_function;
	(void) old_size;
	printf("new size : %zu\n", new_size);
	if (vec->content_len * new_size >= vec->len)
		vec_resize_round(vec, vec->content_len * new_size);
	return (vec);
}