/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:10 by awillems          #+#    #+#             */
/*   Updated: 2022/05/20 15:32:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

/* ************************************************************************** */

# include "vector_template.h"

/* ************************************************************************** */

t_vec	vec_init(void);
t_vec	vec_init_strict(int len, int size, int rate);
void	vec_delete(t_vec *vec);

int		v_get_len(t_vec vec);
int		v_get_size(t_vec vec);
int		v_get_rate(t_vec vec);

t_vec	*vec_resize(t_vec *vec);
t_vec	*vec_fill(t_vec *vec, int option, ...);
void	vec_delete_content(t_vec *vec);

void	vec_print(t_vec vec);

/* ************************************************************************** */

#endif