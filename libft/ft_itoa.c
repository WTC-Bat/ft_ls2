/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:18:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:18:44 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int		set_nbr(int n)
{
	int		nbr;

	nbr = 0;
	if (n < 0)
	{
		nbr = n;
		nbr = -nbr;
	}
	else
		nbr = n;
	return (nbr);
}

char			*ft_itoa(int n)
{
	char	*istr;
	int		nbr;
	size_t	nlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = get_len(n);
	istr = (char *)malloc(sizeof(char) * (nlen + 1));
	if (istr == NULL)
		return (NULL);
	nbr = set_nbr(n);
	*istr = '\0';
	if (n == 0)
		*--istr = '0';
	while (nbr != 0)
	{
		*--istr = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	if (n < 0)
		*--istr = '-';
	if (n == (-2147483647 - 1))
		istr[ft_strlen(istr) - 1] = '8';
	return (istr);
}
