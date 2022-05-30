/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 15:44:49 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

t_vec	empty_vec(void)
{
	t_vec	res;

	res.len = 0;
	res.size = 0;
	res.rate = 0;
	res.content_len = 0;
	res.buffer = NULL;
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
