/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:10 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 12:12:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

/* ************************************************************************** */

# include "vector_template.h"


/* ************************************************************************** */

t_vec	v_init(size_t size, int (*clear)(), int (*delete)());
t_vec	v_init_r(size_t size, int (*clear)(), int (*delete)(), size_t rate);

t_vec	*v_alloc(t_vec *vec, t_alloc_opt option, unsigned int length);

void	v_clear(t_vec *vec);
void	v_delete(t_vec *vec);

/* ************************************************************************** */

void	*v_get(t_vec *vec, int index);
void	*v_getr(t_vec *vec, int index);

/* ************************************************************************** */

t_vec	*v_add(t_vec *vec, t_fill_opt option, ...);
t_vec	*v_insert(t_vec *vec, int pos, t_fill_opt option, ...);

t_vec	*v_pop(t_vec *vec, int index);

/* ************************************************************************** */

void	v_print(t_vec *vec);

/* ************************************************************************** */

int		v_is_empty(t_vec *vec, int index);

/* ************************************************************************** */

t_vec	*v_cast(t_vec *vec, size_t new_size, int casting_function());

/* ************************************************************************** */

#endif