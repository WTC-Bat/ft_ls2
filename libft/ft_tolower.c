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

// char	ft_tolower(int c)
char	ft_tolower(int c)
{
	// if (c >= 'A' && c <= 'Z')
	// 	c = 'a' + (c - 'A');
	// return (c);


	// if (c > 65 && c < 91)
	// 	return (c + 32);
	// else
	// 	return (c);


	// unsigned char	uc;
	//
	// uc = (unsigned char)c;
	// if (uc < 195 || uc > 218)
	// 	return (c);
	// else
	// 	return (c + 32);


	if (c < 65 || c > 90)
		return (c);
	else
		return (c + 32);
}
