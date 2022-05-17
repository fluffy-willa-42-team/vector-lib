/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:15:09 by awillems          #+#    #+#             */
/*   Updated: 2022/05/17 16:19:29 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Copy every bytes from the sources to the destination
 * in protected way.
 * 
 * @param dst Any array.
 * @param src Any array.
 * @param len The length we are going to copy.
 * @return Pointer to the destination.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*memdst;
	unsigned char	*memsrc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	memdst = (unsigned char *) dst;
	memsrc = (unsigned char *) src;
	i = 0;
	while (i < len)
	{
		if (memdst >= memsrc)
			memdst[len - i - 1] = memsrc[len - i - 1];
		else
			memdst[i] = memsrc[i];
		i++;
	}
	return (dst);
}
