/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:32 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 16:12:31 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "vector-template.h"

int	ft_isprint(int c);

void	vecPrint(t_vec vec){
	int	i;

	if (!vec.buffer)
		return ;
	i = 0;
	while (i < vec.len){
		if (ft_isprint(vec.buffer[i]))
			write(1, &vec.buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "/n", 1);
}
