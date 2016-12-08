/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:02:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:12:11 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char *bigc, char *little, int cnt)	//ft_strnequ || ft_strncmp?
{
	size_t	mcnt;
	size_t	len;

	mcnt = cnt;
	len = ft_strlen(little);
	while (mcnt <= len)
	{
		if (bigc[mcnt] != little[mcnt])
			return (0);
		mcnt++;
	}
	return (1);
}

char		*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	cnt;

	if (little[0] == '\0')
		return (big);
	cnt = 0;
	while (big[cnt] != '\0' && cnt < len)
	{
		if (big[cnt] == little[0])
		{
			if (is_match(&big[cnt], little, cnt) == 1)
			{
				return (&big[cnt]);
			}
		}
		cnt++;
	}
	return (NULL);
}
