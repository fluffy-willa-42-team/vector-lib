/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:30 by awillems          #+#    #+#             */
/*   Updated: 2022/10/14 09:13:26 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdarg.h>

/*
v_add    0 - 0	v_insert_elem	0
		  \ /					 \   
		   X					  0 - > v_insert_utils
		  / \					 /
v_insert 0 - 0	v_insert_string	0
*/

static t_vec	*v_insert_string(t_vec *vec, int pos, char *input, va_list args)
{
	const char		*options = "%cspdiuxX.";
	static t_vec	*(*func[10])() = {v_add_str_prct, v_add_str_c, v_add_str_s,
		v_add_str_p, v_add_str_di, v_add_str_di, v_add_str_u, v_add_str_x,
		v_add_str_cap_x, v_add_str_prec};

	while (*input)
	{
		if (*(input + 1) && *input == '%' && ft_strchr(options, *(input + 1)))
		{
			if (!func[ft_strchr(options, *(input + 1)) - options]
				(vec, &pos, args, &input))
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
		{
			va_end(args);
			return (NULL);
		}
		nb--;
	}
	va_end(args);
	return (vec);
}

t_vec	*v_insert(t_vec *vec, int pos, t_add_opt option, ...)
{
	va_list	args;

	va_start(args, option);
	if (option & STRING)
	{
		if (pos != 0 && option & SEP && !v_insert_utils(vec, &pos, "", 1))
			return (NULL);
		return (v_insert_string(vec, get_index(pos, vec->len),
				va_arg(args, char *), args));
	}
	else
		return (v_insert_elem(vec, get_index(pos, vec->len), option, args));
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
