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

	strsize = NULL;
	fsize = NULL;
	longest = get_longest_size(sfile);
	len = 0;
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

void	format_links(struct s_file *sfile)
{
	char	*strlinks;
	char	*flinks;
	int		longest;
	int		len;

	strlinks = NULL;
	flinks = NULL;
	longest = get_longest_links(sfile);
	len = 0;
	while (sfile != NULL)
	{
		strlinks = ft_itoa(sfile->hlinks);
		len = ft_strlen(strlinks);
		if (len < longest)
			flinks = do_pad(longest, len, strlinks);
		else
			flinks = ft_strdup(strlinks);
		sfile->strhlinks = flinks;
		sfile = sfile->next;
	}
}

/*
**	At this point, uname is already set. To pad it, 'sfile->uname'
**	will need to be "re-set" to the padded value
*/
/*
void	format_uname(struct s_file *sfile)
{
	char	*funame;
	int		longest;
	int		len;

	funame = NULL;
	longest = get_longest_uname(sfile);
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(sfile->uname);
		if (len < longest)
		{
			funame = do_pad(longest, len, sfile->uname);
			ft_putendl("CLR: UNAME");
			ft_strclr(sfile->uname);
			ft_putendl("CLRD: UNAME");
			ft_putendl("FREE: UNAME");
			free(sfile->uname);
			ft_putendl("FREED: UNAME");
			sfile->uname = funame;
		}
	}
}
*/

/*
**	At this point, gname is already set. To pad it, 'sfile->gname'
**	will need to be "re-set" to the padded value
*/
/*
void	format_gname(struct s_file *sfile)
{
	char	*fgname;
	int		longest;
	int		len;

	fgname = NULL;
	longest = get_longest_gname(sfile);
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(sfile->gname);
		if (len < longest)
		{
			fgname = do_pad(longest, len, sfile->gname);
			ft_putendl("CLR: GNAME");
			ft_strclr(sfile->gname);
			ft_putendl("CLRD: GNAME");
			ft_putendl("FREE: GNAME");
			free(sfile->gname);
			ft_putendl("FREED: GNAME");
			sfile->gname = fgname;
		}
	}
}
*/

/*
**	At this point, uname is already set. To pad it, 'sfile->uname'
**	will need to be "re-set" to the padded value
*/
void	format_uname(struct s_file *sfile)
{
	char	*funame;
	int		longest;
	int		len;

	funame = NULL;
	longest = get_longest_uname(sfile);
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(sfile->uname);
		if (len < longest)
		{
			funame = do_pad(longest, len, sfile->uname);
			ft_putendl("CLR: UNAME");
			ft_strclr(sfile->uname);
			ft_putendl("CLRD: UNAME");
			ft_putendl("FREE: UNAME");
			free(sfile->uname);
			ft_putendl("FREED: UNAME");
			sfile->uname = funame;
		}
	}
}

/*
**	At this point, gname is already set. To pad it, 'sfile->gname'
**	will need to be "re-set" to the padded value
*/
void	format_gname(struct s_file *sfile)
{
	char	*fgname;
	int		longest;
	int		len;

	fgname = NULL;
	longest = get_longest_gname(sfile);
	len = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(sfile->gname);
		if (len < longest)
		{
			fgname = do_pad(longest, len, sfile->gname);
			ft_putendl("CLR: GNAME");
			ft_strclr(sfile->gname);
			ft_putendl("CLRD: GNAME");
			ft_putendl("FREE: GNAME");
			free(sfile->gname);
			ft_putendl("FREED: GNAME");
			sfile->gname = fgname;
		}
	}
}
