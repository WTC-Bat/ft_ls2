/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:25:09 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:25:10 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the amount of words after splitting at the character specified by
**	'c'. If 's' is NULL or empty, or 'c' is '\0', 0 is returned.
*/
int		ft_splitcnt(char const *s, char c)
{
	int		cnt;
	int		wcnt;

	if (s == NULL || s[0] == '\0' || c == '\0')
		return (0);
	cnt = 0;
	wcnt = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == c && s[cnt - 1] != c && cnt > 0)
			wcnt++;
		cnt++;
	}
	return (wcnt + 1);
}
