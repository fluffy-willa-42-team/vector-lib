
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 09:31:44 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector_template.h"
#include <unistd.h>

#include <stdio.h>

size_t	ft_strlen(const char *s);

typedef struct vf_option_s
{
	va_list	arg_list;
	char	*sep;
	int		sep_len;
	char	*multi_sep;
	int		multi_sep_len;
	int		nb;
}	vf_option_t;

void	init_option(vf_option_t	*opt, int option)
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

t_vec	*vec_fill(t_vec *vec, t_fill_opt option, ...)
{
	vf_option_t	opt;
	int			i;
	char		*str;
	int			len;

	va_start(opt.arg_list, option);
	init_option(&opt, option);

	printf("=> %d\n", opt.nb);
	printf("\"%s\" (%d)\n", opt.sep, opt.sep_len);
	printf("\"%s\" (%d)\n", opt.multi_sep, opt.multi_sep_len);

	i = 0;
	while (i < opt.nb)
	{
		str = va_arg(opt.arg_list, char *);
		if (option & FIXED_LEN)
			len	= va_arg(opt.arg_list, int);
		else
			len = ft_strlen(str);
		printf("\"%s\" (%d)\n", str, len);
		i++;
	}
	va_end(opt.arg_list);
	return (vec);
}