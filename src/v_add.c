/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:30 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 14:59:55 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		get_index(int index, int len);

t_vec	*v_alloc(t_vec *vec, t_alloc_opt option, size_t length);

static t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len)
{
	if (!v_alloc(vec, SET, vec->len + len))
		return (NULL);
	ft_memmove(vec->buffer + (*pos + len) * vec->size,
			vec->buffer + *pos * vec->size, (vec->len - *pos) * vec->size);
	ft_memmove(vec->buffer + *pos * vec->size, elem, len);
	vec->len += len;
	*pos += len;
	return (vec);
}

static t_vec	*v_insert_string(t_vec *vec, int pos, int option, va_list args)
{
	(void) vec;
	(void) pos;
	(void) option;
	
	va_end(args);
	return (NULL);	
}

static t_vec	*v_insert_elem(t_vec *vec, int pos, int option, va_list args)
{
	int nb = 1;
	if (option & MULTI)
		nb = va_arg(args, int);
	while (nb > 0)
	{
		if (!v_insert_utils(vec, &pos, va_arg(args, void *), 1))
			break ;
		nb--;
	}
	va_end(args);
	return (NULL);
}

t_vec	*v_insert(t_vec *vec, int pos, t_add_opt option, ...)
{
	va_list arg_list;

	va_start(arg_list, option);
	if (option & STRING)
		return (v_insert_string(vec, pos, option, arg_list));
	else
		return (v_insert_elem(vec, pos, option, arg_list));
}

t_vec	*v_add(t_vec *vec, t_add_opt option, ...)
{
	va_list arg_list;

	va_start(arg_list, option);
	if (option & STRING)
		return (v_insert_string(vec, vec->len, option, arg_list));
	else
		return (v_insert_elem(vec, vec->len, option, arg_list));
}
