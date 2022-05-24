/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 09:23:35 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector_template.h"
#include <unistd.h>

#include <stdio.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

t_vec	*vec_resize(t_vec *vec);

typedef struct s_v_option
{
	int		raw;
	int		start;
	void	*str;
	int		len;
	void	*sep;
	int		sep_len;
	void	*multi_sep;
	int		multi_sep_len;
	int		nb;
}	t_v_option;

static t_v_option	init_v_option(void)
{
	t_v_option	option;

	option.raw = 0;
	option.start = 0;
	option.str = NULL;
	option.len = 0;
	option.sep = NULL;
	option.multi_sep = NULL;
	option.sep_len = 0;
	option.multi_sep_len = 0;
	option.nb = 1;
	return (option);
}

void	init_option_val(t_v_option *option, int optionRaw, va_list args)
{
	option->raw = optionRaw;
	if (option->raw & V_SEP)
	{
		option->sep = va_arg(args, char *);
		if (ft_strlen(option->sep) == 0)
		{
			option->sep_len = 1;
			option->sep = "";
		}
		else
			option->sep_len = ft_strlen(option->sep);
	}
	if (option->raw & V_MULTI_SEP)
	{
		option->multi_sep = va_arg(args, char *);
		if (ft_strlen(option->multi_sep) == 0)
		{
			option->multi_sep_len = 1;
			option->multi_sep = "\0";
		}
		else
			option->multi_sep_len = ft_strlen(option->multi_sep);
	}
	if (option->raw & V_MULTIPLE)
		option->nb = va_arg(args, int);
}

/**
 * @brief Get the first char we can write to in the vec and
 * resize the vector so it can fit with the start, a string and a separator.
 * 
 * @param vec The given vec.
 * @param str_len The length of the string we want to add.
 * @param sep_len The length of the separator.
 * @return int The index.
 */
static int	start_vec(t_vec *vec, int str_len, int sep_len, char *sep)
{
	int	i;
	int	res;

	i = vec->len - 1;
	while (i >= 0 && vec->buffer[i] == 0)
		i--;
	if (i == -1)
		res = 0;
	else
		res = i + 1;
	while (vec->len < res + str_len + sep_len)
		vec_resize(vec);
	if (sep && sep[0] == 0 && res != 0)
		return (res + 1);
	return (res);
}

/**
 * @brief Get the length of the str to be writen in the buffer
 * without exceeding.
 * 
 * @param args va_list.
 * @param option options of the fill.
 * @param str The string to be added.
 * @return int The length of the string to be written.
 */
static int	get_len_of_fill(va_list args, int option, char *str)
{
	int	len_of_str;
	int	res;

	len_of_str = ft_strlen(str);
	if (option & V_NOT_NULL_TERM)
		res = va_arg(args, int);
	else
		res = len_of_str;
	if (res > len_of_str)
		return (len_of_str);
	return (res);
}

/**
 * @brief Add string(s) to a the given vector.
 * 
 * @param vec The vector where the string will be added.
 * @param option Options of the adding string. Options are (in order) :
 * @param V_MULTIPLE : lets you put multiple elements at the same time;
 * @param ... 
 * @return t_vec* 
 */
t_vec	*vec_fill(t_vec *vec, int option, ...)
{
	va_list		args;
	t_v_option	opt;
	int			i;

	va_start(args, option);
	opt = init_v_option();
	init_option_val(&opt, option, args);
	opt.start = start_vec(vec, 0, opt.sep_len, opt.sep);
	if ((option & V_SEP) && opt.start != 0)
		ft_memmove(vec->buffer + opt.start, opt.sep, opt.sep_len);
	i = 0;
	while (i < opt.nb)
	{
		opt.str = va_arg(args, char *);
		opt.start = start_vec(vec, ft_strlen(opt.str), opt.sep_len, opt.sep);
		printf("%d\n", opt.start);
		opt.len = get_len_of_fill(args, option, opt.str);
		ft_memmove(vec->buffer + opt.start, opt.str, opt.len);
		if ((option & V_MULTI_SEP) && i + 1 != opt.nb)
			ft_memmove(vec->buffer + opt.start + opt.len,
				opt.multi_sep, opt.multi_sep_len);
		i++;
	}
	va_end(args);
	return (vec);
}
