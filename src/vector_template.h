/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_template.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:05:49 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 13:58:56 by awillems         ###   ########.fr       */
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
}	t_vec;

/* ************************************************************************** */

#endif