/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:19:53 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 12:21:52 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>

size_t	ft_strlen(const char *s);
t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);

t_vec	*v_add_str_p(t_vec *vec, int *pos, va_list args)
{
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec	*v_add_str_x(t_vec *vec, int *pos, va_list args)
{
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec	*v_add_str_cap_x(t_vec *vec, int *pos, va_list args)
{
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}
