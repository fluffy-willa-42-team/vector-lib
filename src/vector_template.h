/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_template.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:05:49 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 13:29:15 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATE_H
# define VECTOR_TEMPLATE_H

/* ************************************************************************** */

# define V_DEFAULT_RATE		64

# define V_DEFAULT			0
# define V_SEP				0b0001
# define V_MULTI_SEP		0b0110
# define V_MULTIPLE			0b0100
# define V_FIXED_LEN		0b1000

/* ************************************************************************** */

typedef struct s_vec
{
	int		len;
	int		size;
	int		rate;
	void	*buffer;
}	t_vec;

/* ************************************************************************** */

#endif