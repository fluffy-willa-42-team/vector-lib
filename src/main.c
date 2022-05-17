/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:16 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 16:29:10 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "vector-lib.h"

int main(void){
	printf("Running...\n");

	t_vec	vec = vecInit(sizeof(char));

	vecPrint(vec);
	printf("%d %d\n", vec.len, vec.size);

	printf("Ended\n");
	return (0);
}