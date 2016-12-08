/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:05:21 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:05:23 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	cnt;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (ft_strdup(s));
	start = 0;
	cnt = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (start == ft_strlen(s))
		return ("");
	if ((str = (char *)malloc(sizeof(char) * (end - start + 2))) == NULL)
		return (NULL);
	while (start <= end)
		str[cnt++] = s[start++];
	str[cnt] = '\0';
	return (str);
}
