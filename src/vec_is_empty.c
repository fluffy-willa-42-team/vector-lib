/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_is_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:05:51 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 13:31:32 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

int	vec_is_empty(t_vec *vec, size_t index)
{
	size_t	i;

	if (index >= vec->len)
		return (1);
	i = 0;
	while (i < vec->size)
	{
		if (*((char *) vec->buffer + index + i) != 0)
			return (0);
		i++;
	}
	return (1);
}
