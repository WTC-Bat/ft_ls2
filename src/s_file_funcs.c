#include "ft_ls.h"

static char	*s_file_permissions2(struct stat *st, char *perms)
{
	char	*outperms;

	if (st->st_mode & S_IWOTH)
		perms[8] = 'w';
	if (st->st_mode & S_IXOTH)
		perms[9] = 'x';
	perms[10] = '\0';
	outperms = ft_strdup(perms);
	ft_strdel(&perms);
	return (outperms);
}

char	*s_file_permissions(struct stat *st)
{
	char	*perms;

	perms = (char *)malloc(sizeof(char) * 11);
	ft_memset(perms, '-', 10);
	if (S_ISDIR(st->st_mode) > 0)
		perms[0] = 'd';
	if (st->st_mode & S_IRUSR)
		perms[1] = 'r';
	if (st->st_mode & S_IWUSR)
		perms[2] = 'w';
	if (st->st_mode & S_IXUSR)
		perms[3] = 'x';
	if (st->st_mode & S_IRGRP)
		perms[4] = 'r';
	if (st->st_mode & S_IWGRP)
		perms[5] = 'w';
	if (st->st_mode & S_IXGRP)
		perms[6] = 'x';
	if (st->st_mode & S_IROTH)
		perms[7] = 'r';
	return (s_file_permissions2(st, perms));
}

char	*s_get_name(char *dnm, struct stat *st, char *pth, t_lsargs la)
{
	char	*name;
	char	*lname;
	char	*tmp;

	lname = NULL;
	if (S_ISLNK(st->st_mode) > 0)
	{
		if (la.long_form == 1)
		{
			lname = (char *)malloc(sizeof(char) * 1024);
			readlink(pth, lname, 1024);
			name = ft_strdup(dnm);
			tmp = ft_strjoin(name, " -> ");
			ft_strdel(&name);
			name = ft_strjoin(tmp, lname);
			ft_strdel(&lname);
			ft_strdel(&tmp);
			return (name);
		}
	}
	return (dnm);
}

char	*s_file_get_path(t_lsargs lsargs, char *d_name)
{
	char	*pth;
	char	*join;
	size_t	pthsz;
	size_t	dnamesz;

	pthsz = ft_strlen(lsargs.path);
	dnamesz = ft_strlen(d_name);
	pth = ft_strdup(lsargs.path);
	if (ft_strequ(pth, "./") == 0)
		join = ft_strjoin(pth, "/");
	else
		join = ft_strjoin(pth, d_name);
	ft_strdel(&pth);
	return(join);
}

void	s_file_set_dirpath(struct s_file *sf, struct stat *st, char *pth)
{
	if (S_ISDIR(st->st_mode) > 0)
	{
		sf->is_dir = 1;
		sf->dir_path = ft_strdup(pth);
	}
}

void	s_file_free(struct s_file *sfile)
{
	struct s_file	*tmp;

	while (sfile != NULL)
	{
		tmp = sfile;
		ft_strdel(&(sfile)->perms);
		ft_strdel(&(sfile)->strhlinks);
		ft_strdel(&(sfile)->uname);
		ft_strdel(&(sfile)->gname);
		ft_strdel(&(sfile)->strsize);
		ft_strdel(&(sfile)->mod_time);
			// ft_strdel(&(sfile)->name);	//NOT ALLOCATED?
		ft_strdel(&(sfile)->dir_path);
		sfile = sfile->next;
		free(tmp);
	}
}
