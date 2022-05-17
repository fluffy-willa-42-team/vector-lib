/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:22:33 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 19:24:33 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-template.h"
#include <stdlib.h>

void	vecDelete(t_vec *vec){
	vec->len = 0;
	free(vec->buffer);
}
