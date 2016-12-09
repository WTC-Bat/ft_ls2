#include "ft_ls.h"

static int	dir_count(struct s_file *sfile)
{
	int		dcnt;

	dcnt = 0;
	while  (sfile != NULL)
	{
		if (sfile->is_dir)
			dcnt++;
		sfile = sfile->next;
	}
	return (dcnt);
}

static char	**get_dirs(struct s_file *sfile)
{
	char	**dirs;
	int		dircnt;
	int		dcnt;

	dircnt = dir_count(sfile);
	if ((dirs = (char **)malloc(sizeof(*dirs) + dircnt + 1)) == NULL)
		return (NULL);
	dcnt = 0;
	while (sfile != NULL)
	{
		if (sfile->is_dir)
		{
			if ((ft_endswith(sfile->dir_path, "/.") == 0)
				&& (ft_endswith(sfile->dir_path, "/..")) == 0)
			{
				dirs[dcnt] = ft_strdup(sfile->dir_path);
				dcnt++;
			}
		}
		sfile = sfile->next;
	}
	dirs[dcnt] = NULL;
	return (dirs);
}

static char	**set_args(char *dir, t_lsargs lsargs)
{
	char	**args;
	int		argcnt;
	char	*astr;
	int		acnt;

	if ((args = malloc(sizeof(*args))) == NULL)
		return (NULL);
	if ((astr = malloc(sizeof(char) * 6)) == NULL)
		return (NULL);
	argcnt = 1;
	acnt = 1;
	args[0] = ft_strdup("./ft_ls");
	astr[0] = '-';
	if (lsargs.show_all == 1)
		astr[acnt++] = 'a';
	if (lsargs.long_form == 1)
		astr[acnt++] = 'l';
	if (lsargs.recursive == 1)
		astr[acnt++] = 'R';
	if (lsargs.reverse == 1)
		astr[acnt++] = 'r';
	if (lsargs.order_time == 1)
		astr[acnt++] = 't';
	astr[acnt] = '\0';
	args[argcnt++] = ft_strdup(astr);
	args[argcnt++] = ft_strdup(dir);
	args[argcnt] = NULL;
	ft_strdel(&astr);
	// int		cnt = 0;
	// while (args[cnt] != NULL)
	// {
	// 	ft_putstr("ARG: ");
	// 	ft_putendl(args[cnt]);
	// 	cnt++;
	// }
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

void	recursion(struct s_file *sfile, t_lsargs lsargs)
{
	char	**dirs;
	int		dcnt;
	char	**av;
	int		ac;

	if ((dirs = get_dirs(sfile)) == NULL)				//?
	{
		ft_putendl_fd("Error in 'get_dirs()'", 2);
		exit(0);
	}
	dcnt = 0;
	while (dirs[dcnt] != NULL)
	{
		av = set_args(dirs[dcnt], lsargs);
		ft_putendl("GOT ARGS");
		ac = arg_count(av);
		ft_putendl("GOT COUNT");
		ft_ls(ac, av);
		dcnt++;
	}
	free(dirs);
}
