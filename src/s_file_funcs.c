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
	free(perms);
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
	size_t	nsz;
	size_t	lnsz;

	lname = NULL;
	nsz = 0;
	lnsz = 0;
	if (S_ISLNK(st->st_mode) > 0)
	{
		if (la.long_form == 1)
		{
			lname = (char *)malloc(sizeof(char) * 1024);
			readlink(pth, lname, 1024);	//!?
			nsz = ft_strlen(dnm);
			lnsz = ft_strlen(lname);
			name = (char *)malloc(sizeof(char) * (nsz + lnsz + 4));
			ft_strcpy(name, dnm);
			ft_strcat(name, " -> ");
			ft_strcat(name, lname);
			free(lname);
			return (name);
		}
	}
	return (dnm);
}

char	*s_file_get_path(t_lsargs lsargs, char *d_name)
{
	char	*pth;
	size_t	pthsz;
	size_t	dnamesz;

	pthsz = ft_strlen(lsargs.path);
	dnamesz = ft_strlen(d_name);
	pth = (char *)malloc(sizeof(char) * (pthsz + dnamesz + 2));	//?1
	ft_strcpy(pth, lsargs.path);
	//if (ft_strcmp(pth, "./") != 0)
	if (ft_strequ(pth, "./") == 0)
		ft_strcat(pth, "/");
	ft_strcat(pth, d_name);
	return(pth);
}

void	s_file_pad(struct s_file *sfile)
{
	ft_putendl("FORMATTING");
	format_size(sfile);
	ft_putendl("FORMATTED SIZE");
	format_links(sfile);
	ft_putendl("FORMATTED LINKS");
	format_uname(sfile);
	ft_putendl("FORMATTED UNAME");
	format_gname(sfile);
	ft_putendl("FORMATTED GNAME");

	//foramt date??? shouldn't have to
}

void	s_file_set_dirpath(struct s_file *sf, struct stat *st, char *pth)
{
	if (S_ISDIR(st->st_mode) > 0)
	{
		sf->is_dir = 1;
		sf->dir_path = ft_strdup(pth);
	}
	/*
	else
	{
		sf->is_dir = 0;
		sf->dir_path = ft_strdup("./");
	}
	*/
}
