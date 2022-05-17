/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 22:18:26 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector-template.h"

int	get_start_vec(t_vec *vec, int option){
	int i = 0;

	if (option & V_SKIP){
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
 * vecFill(vec, V_SKIP, separateur, string)
 * 
 * vecFill(vec, V_MULTIPLE, number, string, ...)
 * vecFill(vec, V_MULTIPLE | V_SKIP, separateur, number, string, ...)
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
	char *sep;
	int	start = get_start_vec(vec, option);
	printf("%d\n", start);
	
	if (option & V_SKIP)
		printf("WITH SKIPS\n");
	if (option & V_SEPATOR)
		printf("WITH SEPARATOR\n");
	if (option & V_MULTIPLE)
		printf("WITH MULTIPLE\n");
	
	va_start(args, option);
	if (!(option & V_SEPATOR))
		sep = va_arg(args, char *);
	// if (!(option & V_SEPATOR))
	// 	char *sep = va_arg(args, char *);
	va_end(args);
	return (vec);
}