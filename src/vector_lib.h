/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 15:09:10 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

/* ************************************************************************** */

# include "vector_template.h"

/* ************************************************************************** */

t_vec	vec_init(size_t size);
void	vec_delete(t_vec *vec);
void	vec_destroy(t_vec *vec);

void	*vec_get(t_vec *vec, int index);
void	*vec_get_raw(t_vec *vec, int index);

t_vec	*vec_resize(t_vec *vec);
t_vec	*vec_resize_round(t_vec *vec, size_t new_len);

t_vec	*vec_add(t_vec	*vec, void *new_content);
t_vec	*vec_add_n(t_vec	*vec, void *new_content, size_t nb_elem);
t_vec	*vec_fill(t_vec *vec, t_fill_opt option, ...);

t_vec	*vec_insert(t_vec *vec, t_fill_opt option, ...);

void	vec_print(t_vec *vec);

int		vec_is_empty(t_vec *vec, int index);

/* ************************************************************************** */

#endif