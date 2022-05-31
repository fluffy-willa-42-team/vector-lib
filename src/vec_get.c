/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:33:19 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 08:15:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

int	get_index(int index, int len);

void	*vec_get(t_vec *vec, int index)
{
	if (vec->content_len == 0)
		return (NULL);
	return (vec->buffer + get_index(index, vec->content_len) * vec->size);
}
