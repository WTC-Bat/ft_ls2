/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:14:27 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/14 14:27:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns 1 if the c-string 'str' begins with the c-string 'start', otherwise
**	0 is returned.
*/
int		ft_startswith(char const *str, char const *start)
{
	int		startlen;
	int		cnt;

	if (str == NULL || start == NULL)
		return (0);
	startlen = ft_strlen(start);
	cnt = 0;
	while (cnt < startlen && str[cnt] != '\0')
	{
		if (str[cnt] != start[cnt])
			return (0);
		cnt++;
	}
	return (1);
}
