/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:37:02 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 09:42:03 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*V2*/

// char	ft_tolower(char c)
// {
// 	if (c < 'A' || c > 'Z')
// 		return ((unsigned char)c);
// 	else
// 		return ((unsigned char)(c + 32));
// }

/*V1*/

char	ft_tolower(int c)
{
	if (c < 65 || c > 90)
		return (c);
	else
		return (c + 32);
}

/*ALT*/

// char	ft_tolower(unsigned char c)
// {
// 	if (c < (unsigned int )65 || c > (unsigned int)90)
// 		return (c);
// 	else
// 		return (c + (unsigned int)32);
// }
