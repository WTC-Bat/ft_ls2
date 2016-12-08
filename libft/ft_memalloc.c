/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:13:55 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:13:57 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			cnt;
	unsigned char	*mem;

	if (((mem = (void *)malloc(sizeof(void) * size)) == NULL)
			|| size > 65535)
		return (NULL);
	cnt = 0;
	while (cnt <= size)
	{
		mem[cnt] = 0;
		cnt++;
	}
	return (mem);
}
