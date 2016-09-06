#include "ft_ls.h"

char	*format_time(time_t *ttmtime)
{
	char	*fmttime;
	char	*tmptime;

	tmptime = ctime(ttmtime);
	fmttime = ft_strsub(tmptime, 4, (ft_strlen(tmptime) - 13));
	return (fmttime);
}

void	format_size(struct s_file *sfile)
{
	char	*strsize;
	char	*fsize;
	int		longest;
	int		len;

	longest = get_longest_size(sfile);
	while (sfile != NULL)
	{
		strsize = ft_itoa(sfile->size);
		len = ft_strlen(strsize);
		if (len < longest)
			fsize = do_pad(longest, len, strsize);
		else
			fsize = ft_strdup(strsize);
		sfile->strsize = fsize;
		sfile = sfile->next;
	}
}

/*
void	format_links(struct s_file *sfile)
{

}

void	format_uname(struct s_file *sfile)
{

}

void	format_gname(struct s_file *sfile)
{

}
*/
