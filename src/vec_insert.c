/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:53:18 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 10:36:00 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "vector_template.h"

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		g_start_vec(t_vec *vec, int str_len, int sep_len, char *sep);

t_vec	*vec_resize(t_vec *vec);

t_vec	*vec_insert(t_vec *vec, char *str, int index)
{
	int	start;
	int	len;

	if (!vec)
		return (NULL);
	if (!str || index < 0)
		return (vec);
	len = ft_strlen(str);
	start = g_start_vec(vec, len, 0, NULL);
	while (vec->len < start + len + 1)
		vec_resize(vec);
	ft_memmove(vec->buffer + index + len, vec->buffer + index, vec->size - len);
	ft_memmove(vec->buffer + index, str, len);
	return (vec);
}
