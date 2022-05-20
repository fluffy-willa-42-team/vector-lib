/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_template.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:05:49 by awillems          #+#    #+#             */
/*   Updated: 2022/05/20 15:54:24 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATE_H
# define VECTOR_TEMPLATE_H

/* ************************************************************************** */

# define V_DEFAULT_RATE		64

# define V_DEFAULT			0
# define V_SEP				0b0001
# define V_MULTI_SEP		0b0010
# define V_MULTIPLE			0b0100
# define V_NOT_NULL_TERM	0b1000

/* ************************************************************************** */

typedef struct s_vec
{
	int		len;
	int		size;
	int		rate;
	char	*buffer;
	char	*index;//WIP
}	t_vec;

/* ************************************************************************** */

#endif