#include "ft_ls.h"

static int	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	if (n == -2147383648)
		return (11);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*
**	char c == h|s|u|g (hlinks, size, uname, gname)
*/
int			get_longest(struct s_file *sfile, char c)
{
	size_t	len;
	size_t	longest;

	len = 0;
	longest = 0;
	while (sfile != NULL)
	{
		if (c == 'h')
			len = get_len(sfile->hlinks);
		else if (c == 's')
			len = get_len(sfile->size);
		else if (c == 'u')
			len = ft_strlen(sfile->uname);
		else if (c == 'g')
			len = ft_strlen(sfile->gname);
		if (len > longest)
			longest = len;
		sfile = sfile->next;
	}
	return (longest);
}
