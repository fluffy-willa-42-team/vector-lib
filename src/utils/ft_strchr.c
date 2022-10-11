/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:55:35 by awillems          #+#    #+#             */
/*   Updated: 2022/10/11 11:05:19 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&res[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&res[i]);
	return (0);
}
