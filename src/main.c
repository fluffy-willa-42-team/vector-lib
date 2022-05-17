/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:16 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 19:38:19 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector-lib.h"

int main(void){
	t_vec	vec = vecInit(sizeof(char));

	vecPrint(vec);
	vecPrint(vec);

	vecFill(&vec);
	
	vecDelete(&vec);
	return (0);
}