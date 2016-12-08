/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:22:19 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:22:21 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst != NULL)
	{
		tmp = (*alst)->next;
		del((void *)(*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
