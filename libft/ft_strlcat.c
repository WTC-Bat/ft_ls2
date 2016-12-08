/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:14:47 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 16:38:20 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	cnt;
	size_t	scnt;
	size_t	dlen;

	scnt = 0;
	dlen = 0;
	while (dlen < size && dst[dlen] != '\0')
		dlen++;
	cnt = dlen;
	while (cnt < (size - 1) && src[scnt] != '\0')
	{
		dst[cnt] = src[scnt];
		cnt++;
		scnt++;
	}
	if (dlen < size)
		dst[cnt] = '\0';
	return (dlen + ft_strlen(src));
}
