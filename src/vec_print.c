/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:32 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 15:40:36 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "vector_template.h"

int	ft_isprint(int c);

void	vec_print(t_vec *vec)
{
	size_t	i;

	if (!vec || !vec->buffer)
		return ;
	i = 0;
	while (i < vec->len)
	{
		if (ft_isprint(((char *) vec->buffer)[i]))
			write(1, &((char *) vec->buffer)[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}
