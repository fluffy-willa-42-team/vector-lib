/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:16 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 09:20:32 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-lib.h"

int main(void){
	t_vec	vec = vecInit(sizeof(char), V_DEFAULT_RATE);

	vecFill(&vec, V_MULTIPLE | V_SEP | V_MULTI_SEP, "/e/", "/d/", 2, "hello");
	vecPrint(vec);

	vecDelete(&vec);
	return (0);
}