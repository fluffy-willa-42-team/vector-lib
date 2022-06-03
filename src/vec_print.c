/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:32 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 12:07:36 by awillems         ###   ########.fr       */
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
	while (i < vec->len * vec->size)
	{
		if (ft_isprint(((char *) vec->buffer)[i]))
			write(1, &((char *) vec->buffer)[i], 1);
		else if (((char *) vec->buffer)[i] == 0)
			write(1, "\e[0;31m.\e[0m", 13);
		else
			write(1, "\e[0;36m.\e[0m", 13);
		if (vec->size > 1 && ((i + 1) % vec->size == 0))
			write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
