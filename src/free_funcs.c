#include "ft_ls.h"

void	s_file_free(struct s_file *sfile)
{
	while (sfile != NULL)
	{
		// ft_strdel(&(sfile)->perms);
		ft_strdel(&(sfile)->strhlinks);
		ft_strdel(&(sfile)->uname);
		ft_strdel(&(sfile)->gname);
		ft_strdel(&(sfile)->strsize);
		ft_strdel(&(sfile)->mod_time);
			// ft_strdel(&(sfile)->name);
		ft_strdel(&(sfile)->dir_path);
		// free(sfile);
		sfile = sfile->next;
	}
}

void	lsargs_free(t_lsargs lsargs)
{
	free(lsargs.path);
}

void	star_free(char **star)
{
	int		cnt;

	cnt = 0;
	while (star[cnt] != NULL)
	{
		ft_strdel(&star[cnt]);
		cnt++;
	}
}
