/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:10 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 17:10:52 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

/* ************************************************************************** */

# include "vector_template.h"

/* ************************************************************************** */

# define vec_init(type) {0, sizeof(type), V_DEFAULT_RATE, 0, NULL, NULL}
# define vec_init_r(type, rate) {0, sizeof(type), rate, 0, NULL, NULL}

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
t_vec	*vec_pop(t_vec *vec, int index);
void	vec_print(t_vec *vec);

int		vec_is_empty(t_vec *vec, int index);

t_vec	*vec_cast(t_vec *vec, size_t new_size, int casting_function());

t_vec	*vec_add_itoa(t_vec *vec, int n);

/* ************************************************************************** */

#endif