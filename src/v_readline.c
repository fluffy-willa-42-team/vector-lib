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
	return (RDLINE_BUF_SIZE);
}

static t_vec *move_into_buf(t_vec *vec, char *buf)
{
	int len;
	
	len = len_to_copy(buf);
	if (!v_add(vec, STRING, "%.*s", len, buf))
		return (NULL);
	ft_memmove(buf, buf + len, RDLINE_BUF_SIZE - len);
	ft_memset(buf + RDLINE_BUF_SIZE - len, 0, len);
	return (vec);
}

/*
  len SIZE-len
******OOO => OOO______
********* => _________
*000_____ => 000______
****_____ => _________
*/
t_vec	*v_readline(t_vec *vec, int fd)
{
	static char	buf[RDLINE_MAX_FD][RDLINE_BUF_SIZE];
	ssize_t		char_read;

	if (!vec || fd < 0)
		return (NULL);
	if (!move_into_buf(vec, buf[fd]))
		return (NULL);
	char_read = -1;
	while (
		char_read == -1 || (char_read != 0 && (char_read == RDLINE_BUF_SIZE ||
		(v_get(vec, -1) && *(char *) v_get(vec, -1) != 0
		&& *(char *) v_get(vec, -1) != '\n')))
	)
	{
		char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
		if (char_read == -1)
			return (NULL);
		if (!move_into_buf(vec, buf[fd]))
			return (NULL);
	}
	return (vec);
}
