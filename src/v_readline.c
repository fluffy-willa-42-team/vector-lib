/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_readline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:19:28 by awillems          #+#    #+#             */
/*   Updated: 2022/10/14 11:34:35 by awillems         ###   ########.fr       */
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

	write(1, "    BUF=  ", 10);
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

static int move_into_buf(t_vec *vec, char *buf, int *ptr)
{
	int len;
	
	*ptr = 0;
	len = len_to_copy(buf);
	if (len == -1)
		len = RDLINE_BUF_SIZE;
	if (!v_add(vec, STRING, "%.*s", len, buf))
		return (0);
	if (len_to_copy(buf) != 0 && buf[len_to_copy(buf)] == 0)
	{
		(*ptr)++;
	}
	if (len_to_copy(buf) != -1 && buf[len_to_copy(buf)] == '\n')
	{
		len++;
		(*ptr)++;
	}
	ft_memmove(buf, buf + len, RDLINE_BUF_SIZE - len);
	ft_memset(buf + RDLINE_BUF_SIZE - len, 0, len);
	return (1);
}

int	v_readline(t_vec *vec, int fd)
{
	static char	buf[RDLINE_MAX_FD][RDLINE_BUF_SIZE];
	ssize_t		char_read;
	int 		has_the_end;


	if (!vec || fd < 0)
		return (0);
	move_into_buf(vec, buf[fd], &has_the_end);
	if (has_the_end)
		return (2);
	char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
	if (char_read <= 0 && has_the_end == 2)
		return (3);
	if (char_read <= 0)
		return (0);
	while (len_to_copy(buf[fd]) < 0 && !has_the_end)
	{
		if (char_read == -1)
			return (0);
		move_into_buf(vec, buf[fd], &has_the_end);
		char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
	}
	if (!has_the_end)
		move_into_buf(vec, buf[fd], &has_the_end);
	return (4);
}
