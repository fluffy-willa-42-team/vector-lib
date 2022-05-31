/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:20:03 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 08:56:48 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);

t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

typedef struct s_vi_option {
	va_list	arg_list;
	size_t	option;
	char	*sep;
	size_t	sep_len;
	char	*multi_sep;
	size_t	multi_sep_len;
	size_t	nb;
}	t_vi_option;

static void	init_sep_opt(t_vi_option *opt, int option, char **ptr, size_t *len)
{
	*ptr = NULL;
	*len = 0;
	if (!(opt->option & option))
		return ;
	*ptr = va_arg(opt->arg_list, char *);
	*len = ft_strlen(*ptr);
	if (*len != 0)
		return ;
	*ptr = "";
	*len = 1;
}

static void	init_option(t_vi_option *opt, size_t option)
{
	opt->nb = 1;
	opt->option = option;
	init_sep_opt(opt, SEP, &opt->sep, &opt->sep_len);
	init_sep_opt(opt, SEP, &opt->multi_sep, &opt->multi_sep_len);
	if (option & MULTI)
		opt->nb = va_arg(opt->arg_list, size_t);
}

t_vec	*vec_insert(t_vec *vec, t_fill_opt option, ...)
{
	t_vi_option	opt;
	
	va_start(opt.arg_list, option);
	init_option(&opt, option);
	printf("%zu\n", opt.nb);
	printf("%s (%zu)\n", opt.sep, opt.sep_len);
	printf("%s (%zu)\n", opt.multi_sep, opt.multi_sep_len);
	va_end(opt.arg_list);
	return (vec);
}