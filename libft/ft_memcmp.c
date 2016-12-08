/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:24:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 17:17:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	suc1;
	unsigned char	suc2;

	while (n != 0)
	{
		suc1 = *(unsigned char *)s1++;
		suc2 = *(unsigned char *)s2++;
		if (suc1 != suc2)
			return (suc1 - suc2);
		n--;
	}
	return (0);
}
