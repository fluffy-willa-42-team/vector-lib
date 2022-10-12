/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_readline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:19:28 by awillems          #+#    #+#             */
/*   Updated: 2022/10/12 12:13:03 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);

static int	len_to_copy(char *str, int len)
{
	int i = 0;

	while (i < len)
	{
		if (str[i] == '\n' || str[i] == 0)
			return (i);
		i++;
	}
	return (i);
}

/*
******OOO => OOO______
********* => _________
*000_____ => 000______
****_____ => _________
*/
t_vec	*v_readline(t_vec *vec, int fd)
{
	static char	buf[RDLINE_MAX_FD][RDLINE_BUF_SIZE];
	ssize_t	char_read;
	int len;

	if (!vec || fd < 0)
		return (NULL);
	
	// add_rest_of_buf();
	
	len = -1;
	while (len == -1 || buf[fd][len] == '\n' || buf[fd][len] == 0)
	{
		char_read = read(fd, buf[fd], RDLINE_BUF_SIZE);
		if (char_read == -1)
			return (NULL);
		len = len_to_copy(buf[fd], RDLINE_BUF_SIZE);
		// ft_memmove();
	}




	return (vec);
}
