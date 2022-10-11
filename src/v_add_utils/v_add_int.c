/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:19:56 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 14:30:50 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdarg.h>

t_vec	*v_add_itoa_base(t_vec *vec, int *pos, char *base, long number);

t_vec	*v_add_str_di(t_vec *vec, int *pos, va_list args)
{
	return (v_add_itoa_base(vec, pos, "0123456789", va_arg(args, int)));
}

t_vec	*v_add_str_u(t_vec *vec, int *pos, va_list args)
{
	return (v_add_itoa_base(vec, pos, "0123456789",
			va_arg(args, unsigned int)));
}

t_vec	*v_add_str_x(t_vec *vec, int *pos, va_list args)
{
	return (v_add_itoa_base(vec, pos, "0123456789abcdef", va_arg(args, int)));
}

t_vec	*v_add_str_cap_x(t_vec *vec, int *pos, va_list args)
{
	return (v_add_itoa_base(vec, pos, "0123456789ABCDEF", va_arg(args, int)));
}
