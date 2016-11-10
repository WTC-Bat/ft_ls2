/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:22:47 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 10:22:50 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			return (0);
	}
	if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	else
		return (1);


	// while (*s1 == *s2)
	// {
	// 	s1++;
	// 	s2++;
	// 	if (*s1 != *s2)
	// 	{
	// 		if (*(unsigned char *)s1 < *(unsigned char *)s2)
	// 			return (-1);
	// 		else
	// 			return (1);
	// 	}
	// }
	// return (0);
}
