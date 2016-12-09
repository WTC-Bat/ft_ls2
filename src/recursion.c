#include "ft_ls.h"

static int	dir_count(struct s_file *sfile)
{
	int		cnt;

	cnt = 0;
	while (sfile != NULL)
	{
		if (sfile->is_dir == 1)
			cnt++;
		sfile = sfile->next;
	}
	return (cnt);
}

static char	**get_dirs(struct s_file *sfile)
{
	char	**dirs;
	int		cnt;
	int		dircnt;

	dircnt = dir_count(sfile);
	if ((dirs = (char **)malloc(sizeof(*dirs) * dircnt + 1)) == NULL)
	{
		ft_putendl_fd("ERROR ALLOCATING DIRS", 2);
		exit(1);
	}
	cnt = 0;
	while (sfile != NULL)
	{
		if (sfile->is_dir == 1)
		{
			if ((ft_endswith(sfile->dir_path, "/.") == 0)
					&& (ft_endswith(sfile->dir_path, "/..")) == 0)
			{
				dirs[cnt] = ft_strdup(sfile->dir_path);
				cnt++;
			}
		}
		sfile = sfile->next;
	}
	dirs[cnt] = NULL;
	return (dirs);
}

static char	*flag_string(t_lsargs lsargs)
{
	char	*argstr;
	int		argcnt;

	if ((argstr = (char *)malloc(sizeof(char) * 7)) == NULL)
	{
		ft_putendl_fd("ERROR ALLOCATING ARGSTR", 2);
		exit(1);
	}
	argcnt = 1;
	argstr[0] = '-';
	if (lsargs.show_all == 1)
		argstr[argcnt++] = 'a';
	if (lsargs.long_form == 1)
		argstr[argcnt++] = 'l';
	if (lsargs.recursive == 1)
		argstr[argcnt++] = 'R';
	if (lsargs.reverse == 1)
		argstr[argcnt++] = 'r';
	if (lsargs.order_time == 1)
		argstr[argcnt++] = 't';
	// lsargs.path	//?
	argstr[argcnt] = '\0';
	if (ft_strequ(argstr, "-") == 1)
		return (NULL);
	else
		return (argstr);
}

static char	**set_args(char *dirpath, t_lsargs lsargs)
{
	char	**args;
	int		argcnt;
	char	*flags;

	if ((args = (char**)malloc(sizeof(*args) * 4)) == NULL)
	{
		ft_putendl("ERROR ALLOCATING ARGS");
		exit(1);
	}
	argcnt = 1;
	flags = flag_string(lsargs);
	args[0] = ft_strdup("./ft_ls");	//?
	if (flags != NULL)
	{
		args[1] = ft_strdup(flags);
		args[2] = ft_strdup(dirpath);
		ft_strdel(&flags);
	}
	else
	{
		args[1] = ft_strdup(dirpath);
	}
	// ft_strdel(&flags);
	args[3] = NULL;
	return (args);
}

static int	arg_count(char **av)
{
	int		cnt;

	cnt = 0;
	while (av[cnt] != NULL)
		cnt++;
	return (cnt);
}

void		recursion(struct s_file *sfile, t_lsargs lsargs)
{
	char	**dirs;
	int		dcnt;
	char	**av;
	int		ac;

	dirs = get_dirs(sfile);
	s_file_free(sfile);
	dcnt = 0;
	ac = 0;
	while (dirs[dcnt] != NULL)	//substr on dirs?
	{
		av = set_args(dirs[dcnt], lsargs);
		ac = arg_count(av);
		// ft_putendl("ARGS SET");
		// int cnt = 0;
		// while (av[cnt] != NULL)
		// {
		// 	ft_putendl(av[cnt]);
		// 	cnt++;
		// }
		// ft_putnbr_endl(ac);
		ft_ls(ac, av);
		star_free(av);
		dcnt++;
	}
	star_free(dirs);
	lsargs_free(lsargs);
}
