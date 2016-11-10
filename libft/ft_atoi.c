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

int		ft_atoi(char *s)
{
	int		cnt;
	int		out_int;

	out_int = 0;
	if (s[0] == '-')
		cnt = 1;
	else
		cnt = 0;
	while (s[cnt] && s[cnt] > 47 && s[cnt] < 58)
	{
		out_int = out_int * 10 + (s[cnt] - '0');
		cnt++;
	}
	if (s[0] == '-')
		out_int = -out_int;
	return (out_int);
}

// int		ft_atoi(char *s)
// {
// 	int		cnt;
// 	int		out_int;
//
// 	cnt = 0;
// 	out_int = 0;
// 	while (s[cnt])
// 	{
// 		out_int = out_int * 10 + (s[cnt] - '0');
// 		cnt++;
// 	}
// 	return (out_int);
// }
