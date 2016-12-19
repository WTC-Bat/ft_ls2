#include "ft_ls.h"

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

static int	arg_count(char **av)
{
	int		cnt;

	cnt = 0;
	while (av[cnt] != NULL)
		cnt++;
	return (cnt);
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

void		recursion(char **dirs, t_lsargs lsargs)
{
	int		dcnt;
	char	**av;
	int		ac;

	dcnt = 0;
	ac = 0;
	while (dirs[dcnt] != NULL)	//substr on dirs?
	{
		av = set_args(dirs[dcnt], lsargs);
		ac = arg_count(av);
		ft_ls(ac, av);
		star_free(av);
		dcnt++;
	}
	star_free(dirs);
	// lsargs_free(lsargs);
}