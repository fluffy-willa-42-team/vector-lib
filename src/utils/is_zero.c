/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:36:15 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 13:10:08 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_zero(void *mem_raw, int size)
{
	unsigned char	*mem;
	int				i;

	mem = (unsigned char *) mem_raw;
	i = 0;
	while (i < size)
	{
		if (mem[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
