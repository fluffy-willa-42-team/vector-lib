/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:12:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 13:52:44 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_index(int index, int len)
{
	if (len == 0)
		return (0);
	while (index < 0)
		index += len;
	while (index >= len)
		index -= len;
	return (index);
}
