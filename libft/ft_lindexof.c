/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lindexof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:04:43 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/31 17:13:01 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the index of the last occurence of the char 'c' in the c-string
**	'str'. If str is NULL or empty, or 'c' is '\0', -1 is returned.
*/
int		ft_lindexof(char const *str, char c)
{
	int		cnt;

	if (str != NULL && str[0] != '\0' && c != '\0')
	{
		cnt = ft_strlen(str) - 1;
		while (cnt >= 0)
		{
			if (str[cnt] == c)
				return (cnt);
			cnt--;
		}
	}
	return (-1);
}
