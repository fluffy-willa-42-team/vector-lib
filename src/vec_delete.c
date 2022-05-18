/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:22:33 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 09:24:01 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-template.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);

void	vecDelete(t_vec *vec){
	vec->len = 0;
	free(vec->buffer);
}

void	vecDeleteContent(t_vec *vec){
	ft_memset(vec->buffer, vec->len, vec->size);
}
