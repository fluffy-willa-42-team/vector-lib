/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:32 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 12:49:48 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "vector_template.h"

int	ft_isprint(int c);

void	vec_print(t_vec *vec)
{
	int	i;

	if (!vec || !vec->buffer)
		return ;
	i = 0;
	while (i < vec->len)
	{
		if (ft_isprint(vec->buffer[i]))
			write(1, &vec->buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}
