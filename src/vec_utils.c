/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:58:53 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 09:02:09 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-lib.h"

int v_getLen(t_vec vec){
	return (vec.len);
}

int v_getSize(t_vec vec){
	return (vec.size);
}

int v_getRate(t_vec vec){
	return (vec.rate);
}
