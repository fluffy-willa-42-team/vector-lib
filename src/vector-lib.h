/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector-lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:10 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 09:24:55 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

/* ************************************************************************** */

#include "vector-template.h"

/* ************************************************************************** */

t_vec	vecInit(int size, int rate);
void	vecDelete(t_vec *vec);

int	v_getLen(t_vec vec);
int	v_getSize(t_vec vec);
int	v_getRate(t_vec vec);

t_vec	*vecResize(t_vec *vec);
t_vec	*vecFill(t_vec *vec, int option, ...);
void	vecDeleteContent(t_vec *vec);

void	vecPrint(t_vec vec);

/* ************************************************************************** */

#endif