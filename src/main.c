/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:16 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 12:36:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-lib.h"

int main(void){
	t_vec	vec = vecInit();

	vecPrint(vec);
	vecFill(&vec, V_MULTIPLE | V_SEP | V_MULTI_SEP, "/c/", "/h/", 2, "hello", "world");
	vecPrint(vec);

	vecDelete(&vec);
	return (0);
}