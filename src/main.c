/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:16 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 14:32:56 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

int	main(void)
{
	t_vec	vec;

	vec = vec_init();
	vec_fill(&vec, 0b1111, " /// ", " ", 2, "hello", 10, "world", 2);
	vec_fill(&vec, 0b0111, " /// ", " ", 3, "bruh", "wtf", "cool");
	vec_fill(&vec, 0b0001, " /// ", "YOOOOOO");
	vec_print(vec);
	vec_delete(&vec);
	return (0);
}
