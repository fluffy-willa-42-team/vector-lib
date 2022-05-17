/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:16 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 19:28:52 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-lib.h"

int main(void){
	t_vec	vec = vecInit(sizeof(char));

	vecPrint(vec);
	printf("%d\n", vec.len);

	printf("\n");
	vecResize(&vec);

	vecPrint(vec);

	printf("%d\n", vec.len);
	
	vecDelete(&vec);
	return (0);
}