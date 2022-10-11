/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:30 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 10:45:24 by awillems         ###   ########.fr       */
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

static t_vec	*v_insert_string(t_vec *vec, int pos, char *input, va_list args)
{
	while (*input)
	{
		if (*(input + 1) && *input == '%')
		{
			if (*(input + 1) == '%')
				v_insert_utils(vec, &pos, "%", 1);
			else if (*(input + 1) == 'c')
			{
				char c = (char) va_arg(args, int);
				v_insert_utils(vec, &pos, &c, 1);
			}
			else if (*(input + 1) == 's')
			{
				char *str = va_arg(args, char*);
				v_insert_utils(vec, &pos, str, ft_strlen(str));
			}
			// else if (*(input + 1) == 'd' || *(input + 1) == 'i')
			// else if (*(input + 1) == 'u')
			// else if (*(input + 1) == 'h')
			input++;
		}
		else
			v_insert_utils(vec, &pos, input, 1);
		input++;
	}
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
	va_list args;

	va_start(args, option);
	if (option & STRING)
	{
		if (pos != 0 && option & SEP)
			v_insert_utils(vec, &pos, "", 1);
		return (v_insert_string(vec, pos, va_arg(args, char *), args));
	}
	else
		return (v_insert_elem(vec, pos, option, args));
}

t_vec	*v_add(t_vec *vec, t_add_opt option, ...)
{
	va_list args;
	int pos;

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
