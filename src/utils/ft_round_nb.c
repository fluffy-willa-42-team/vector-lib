/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:41:30 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 12:10:56 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_round_up(size_t nb, size_t base)
{
	(void) nb;
	(void) base;
	return (nb / base * base + base);
}
