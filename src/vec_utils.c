/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:58:53 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 14:32:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

int	v_get_len(t_vec vec)
{
	return (vec.len);
}

int	v_get_size(t_vec vec)
{
	return (vec.size);
}

int	v_get_rate(t_vec vec)
{
	return (vec.rate);
}
