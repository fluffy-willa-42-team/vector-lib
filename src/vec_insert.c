/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:53:18 by awillems          #+#    #+#             */
/*   Updated: 2022/05/19 12:06:16 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "vector_template.h"

int	get_start_vec(t_vec *vec, int str_len, int sep_len);

t_vec	*vec_insert(t_vec *vec, char *str, int index)
{
	int	start;
	int	len;

	if (!vec)
		return (NULL);
	if (!str || index < 0)
		return (vec);
	len = ft_strlen(str);
	start = get_start_vec(vec, len, 0);
	ft_memmove(vec->buffer + index + len, vec->buffer + index, vec->size - len);
	ft_memmove(vec->buffer + index, str, len);
}
