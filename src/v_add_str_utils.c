/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:49:27 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 11:26:23 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
t_vec	*v_insert_utils(t_vec *vec, int *pos, void *elem, size_t len);

t_vec *v_add_str_prct(t_vec *vec, int *pos)
{
	printf("%%\n");
	if (!v_insert_utils(vec, pos, "%", 1))
		return (NULL);
	return (vec);
}
				
t_vec *v_add_str_c(t_vec *vec, int *pos, va_list args)
{
	printf("c\n");
	char c = (char) va_arg(args, int);
	if (!v_insert_utils(vec, pos, &c, 1))
		return (NULL);
	return (vec);
}

t_vec *v_add_str_s(t_vec *vec, int *pos, va_list args)
{
	printf("s\n");
	char *str = va_arg(args, char*);
	if (!v_insert_utils(vec, pos, str, ft_strlen(str)))
		return (NULL);
	return (vec);
}

t_vec *v_add_str_di(t_vec *vec, int *pos, va_list args)
{
	printf("di\n");
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec *v_add_str_u(t_vec *vec, int *pos, va_list args)
{
	printf("u\n");
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec *v_add_str_p(t_vec *vec, int *pos, va_list args)
{
	printf("p\n");
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec *v_add_str_x(t_vec *vec, int *pos, va_list args)
{
	printf("x\n");
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}

t_vec *v_add_str_cap_x(t_vec *vec, int *pos, va_list args)
{
	printf("X\n");
	(void) vec;
	(void) pos;
	(void) args;
	return (NULL);
}
