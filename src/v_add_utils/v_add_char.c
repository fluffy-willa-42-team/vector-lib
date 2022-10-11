/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:19:51 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 12:20:34 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>

size_t	ft_strlen(const char *s);
t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);

t_vec	*v_add_str_prct(t_vec *vec, int *pos)
{
	if (!v_insert_utils(vec, pos, "%", 1))
		return (NULL);
	return (vec);
}

t_vec	*v_add_str_c(t_vec *vec, int *pos, va_list args)
{
	char c = (char) va_arg(args, int);
	if (!v_insert_utils(vec, pos, &c, 1))
		return (NULL);
	return (vec);
}

t_vec	*v_add_str_s(t_vec *vec, int *pos, va_list args)
{
	char *str = va_arg(args, char*);
	if (!v_insert_utils(vec, pos, str, ft_strlen(str)))
		return (NULL);
	return (vec);
}