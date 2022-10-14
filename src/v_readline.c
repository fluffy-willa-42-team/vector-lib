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

t_vec	*v_add(t_vec *vec, t_add_opt option, ...);
void	v_print(t_vec *vec);

static int	len_to_copy(char *str)
{
	int i = 0;

	while (i < RDLINE_BUF_SIZE)
	{
		if (str[i] == '\n' || str[i] == 0)
			return (i);
		i++;
	}
	return (i);
}


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
	// ssize_t	char_read;
	int len;

	if (!vec || fd < 0)
		return (NULL);
	
	buf[fd][0] = 'a';
	buf[fd][1] = '3';

	print_buf(buf[fd]);
	
	// add_rest_of_buf();
	len = len_to_copy(buf[fd]);
	v_add(vec, STRING, "%.*s", len, buf[fd]);
	ft_memmove(buf[fd], buf[fd] + len, RDLINE_BUF_SIZE - len);
	ft_memset(buf[fd] + RDLINE_BUF_SIZE - len, 0, len);
	
	v_print(vec);
	print_buf(buf[fd]);
	printf("%zu %zu\n", vec->len, vec->alloc_len);

	// len = -1;
	// while (len == -1 || buf[fd][len] == '\n' || buf[fd][len] == 0)
	// {
	// 	char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
	// 	if (char_read == -1)
	// 		return (NULL);
	// 	len = len_to_copy(buf[fd], RDLINE_BUF_SIZE);
	// 	// ft_memmove();
	// }




	return (vec);
}
