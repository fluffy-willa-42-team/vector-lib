/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 09:30:17 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);

t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

typedef struct s_vf_option
{
	va_list	arg_list;
	size_t	option;
	char	*sep;
	size_t	sep_len;
	char	*multi_sep;
	size_t	multi_sep_len;
	size_t	nb;
	size_t	i;
	char	*str;
	size_t	len;
}	t_vf_option;

static void	init_sep_opt(t_vf_option *opt, int option, char **ptr, size_t *len)
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

static void	init_option(t_vf_option *opt, size_t option)
{
	opt->nb = 1;
	opt->option = option;
	init_sep_opt(opt, SEP, &opt->sep, &opt->sep_len);
	init_sep_opt(opt, SEP, &opt->multi_sep, &opt->multi_sep_len);
	if (option & MULTI)
		opt->nb = va_arg(opt->arg_list, size_t);
}

static void	add_elem_in_vec(t_vec *vec, char *src, size_t len)
{
	vec_resize_round(vec, len);
	ft_memmove(vec->buffer + vec->content_len, src, len);
	vec->content_len += len;
}

t_vec	*vec_fill(t_vec *vec, t_fill_opt option, ...)
{
	t_vf_option	opt;

	va_start(opt.arg_list, option);
	init_option(&opt, option);
	if (vec->content_len != 0)
		add_elem_in_vec(vec, opt.sep, opt.sep_len);
	opt.i = 0;
	while (opt.i < opt.nb)
	{
		opt.str = va_arg(opt.arg_list, char *);
		if (option & FIXED_LEN)
			opt.len = va_arg(opt.arg_list, int);
		else
			opt.len = ft_strlen(opt.str);
		if (opt.i != 0)
			add_elem_in_vec(vec, opt.multi_sep, opt.multi_sep_len);
		add_elem_in_vec(vec, opt.str, opt.len);
		opt.i++;
	}
	va_end(opt.arg_list);
	return (vec);
}
