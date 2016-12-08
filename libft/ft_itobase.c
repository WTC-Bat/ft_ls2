/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:41:32 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:21:07 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_nbr(int n)
{
	int		nbr;

	nbr = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			nbr = n + 1;
			nbr = -nbr;
		}
		else
		{
			nbr = n;
			nbr = -nbr;
		}
	}
	else
		nbr = n;
	return (nbr);
}

char		*ft_itobase(int n, int base)
{
	char	*basechars;
	char	*out;
	int		nbr;
	int		bc;

	basechars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	out = (char *)malloc(sizeof(char) * 32);
	nbr = set_nbr(n);
	bc = 0;
	*out = '\0';
	if (n == 0)
		*--out = '0';
	while (nbr != 0)
	{
		bc = nbr % base;
		nbr = nbr / base;
		*--out = basechars[bc];
	}
	if (n < 0 && base == 10)
		*--out = '-';
	if (n == -2147483648 && base == 10)
		out[ft_strlen(out) - 1] = '8';
	return (out);
}
