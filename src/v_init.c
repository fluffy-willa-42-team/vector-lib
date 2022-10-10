/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 12:15:11 by awillems         ###   ########.fr       */
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
	res.clear = NULL;
	res.delete = NULL;
	return (res);
}

t_vec	v_init_r(size_t size, int (*clear)(), int (*delete)(), size_t rate);
{
	res.size = size;
	res.rate = rate;
	res.clear = clear;
	res.delete = delete;
	return (empty_vec());
}

t_vec	v_init(size_t size, int (*clear)(), int (*delete)());
{
	return (v_init_r(size, clear, delete));
}
