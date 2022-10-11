/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:19:56 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 12:21:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>

size_t	ft_strlen(const char *s);
t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);

t_vec	*v_add_str_di(t_vec *vec, int *pos, va_list args)
{
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec	*v_add_str_u(t_vec *vec, int *pos, va_list args)
{
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}
