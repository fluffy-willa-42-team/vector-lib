/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 16:52:59 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

t_vec	empty_vec(void)
{
	t_vec	res;

	res.len = 0;
	res.size = 0;
	res.rate = 0;
	res.alloc_len = 0;
	res.buffer = NULL;
	res.exit_func = NULL;
	return (res);
}

t_vec	vec_init(size_t size)
{
	t_vec	res;

	res = empty_vec();
	res.size = size;
	res.rate = V_DEFAULT_RATE;
	return (res);
}

t_vec	vec_init_r(size_t size, size_t rate)
{
	t_vec	res;

	res = empty_vec();
	res.size = size;
	res.rate = rate;
	return (res);
}
