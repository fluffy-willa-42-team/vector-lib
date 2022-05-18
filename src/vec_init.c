/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 12:24:16 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-template.h"

t_vec	*vecResize(t_vec *vec);
t_vec	*vecResizeStrict(t_vec *vec, int len);

static t_vec	vecEmpty(int size, int rate)
{
	t_vec	res;

	res.buffer = 0;
	res.len = 0;
	res.rate = rate;
	res.size = size;
	return (res);
}

/**
 * @brief Initialize a vector to a given length.
 * 
 * @param len 
 * @param size 
 * @param rate 
 * @return t_vec 
 */
t_vec vecInitStrict(int len, int size, int rate){
	t_vec	res;
	
	res = vecEmpty(size, rate);
	
	if (!vecResizeStrict(&res, len))
		return (vecEmpty(size, rate));
	return (res);
}

/**
 * @brief Initialize a vector.
 * 
 * @return t_vec 
 */
t_vec vecInit(){
	return (vecInitStrict(V_DEFAULT_RATE, sizeof(char), V_DEFAULT_RATE));
}