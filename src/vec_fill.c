/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 15:14:08 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector_template.h"
#include <unistd.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);

t_vec	*vec_resize_round(t_vec *vec, int new_len);

typedef struct s_vf_option
{
	va_list	arg_list;
	char	*sep;
	int		sep_len;
	char	*multi_sep;
	int		multi_sep_len;
	int		nb;
}	t_vf_option;

void	init_option(t_vf_option	*opt, int option)
{
	opt->nb = 1;
	opt->sep = NULL;
	opt->multi_sep = NULL;
	if (option & SEP)
		opt->sep = va_arg(opt->arg_list, char *);
	opt->sep_len = ft_strlen(opt->sep);
	if (!opt->sep_len)
		opt->sep = "";
	if (option & 0b10)
		opt->multi_sep = va_arg(opt->arg_list, char *);
	opt->multi_sep_len = ft_strlen(opt->multi_sep);
	if (!opt->multi_sep_len)
		opt->multi_sep = "";
	if (option & MULTI)
		opt->nb = va_arg(opt->arg_list, int);
}

void	add_elem_in_vec(t_vec *vec, char *src, int len)
{
	vec_resize_round(vec, len);
	ft_memmove(vec->buffer + vec->content_len, src, len);
	vec->content_len += len;
}

t_vec	*vec_fill(t_vec *vec, t_fill_opt option, ...)
{
	t_vf_option	opt;
	int			i;
	char		*str;
	int			len;

	va_start(opt.arg_list, option);
	init_option(&opt, option);
	if (vec->content_len != 0)
		add_elem_in_vec(vec, opt.sep, opt.sep_len);
	i = 0;
	while (i < opt.nb)
	{
		str = va_arg(opt.arg_list, char *);
		if (option & FIXED_LEN)
			len = va_arg(opt.arg_list, int);
		else
			len = ft_strlen(str);
		if (i != 0)
			add_elem_in_vec(vec, opt.multi_sep, opt.multi_sep_len);
		add_elem_in_vec(vec, str, len);
		i++;
	}
	va_end(opt.arg_list);
	return (vec);
}
