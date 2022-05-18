/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 09:19:40 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector-template.h"

typedef struct s_v_option
{
	int		raw;
	int		start;
	char	*sep;
	char	*multi_sep;
	int		nb;
}	t_v_option;

static t_v_option initOption(int optionRaw, va_list args){
	t_v_option	option;

	option.raw		 = optionRaw;
	option.start	 = 0;
	option.sep		 = (option.raw & V_SEP)		  ? va_arg(args, char *) : NULL;
	option.multi_sep = (option.raw & V_MULTI_SEP) ? va_arg(args, char *) : NULL;
	option.nb		 = (option.raw & V_MULTIPLE)  ? va_arg(args, int)	 : 0;
	return (option);
}

int	get_start_vec(t_vec *vec, t_v_option option){
	int i = 0;

	if (option.raw & V_SEP){
		while (i < vec->len - 1 && vec->buffer[i] && !vec->buffer[i+1])
			i++;
	}
	else {
		while (i < vec->len - 2 && !vec->buffer[i+2] && vec->buffer[i] && !vec->buffer[i+1])
			i++;
	}
	return (i);
}



/**
 * vecFill(vec, V_DEFAULT, string)
 * vecFill(vec, V_SEP, separateur, string)
 * 
 * vecFill(vec, V_MULTIPLE, number, string, ...)
 * vecFill(vec, V_MULTIPLE | V_SEP, separateur, number, string, ...)
 * vecFill(vec, V_MULTIPLE | V_SEP | V_MULTI_SEP, separateur, separateur, number, string, ...)
 * 
 * fill(hello)
 * fill(world)
 * [ , /]
 * 
 * [hello world.........]
 */

/**
 * @brief Add string(s) to a the given vector.
 * 
 * @param vec The vector where the string will be added.
 * @param option Options of the adding string.
 * @param ... 
 * @return t_vec* 
 */
t_vec	*vecFill(t_vec *vec, int option, ...){
	va_list	args;
	t_v_option v_option;
	
	va_start(args, option);
	v_option = initOption(option, args);
	printf("%s | %s | %d\n", v_option.sep, v_option.multi_sep, v_option.nb);
	v_option.start = get_start_vec(vec, v_option);

	va_end(args);
	return (vec);
}