/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_template.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:05:49 by awillems          #+#    #+#             */
/*   Updated: 2022/10/12 11:53:31 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATE_H
# define VECTOR_TEMPLATE_H

/* ************************************************************************** */

# include "unistd.h"

/* ************************************************************************** */

# define V_DEFAULT_RATE		64

# define RDLINE_MAX_FD		1000
# define RDLINE_BUF_SIZE	8

/* ************************************************************************** */

typedef enum s_alloc_opt
{
	SET		= 0b00,
	TRUNC	= 0b01,
	ROUND	= 0b10
}	t_alloc_opt;

typedef enum s_add_opt
{
	DEFAULT		= 0b000,
	STRING		= 0b001,
	MULTI		= 0b010,
	SEP			= 0b100
}	t_add_opt;

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