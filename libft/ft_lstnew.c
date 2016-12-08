/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:22:57 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:22:58 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if ((lst->content = (void *)malloc(sizeof(content_size))) == NULL)
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}

// t_list	*ft_lstnew(void const *content, size_t content_size)
// {
// 	t_list	*lst;
//
// 	lst = (t_list *)malloc(sizeof(t_list));
// 	if (!lst)
// 		return (NULL);
// 	if (content == NULL)
// 	{
// 		lst->content = NULL;
// 		lst->content_size = 0;
// 	}
// 	else
// 	{
// 		lst->content = (void *)malloc(sizeof(content));
// 		if (lst->content == NULL)
// 			return (NULL);
// 		ft_memcpy(lst->content, content, content_size);
// 		lst->content_size = content_size;
// 	}
// 	lst->next = NULL;
// 	return (lst);
// }
