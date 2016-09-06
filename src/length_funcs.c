#include "ft_ls.h"

int		get_longest_gname(struct s_file *sfile)
{
	int		longest;
	int		len;

	longest = 0;
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(sfile->gname);
		if (len > longest)
			longest = len;
		sfile = sfile->next;
	}
	return (longest);
}

int		get_longest_links(struct s_file *sfile)
{
	int		longest;
	int		len;

	longest = 0;
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(ft_itoa(sfile->hlinks));
		if (len > longest)
			longest = len;
		sfile = sfile->next;
	}
	return (longest);
}

int		get_longest_size(struct s_file *sfile)
{
	int		longest;
	int		len;

	longest = 0;
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(ft_itoa(sfile->size));
		if (len > longest)
			longest = len;
		sfile = sfile->next;
	}
	return (longest);
}

int		get_longest_uname(struct s_file *sfile)
{
	int		longest;
	int		len;

	longest = 0;
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(sfile->uname);
		if (len > longest)
			longest = len;
		sfile = sfile->next;
	}
	return (longest);
}
