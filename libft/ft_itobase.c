/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:41:32 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/06 13:09:30 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itobase(int n, int base)
{
	char	*basechars;
	char	*tmp;
	char	*baseout;
	int		cnt;
	int		i;

	basechars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cnt = 0;
	tmp = (char *)malloc(sizeof(char) * 64);
	baseout = (char *)malloc(sizeof(tmp));
	while (n > 0)
	{
		i = n % base;
		n = n / base;
		tmp[cnt] = basechars[i];
		cnt++;
	}
	baseout = ft_strrev(tmp);
	baseout[cnt] = '\0';
	return (baseout);
}
