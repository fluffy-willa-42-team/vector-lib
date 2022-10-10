/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_template.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:05:49 by awillems          #+#    #+#             */
/*   Updated: 2022/10/10 12:10:58 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATE_H
# define VECTOR_TEMPLATE_H

# include "unistd.h"

/* ************************************************************************** */

# ifdef WRA
#  include "wraloc.h"
# endif /* WRA */

# define V_DEFAULT_RATE		64

/* ************************************************************************** */

typedef enum s_alloc_opt
{
	SET		= 0b00,
	TRUNC	= 0b01,
	ROUND	= 0b10
}	t_alloc_opt;


typedef enum s_fill_opt
{
	DEFAULT			= 0b0000,
	SEP				= 0b0001,
	MULTI			= 0b0100,
	MULTI_SEP		= 0b0110,
	MULTI_ALL_SEP	= 0b0111,
	FIXED_LEN		= 0b1000
}	t_fill_opt;

/* ************************************************************************** */

typedef struct s_vec
{
	size_t	len;
	size_t	size;
	size_t	rate;
	size_t	alloc_len;
	void	*buffer;
	int		(*clear)();
	int		(*delete)();
}	t_vec;

/* ************************************************************************** */

#endif