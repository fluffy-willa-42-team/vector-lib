/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:19:53 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 13:43:56 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>

t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);
t_vec	*v_add_itoa_base(t_vec *vec, int *pos, char *base, long number);

t_vec	*v_add_str_p(t_vec *vec, int *pos, va_list args)
{
	if (!v_insert_utils(vec, pos, "0x", 2))
		return (NULL);
	return (v_add_itoa_base(vec, pos, "0123456789abcdef", va_arg(args, long long)));
}

t_vec	*v_add_str_x(t_vec *vec, int *pos, va_list args)
{
	return (v_add_itoa_base(vec, pos, "0123456789abcdef", va_arg(args, int)));
}

t_vec	*v_add_str_cap_x(t_vec *vec, int *pos, va_list args)
{
	return (v_add_itoa_base(vec, pos, "0123456789ABCDEF", va_arg(args, int)));
}
