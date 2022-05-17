/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 20:57:25 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-template.h"

t_vec	*vecResize(t_vec *vec);
t_vec	*vecResizeStrict(t_vec *vec, int len);

static t_vec	vecEmpty(int size)
{
	t_vec	res;

	res.buffer = 0;
	res.len = 0;
	res.size = size;
	return (res);
}

t_vec vecInitStrict(int len, int size){
	t_vec	res;
	
	res = vecEmpty(size);
	
	if (!vecResizeStrict(&res, len))
		return (vecEmpty(size));
	return (res);
}

t_vec vecInit(int size){
	return (vecInitStrict(VECTOR_SIZE, size));
}