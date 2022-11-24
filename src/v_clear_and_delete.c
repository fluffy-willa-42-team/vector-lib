/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_clear_and_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:36:43 by awillems          #+#    #+#             */
/*   Updated: 2022/11/24 16:53:07 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
void	*v_getr(t_vec *vec, int index);

/**
 * @brief Set all buffer to `\0`.
 */
int	v_clear(t_vec *vec)
{
	size_t	i;

	if (vec->clear)
	{
		i = -1;
		while (++i < vec->len)
			if (!vec->clear(v_getr(vec, i)))
				return (0);
		return (1);
	}
	ft_memset(vec->buffer, 0, vec->size * vec->alloc_len);
	vec->len = 0;
	return (1);
}

/**
 * @brief Free the vector and set `vec->alloc_len` to `0`.
 * 
 * @warning When the `vec->delete` function ptr is set, `v_delete` will
 *          check each call if the function return a error (non null value).
 *         `v_delete` will directly return a non null value when `v->delete`
 *          return an error.
 *          The items in the array before the error will not be deleted.
 * 
 * @return int Null value if there are no error, otherwise return non null value.
 */
int	v_delete(t_vec *vec)
{
	size_t	i;

	if (vec->delete)
	{
		i = -1;
		while (++i < vec->len)
			if (vec->delete(v_getr(vec, i)) != 0)
				return (1);
	}
	vec->alloc_len = 0;
	vec->len = 0;
	free(vec->buffer);
	vec->buffer = NULL;
	return (0);
}
