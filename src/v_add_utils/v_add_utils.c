/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:37:21 by awillems          #+#    #+#             */
/*   Updated: 2022/10/12 09:33:06 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
t_vec	*v_alloc(t_vec *vec, t_alloc_opt option, size_t length);

t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len)
{
	if (!v_alloc(vec, SET, vec->len + len))
		return (NULL);
	ft_memmove(vec->buffer + (*pos + len) * vec->size,
		vec->buffer + *pos * vec->size, (vec->len - *pos) * vec->size);
	ft_memmove(vec->buffer + *pos * vec->size, elem, len * vec->size);
	vec->len += len;
	*pos += len;
	return (vec);
}

t_vec	*v_add_itoa_base(t_vec *vec, int *pos, char *base, long number)
{
	const int		base_len = ft_strlen(base);
	unsigned long	n;
	int				offset;

	if (number < 0)
	{
		v_insert_utils(vec, pos, "-", 1);
		n = -number;
	}
	else
		n = number;
	if (n == 0 && !v_insert_utils(vec, pos, "0", 1))
		return (NULL);
	offset = 0;
	while (n != 0)
	{
		if (!v_insert_utils(vec, pos, &base[n % base_len], 1))
			return (NULL);
		(*pos)--;
		offset++;
		n = n / base_len;
	}
	*pos += offset;
	return (vec);
}
