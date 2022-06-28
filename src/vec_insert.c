/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:20:03 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 13:58:37 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"

#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		get_index(int index, int len);

t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

typedef struct s_vi_option {
	va_list	arg_list;
	size_t	index;	
	size_t	option;
	char	*sep;
	size_t	sep_len;
	char	*multi_sep;
	size_t	multi_sep_len;
	size_t	nb;
	char	*str;
	size_t	len;
	size_t	i;
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
	opt->i = 0;
}

static void	init_option(t_vec *vec, t_vi_option *opt, size_t option)
{
	opt->nb = 1;
	opt->option = option;
	opt->index = get_index(va_arg(opt->arg_list, int), vec->len);
	init_sep_opt(opt, SEP, &opt->sep, &opt->sep_len);
	init_sep_opt(opt, SEP, &opt->multi_sep, &opt->multi_sep_len);
	if (option & MULTI)
		opt->nb = va_arg(opt->arg_list, size_t);
}

t_vec	*insert_elem(t_vec *vec, t_vi_option	*opt, char *str, size_t len)
{
	if (!vec_resize_round(vec, len))
		return (NULL);
	ft_memmove(vec->buffer + opt->index + len, vec->buffer + opt->index,
		vec->len - opt->index);
	ft_memmove(vec->buffer + opt->index, str, len);
	vec->len += len;
	opt->index += len;
	return (vec);
}

t_vec	*vec_insert(t_vec *vec, t_fill_opt option, ...)
{
	t_vi_option	opt;

	va_start(opt.arg_list, option);
	init_option(vec, &opt, option);
	if (opt.index != 0 && !insert_elem(vec, &opt, opt.sep, opt.sep_len))
		return (NULL);
	while (opt.i < opt.nb)
	{
		if (opt.i != 0)
			if (!insert_elem(vec, &opt, opt.multi_sep, opt.multi_sep_len))
				return (NULL);
		opt.str = va_arg(opt.arg_list, char *);
		if (option & FIXED_LEN)
			opt.len = va_arg(opt.arg_list, int);
		else
			opt.len = ft_strlen(opt.str);
		if (!insert_elem(vec, &opt, opt.str, opt.len))
			return (NULL);
		opt.i++;
	}
	if (opt.index != vec->len - 1)
		if (!insert_elem(vec, &opt, opt.sep, opt.sep_len))
			return (NULL);
	va_end(opt.arg_list);
	return (vec);
}
