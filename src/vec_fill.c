/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 16:25:01 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "vector_template.h"
#include <unistd.h>

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

/**
 * @brief [internal] initialize all option values according to optionRaw.
 */
static void	init_option_val(t_v_option *option, int optionRaw, va_list args)
{
	option->raw = optionRaw;
	if (option->raw & SEP)
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
	if (option->raw & 0b10)
	{
		option->multi_sep = va_arg(args, char *);
		if (ft_strlen(option->multi_sep) == 0)
		{
			option->multi_sep_len = 1;
			option->multi_sep = "";
		}
		else
			option->multi_sep_len = ft_strlen(option->multi_sep);
	}
	if (option->raw & MULTI)
		option->nb = va_arg(args, int);
}

/**
 * @brief [internal] Get the first writable character inside the vector and will
 * expand the vector if needed
 */
int	g_start_vec(t_vec *vec, int str_len, int sep_len, char *sep)
{
	int	res;

	if (!vec->buffer)
		vec_resize(vec);
	res = vec->len - 1;
	while (res > 0 && ((char *) vec->buffer)[res - 1] == 0)
		res--;
	if (res != 0 && sep && !sep[0])
		res += 1;
	while (vec->len < res + str_len + sep_len)
		vec_resize(vec);
	return (res);
}

/**
 * @brief [internal] Get the length of the given string that will be moved
 */
static int	get_fill_len(va_list args, int option, char *str)
{
	int	len_of_str;
	int	res;

	len_of_str = ft_strlen(str);
	if (option & FIXED_LEN)
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
 * @param SEP Will put a string or if null a char 0 between two fill calls.
 * @param MULTI_SEP Will put a string or if null a char 0 between two string
 * in a call with multiple string added.
 * @param MULTI Will accept multiple strings.
 * @param FIXED_LEN Will limit the length of the string given before.
 * @param EXAMPLE vec_fill(vec, opt, SEP, MULTI_SEP, NB_STR, [STR, STR_LEN, ..])
 */
t_vec	*vec_fill(t_vec *vec, t_fill_opt option, ...)
{
	va_list		args;
	t_v_option	opt;
	int			i;

	va_start(args, option);
	opt = init_v_option();
	init_option_val(&opt, option, args);
	opt.start = g_start_vec(vec, 0, opt.sep_len, opt.sep);
	if ((option & SEP) && opt.start != 0)
		ft_memmove(vec->buffer + opt.start, opt.sep, opt.sep_len);
	i = 0;
	while (i < opt.nb)
	{
		opt.str = va_arg(args, char *);
		opt.start = g_start_vec(vec, ft_strlen(opt.str),
				opt.multi_sep_len, opt.multi_sep);
		opt.len = get_fill_len(args, option, opt.str);
		ft_memmove(vec->buffer + opt.start, opt.str, opt.len);
		if ((option & 0b10) && i + 1 != opt.nb)
			ft_memmove(vec->buffer + opt.start + opt.len,
				opt.multi_sep, opt.multi_sep_len);
		i++;
	}
	va_end(args);
	return (vec);
}
