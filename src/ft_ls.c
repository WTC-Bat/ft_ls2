#include "ft_ls.h"

static void				*getelems2(struct s_file *sfile, struct stat *st)
{

}

static struct s_file	*s_file_getelems(DIR *d, t_lsargs lsargs)
{
	struct dirent	*dent;
	struct stat		*st;
	struct s_file	*current;
	struct s_file	*root;
	char			*pth;

	root = NULL;
	while ((dent = readdir(d)) != NULL)
	{
		pth = ft_strjoin(lsargs.path, dent->d_name);
		st = (struct stat *)malloc(sizeof(struct stat));
		lstat(pth, st);
		current = (struct s_file *)malloc(sizeof(struct s_file));
		current->name = s_get_name(dent->d_name, st, pth, lsargs);
		ft_putendl(current->name);
		//getelems2(current, st);

		free(pth);
		free(st);
		current->next = root;
		root = current;
	}
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

int						main(int argc, char **argv)
{
	struct s_file	*sfile;
	t_lsargs		lsargs;

	if (argc == 0)
	{
		ft_putendl("Exiting");
		exit(1);
	}
	lsargs = analyze_args(argc, argv);
	sfile = s_file_init(lsargs);
	//initialize
	//free
	return (0);
}
