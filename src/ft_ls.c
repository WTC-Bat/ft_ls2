#include "ft_ls.h"

static void				getelems2(struct s_file *sfile, struct stat *st)
{
	struct passwd	*pd;
	struct group	*gp;

	pd = getpwuid(st->st_uid);
	gp = getgrgid(st->st_gid);
	sfile->perms = s_file_permissions(st);
	sfile->hlinks = st->st_nlink;
	sfile->uname = ft_strdup(pd->pw_name);
	sfile->gname = ft_strdup(gp->gr_name);
	sfile->size = st->st_size;
	sfile->ttmtime = st->st_mtime;
	sfile->mod_time = format_time(&st->st_mtime);
	sfile->block_count = st->st_blocks;
	sfile->is_dir = 0;
	sfile->dir_path = NULL;
}

static struct s_file	*s_file_getelems(DIR *d, t_lsargs lsargs)
{
	struct dirent	*dent;
	struct stat		*st;
	struct s_file	*current;
	struct s_file	*root;
	char			*pth;

	root = NULL;
	st = (struct stat *)malloc(sizeof(struct stat));
	while ((dent = readdir(d)) != NULL)
	{
		pth = s_file_get_path(lsargs, dent->d_name);
		lstat(pth, st);
		current = (struct s_file *)malloc(sizeof(struct s_file));
		current->name = s_get_name(dent->d_name, st, pth, lsargs);
		getelems2(current, st);
		s_file_set_dirpath(current, st, pth);
		ft_putendl("FREE: PTH");
		free(pth);
		ft_putendl("FREED: PTH");
		current->next = root;
		root = current;
	}
	free(st);
	s_file_pad(root);
	return (root);
}

static struct s_file	*s_file_init(t_lsargs lsargs)
{
	DIR				*d;
	struct s_file	*sfile;

	d = opendir(lsargs.path);
	if (d == NULL)
	{
		ft_putstr_fd("Error: unable to opendir - ", 2);
		ft_putendl_fd(lsargs.path, 2);
		exit(1);
	}
	sfile = s_file_getelems(d, lsargs);
	closedir(d);
	return (sfile);
}

static void				initialize(struct s_file *sfile, t_lsargs lsargs)
{
	if (lsargs.all_members == 1)
		s_file_print_members(sfile);
	else
	{
		if (lsargs.order_time == 1)
			if (lsargs.reverse == 1)
				s_file_sort_mtime_rev(sfile);
			else
				s_file_sort_mtime(sfile);
		else
			if (lsargs.reverse == 1)
				s_file_sort_az_rev(sfile);
			else
				s_file_sort_az(sfile);
		handle_print(sfile, lsargs);
	}
}

int						main(int argc, char **argv)
{
	struct s_file	*sfile;
	t_lsargs		lsargs;

	if (argc == 0)
	{
		ft_putendl_fd("Error: How did you even...?", 2);
		exit(1);
	}
	lsargs = analyze_args(argc, argv);
	sfile = s_file_init(lsargs);
	initialize(sfile, lsargs);
	//free
	return (0);
}
