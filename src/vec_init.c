/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 16:10:11 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-template.h"

static t_vec	vecEmpty(void)
{
	t_vec	res;

	res.buffer = 0;
	res.len = 0;
	res.size = 0;
	return (res);
}

t_vec vecInitStrict(int size){
	t_vec	res;
	
	res = vecEmpty();
	(void) size;
	return (res);
}

t_vec vecInit(void){
	return (vecInitStrict(VECTOR_SIZE));
}