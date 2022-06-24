/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:36:36 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/24 11:43:01 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_template.h"
#include <stddef.h>

/**
 * @brief copy `src` in `dest` starting by the end of `src` in non destructive
 *        way.
 * 
 */
static void	rev_cpy(char *dest, char *src)
{
	const char	*mid;
	char		tmp;

	mid = src;
	while (*src)
		src++;
	src--;
	mid = (src - ((src - mid)) / 2);
	while (src > mid)
	{
		tmp = *dest;
		*dest = *src;
		*src = tmp;
		dest++;
		src--;
	}
}

t_vec	*vec_add_n(t_vec	*vec, void *new_content, size_t nb_elem);
size_t	ft_strlen(const char *s);

/**
 * index   0  1  2  3  4  5  6  7  8  9  10 11
 *        [8][4][6][3][8][4][7][4][1][2][-][\0]
 * @brief Convert integer to string of char. (use malloc())
 * 
 * @param n The integer to convert.
 * @return  char* The string representing the integer. NULL if the
 *          allocation fails.
 *
 */
t_vec	*vec_add_itoa(t_vec *vec, int n)
{
	char	buff[12];
	char	*str;
	size_t	nbr;

	nbr = (unsigned int []){n, -n}[n < 0];
	str = buff;
	if (nbr == 0)
		*str++ = '0';
	while (nbr > 0)
	{
		*str++ = (char)((nbr % 10) + '0');
		nbr /= 10;
	}
	*str++ = (char []){'\0', '-'}[n < 0];
	*str = '\0';
	rev_cpy(buff, buff);
	return (vec_add_n(vec, buff, ft_strlen(buff)));
}
