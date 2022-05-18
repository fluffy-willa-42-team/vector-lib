/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 12:20:30 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector-template.h"

size_t	ft_strlen(const char *s);

typedef struct s_v_option
{
	int		raw;
	int		start;
	void	*sep;
	int		sep_len;
	void	*multi_sep;
	int		multi_sep_len;
	int		nb;
}	t_v_option;

static t_v_option initOption(int optionRaw, va_list args){
	t_v_option	option;

	option.raw		 = optionRaw;
	option.start	 = 0;
	option.sep		 = (option.raw & V_SEP)		  ? va_arg(args, char *) : NULL;
	option.multi_sep = (option.raw & V_MULTI_SEP) ? va_arg(args, char *) : NULL;
	option.nb		 = (option.raw & V_MULTIPLE)  ? va_arg(args, int)	 : 0;
	option.sep_len			= ft_strlen(option.sep);
	option.multi_sep_len	= ft_strlen(option.multi_sep);
	return (option);
}


int	get_start_vec(t_vec *vec, t_v_option option){

	int len_sep = (option.raw & V_SEP) ? option.sep_len + 1 : 1;

	int i = 0;
	while (i < vec->len && !vec->buffer[vec->len - 1 - i])
		i++;
	return (i + len_sep);
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
 * @param option Options of the adding string. Options are (in order) :
 * @param V_MULTIPLE : lets you put multiple elements at the same time;
 * @param ... 
 * @return t_vec* 
 */
t_vec	*vecFill(t_vec *vec, int option, ...){
	va_list	args;
	t_v_option v_option;
	
	printf("%d\n", vec->len);
	va_start(args, option);
	v_option = initOption(option, args);
	printf("%s | %s | %d\n", v_option.sep, v_option.multi_sep, v_option.nb);
	v_option.start = get_start_vec(vec, v_option);

	va_end(args);
	return (vec);
}