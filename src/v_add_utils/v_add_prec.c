/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:43:42 by awillems          #+#    #+#             */
/*   Updated: 2022/10/14 10:09:06 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

char	*ft_strchr(const char *s, int c);

t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);

t_vec	*v_add_str_prct(t_vec *vec, int *pos);
t_vec	*v_add_str_c(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_s(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_di(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_u(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_p(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_x(t_vec *vec, int *pos, va_list args);
t_vec	*v_add_str_cap_x(t_vec *vec, int *pos, va_list args);

t_vec	*v_add_str_s_prec(t_vec *vec, int *pos, va_list args, unsigned int prec)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		if (!v_insert_utils(vec, pos, "(null)", prec))
			return (NULL);
	}
	else if (!v_insert_utils(vec, pos, str, prec))
		return (NULL);
	return (vec);
}

static unsigned int	ft_atoui(char **str)
{
	unsigned long int	res;

	res = 0;
	while (*(*str + 2) && *(*str + 2) >= '0' && *(*str + 2) <= '9')
	{
		if (res > LONG_MAX / 10 && *(*str + 2) - 48 > (LONG_MAX % 10))
			return (0);
		res = res * 10 + (*(*str + 2) - 48);
		(*str)++;
	}
	return (res);
}

t_vec	*v_add_str_prec(t_vec *vec, int *pos, va_list args, char **input)
{
	char			*save;
	const char		*options = "%cspdiuxX";
	static t_vec	*(*func[10])() = {v_add_str_prct, v_add_str_c,
		v_add_str_s_prec, v_add_str_p, v_add_str_di, v_add_str_di, v_add_str_u,
		v_add_str_x, v_add_str_cap_x};
	unsigned int	precision;

	save = *input;
	if (*(*input + 2) && *(*input + 2) == '*')
	{
		(*input)++;
		precision = va_arg(args, unsigned int);
	}
	else
		precision = ft_atoui(input);
	if (*(*input + 2) && ft_strchr(options, *(*input + 2)))
	{
		if (!func[ft_strchr(options, *(*input + 2)) - options]
			(vec, pos, args, precision))
			return (NULL);
		(*input)++;
	}
	else if (!v_insert_utils(vec, pos, save, *input - save + 2))
		return (NULL);
	return (vec);
}