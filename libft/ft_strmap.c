/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:14:10 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:14:16 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		cnt;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	cnt = 0;
	while (s[cnt] != '\0')
	{
		str[cnt] = f(s[cnt]);
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}
