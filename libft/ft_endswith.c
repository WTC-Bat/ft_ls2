/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:25:49 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:26:12 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns 1 if the c-string 'str' ends with the c-string 'start', otherwise
**	0 is returned.
*/
int		ft_endswith(char const *str, char const *end)
{
	int		cnt;
	int		endlen;
	int		stridx;

	cnt = 0;
	endlen = ft_strlen(end);
	stridx = ft_strlen(str) - endlen;
	while (str[stridx] != '\0' && end[cnt] != '\0' && cnt < endlen)
	{
		if (str[stridx] != end[cnt])
			return (0);
		cnt++;
		stridx++;
	}
	return (1);
}
