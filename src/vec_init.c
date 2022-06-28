/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:34 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 13:59:22 by awillems         ###   ########.fr       */
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
	return (res);
}
