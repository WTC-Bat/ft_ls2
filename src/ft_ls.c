#include "ft_ls.h"


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
	//sfile = s_file_getelems(d, lsargs);
	closedir(d);
	sfile = NULL;	// !<--!
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
