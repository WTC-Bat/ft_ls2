/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:12:52 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/31 17:12:56 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the index of the first occurence of the char 'c' in the c-string
**	'str'. If 'str' is NULL or empty, or 'c' is '\0', -1 is returned.
*/
int		ft_indexof(char const *str, char c)
{
	int		cnt;

	if (str != NULL && str[0] != '\0' && c != '\0')
	{
		cnt = 0;
		while (str[cnt] != '\0')
		{
			if (str[cnt] == c)
				return (cnt);
			cnt++;
		}
	}
	return (-1);
}
