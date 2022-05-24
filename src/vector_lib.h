/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:10 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 11:37:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

/* ************************************************************************** */

# include "vector_template.h"

/* ************************************************************************** */

t_vec	vec_init(int size);
void	vec_delete(t_vec *vec);

int		v_get_len(t_vec vec);
int		v_get_size(t_vec vec);
int		v_get_rate(t_vec vec);

t_vec	*vec_resize(t_vec *vec);
t_vec	*vec_add(t_vec *vec);
t_vec	*vec_fill(t_vec *vec, int option, ...);
void	vec_delete_content(t_vec *vec);

void	vec_print(t_vec vec);

/* ************************************************************************** */

#endif