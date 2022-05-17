/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:45:50 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 19:43:20 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-template.h"

#define VEC_DEFAULT		0
#define VEC_SKIP		0b0001
#define VEC_SEPATOR		0b0010
#define VEC_MULTIPLE	0b0100

t_vec	*vecFill(t_vec *vec){
	int option;
	
	option = (VEC_SKIP | VEC_SEPATOR);
	
	if (option & VEC_SKIP){
		printf("WITH SKIPS\n");
	}

	if (option & VEC_SEPATOR){
		printf("WITH SEPARATOR\n");
	}

	if (option & VEC_MULTIPLE){
		printf("WITH MULTIPLE\n");
	}

	return (vec);
}