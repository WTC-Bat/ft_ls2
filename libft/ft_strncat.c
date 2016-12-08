/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:11:01 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 16:29:43 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t		cnt;
	size_t		len;

	cnt = 0;
	len = ft_strlen(dest);
	while (cnt < nb && src[cnt] != '\0')
	{
		dest[cnt + len] = src[cnt];
		cnt++;
	}
	dest[cnt + len] = '\0';
	return (dest);
}
