/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:19:51 by awillems          #+#    #+#             */
/*   Updated: 2022/10/14 10:09:41 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdarg.h>

size_t	ft_strlen(const char *s);
t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);
t_vec	*v_add_itoa_base(t_vec *vec, int *pos, char *base, long number);

t_vec	*v_add_str_prct(t_vec *vec, int *pos)
{
	if (!v_insert_utils(vec, pos, "%", 1))
		return (NULL);
	return (vec);
}

t_vec	*v_add_str_c(t_vec *vec, int *pos, va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	if (!v_insert_utils(vec, pos, &c, 1))
		return (NULL);
	return (vec);
}

t_vec	*v_add_str_s(t_vec *vec, int *pos, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		if (!v_insert_utils(vec, pos, "(null)", 6))
			return (NULL);
	}
	else if (!v_insert_utils(vec, pos, str, ft_strlen(str)))
		return (NULL);
	return (vec);
}

t_vec	*v_add_str_p(t_vec *vec, int *pos, va_list args)
{
	if (!v_insert_utils(vec, pos, "0x", 2))
		return (NULL);
	return (v_add_itoa_base(vec, pos, "0123456789abcdef",
			va_arg(args, long long)));
}
