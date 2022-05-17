/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:55 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 16:12:34 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector-lib.h"

t_vec	*vecResizeStrict(t_vec *vec, int size){
	(void) size;
	if (!vec)
		return (NULL);
	return (vec);
}

t_vec	*vecResize(t_vec *vec){
	return (vecResizeStrict(vec, vec->len + VECTOR_SIZE));
}