#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*tmp;

	newlist = NULL;
	tmp = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if ((newlist = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		newlist = f(lst);
		newlist->next = tmp;
		tmp = newlist;
		lst = lst->next;
	}
	return (newlist);
}
