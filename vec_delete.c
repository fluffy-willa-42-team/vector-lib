/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:22:33 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 14:32:54 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);

void	vec_delete(t_vec *vec)
{
	vec->len = 0;
	free(vec->buffer);
}

void	vec_delete_content(t_vec *vec)
{
	ft_memset(vec->buffer, vec->len, vec->size);
}
