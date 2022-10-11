/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:30 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 12:04:50 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


void	*ft_memmove(void *dst, const void *src, size_t len);
int		get_index(int index, int len);
char	*ft_strchr(const char *s, int c);

t_vec	*v_add_str_prct(t_vec *vec, int *pos);
t_vec	*v_add_str_c(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_s(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_di(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_u(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_p(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_x(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_cap_x(t_vec *vec, int *pos, va_list args);

t_vec	*v_alloc(t_vec *vec, t_alloc_opt option, size_t length);

t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len)
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

static t_vec	*v_insert_string(t_vec *vec, int pos, char *input, va_list args)
{
	const char		*options = "%cspdiuxX";
	static t_vec	*(*func[10])() = {v_add_str_prct, v_add_str_c, v_add_str_s,
		v_add_str_p, v_add_str_di, v_add_str_di, v_add_str_u, v_add_str_x,
		v_add_str_cap_x};

	while (*input)
	{
		if (*(input + 1) && *input == '%' && ft_strchr(options, *(input + 1)))
		{
			if (!func[ft_strchr(options, *(input + 1)) - options]
				(vec, &pos, args))
				break ;
			input++;
		}
		else if (!v_insert_utils(vec, &pos, input, 1))
			break ;
		input++;
	}
	va_end(args);
	if (*input != 0)
		return (NULL);
	return (vec);
}

static t_vec	*v_insert_elem(t_vec *vec, int pos, int option, va_list args)
{
	int	nb;

	nb = 1;
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
	va_list	args;

	va_start(args, option);
	if (option & STRING)
	{
		if (pos != 0 && option & SEP && !v_insert_utils(vec, &pos, "", 1))
			return (NULL);
		return (v_insert_string(vec, pos, va_arg(args, char *), args));
	}
	else
		return (v_insert_elem(vec, pos, option, args));
}

t_vec	*v_add(t_vec *vec, t_add_opt option, ...)
{
	va_list	args;
	int		pos;

	va_start(args, option);
	if (option & STRING)
	{
		pos = vec->len;
		if (pos != 0 && option & SEP)
			v_insert_utils(vec, &pos, "", 1);
		return (v_insert_string(vec, pos, va_arg(args, char *), args));
	}
	else
		return (v_insert_elem(vec, vec->len, option, args));
}