/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_readline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:19:28 by awillems          #+#    #+#             */
/*   Updated: 2022/10/20 12:53:41 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);

void	*v_get(t_vec *vec, int index);
t_vec	*v_add(t_vec *vec, t_add_opt option, ...);
void	v_print(t_vec *vec);



#include <unistd.h>
int	ft_isprint(int c);
void print_buf(char *buf)
{
	size_t	i;

	write(1, "\t\t\tBUF=  ", 10);
	i = 0;
	while (i < RDLINE_BUF_SIZE)
	{
		if (ft_isprint(buf[i]))
			write(1, &buf[i], 1);
		else if (buf[i] == 0)
			write(1, "\e[0;31m.\e[0m", 13);
		else
			write(1, "\e[0;36m.\e[0m", 13);
		i++;
	}
	write(1, "\n", 1);
}

static int	len_to_copy(char *str)
{
	int i = 0;

	while (i < RDLINE_BUF_SIZE)
	{
		if (str[i] == '\n' || str[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int move_into_buf(t_vec *vec, char *buf, char *last_char, int *has_print)
{
	int len;

	len = len_to_copy(buf);
	if (len == -1)
		len = RDLINE_BUF_SIZE;
	*last_char = buf[len];
	if (!v_add(vec, STRING, "%.*s", len, buf))
		return (0);
	if (*last_char == '\n')
		len++;
	if (len > 0)
		*has_print = 1;
	ft_memmove(buf, buf + len, RDLINE_BUF_SIZE - len);
	ft_memset(buf + RDLINE_BUF_SIZE - len, 0, len);
	return (1);
}

int	v_readline(t_vec *vec, int fd)
{
	static char	buf[RDLINE_MAX_FD][RDLINE_BUF_SIZE];
	ssize_t		char_read;
	char 		c;
	int 		has_printed;

	if (!vec || fd < 0)
		return (0);
	has_printed = 0;
	if (!move_into_buf(vec, buf[fd], &c, &has_printed))
		return (-1);
	if (c == '\n')
		return (1);
	char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
	if (!has_printed && char_read <= 0)
		return (0);
	while (len_to_copy(buf[fd]) < 0)
	{
		if (char_read == -1)
			return (0);
		if (!move_into_buf(vec, buf[fd], &c, &has_printed))
			return (-1);
		char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
	}
	if (!move_into_buf(vec, buf[fd], &c, &has_printed))
		return (-1);
	return (1);
}
