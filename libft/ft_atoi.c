/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:24:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 10:25:06 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_start(char *s)
{
	int		cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] > 32 && s[cnt] < 127)
			return (cnt);
		cnt++;
	}
	return (-1);
}

int			ft_atoi(char *s)
{
	int		cnt;
	int		out_int;
	int		is_signed;

	out_int = 0;
	is_signed = 0;
	cnt = get_start(s);
	if (cnt == -1)
		return (0);
	if (s[cnt] == '-')
	{
		if (ft_isdigit(s[cnt + 1]) == 0)
			return (0);
		is_signed = 1;
		cnt++;
	}
	while (ft_isdigit(s[cnt]) == 1)
	{
		out_int = out_int * 10 + (s[cnt] - '0');
		cnt++;
	}
	if (is_signed == 1)
		out_int = -out_int;
	return (out_int);
}
