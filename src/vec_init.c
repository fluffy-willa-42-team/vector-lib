/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/05/20 15:54:24 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

t_vec	*vec_resize(t_vec *vec);
t_vec	*vec_resize_strict(t_vec *vec, int len);

static t_vec	vec_empty(int size, int rate)
{
	t_vec	res;

	res.buffer = 0;
	res.index = 0;//WIP
	res.len = 0;
	res.rate = rate;
	res.size = size;
	return (res);
}

/**
 * @brief Initialize a vector to a given length.
 * 
 * @param len Size of the buffer
 * @param size sizeof(var)
 * @param rate  The speed at which the vector grows at each resize.
 * @return t_vec 
 */
t_vec	vec_init_strict(int len, int size, int rate)
{
	t_vec	res;

	res = vec_empty(size, rate);
	if (!vec_resize_strict(&res, len))
		return (vec_empty(size, rate));
	return (res);
}

/**
 * @brief Initialize a vector.
 * 
 * @return t_vec 
 */
t_vec	vec_init(void)
{
	return (vec_init_strict(V_DEFAULT_RATE, sizeof(char), V_DEFAULT_RATE));
}
