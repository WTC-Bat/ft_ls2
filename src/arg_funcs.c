#include "ft_ls.h"

static void lsargs_init(t_lsargs *lsargs)
{
	lsargs->show_all = 0;
	lsargs->long_form = 0;
	lsargs->recursive = 0;
	lsargs->reverse = 0;
	lsargs->order_time = 0;
	lsargs->path = NULL;
	//lsargs->path = ft_strcpy(lsargs->path, "./");
	//ft_strcpy((*lsargs).path, "./");
}

static int	arg_ispath(char *arg)
{
	struct stat	*st;
	int			ispath;

	st = (struct stat *)malloc(sizeof(struct stat));
	ispath = 0;
	if (lstat(arg, st) == 0)
		if (S_ISDIR((*st).st_mode) > 0)
			ispath = 1;
	return (ispath);
}

static void	lsargs_set_path(t_lsargs *lsargs, char **argv)
{
	int		scnt;
	char	*pth;
	size_t	pthsz;
	size_t	argsz;

	scnt = 1;
	pth = NULL;
	pthsz = 0;
	argsz = 0;
	while (argv[scnt] != NULL)
	{
		if (arg_ispath(argv[scnt]) == 1)
		{
			lsargs->path = ft_strdup(argv[scnt]);
			ft_putendl("Arg is path");
			return ;
		}
		else	//may be uneccesary. may also be a precaution?
		{
			pthsz = ft_strlen(lsargs->path);
			argsz = ft_strlen(argv[scnt]);
			pth = (char *)malloc(sizeof(char) * (pthsz + argsz));
			ft_strcpy(pth, lsargs->path);
			ft_strcat(pth, argv[scnt]);
			if (arg_ispath(pth) == 1)
			{
				lsargs->path = ft_strdup(pth);
				ft_putendl("Arg is path after join");
				return ;
			}
			else
			{
				//lsargs->path = "./";
				lsargs->path = ft_strdup("./"); //?!
				ft_putendl("No Path");
				return ;
			}
			free(pth);
		}
		scnt++;
	}
}

/*
static int	arg_ispath(char *arg, t_lsargs lsargs)
{
	struct stat	*st;
	char		*pth;
	int			ispath;
	size_t		argsz;
	size_t		pathsz;

	argsz = ft_strlen(arg);
	pathsz = 0;
	st = (struct stat *)malloc(sizeof(struct stat));
	pth = NULL;
	ispath = 0;
	if (lstat(arg, st) == 0)
	{
		if (S_ISDIR((*st).st_mode))	//?
			ispath = 1;
	}
	else
	{
		pth = (char *)malloc(sizeof(char) * (argsz + pathsz));
		ft_strcpy(pth, lsargs.path);
		ft_strcat(pth, arg);
		if (lstat(pth, st) == 0)
			if (S_ISDIR((*st).st_mode))
				ispath = 1;
	}
	free(st);
	free(pth);
	return (ispath);
}
*/

/*
static int	args_are_valid(char **argv, t_lsargs lsargs)
{
	int		scnt;

	scnt = 1;
	while (argv[scnt] != NULL)
	{
		//if (arg_ispath(argv[scnt], lsargs) == 0 &&
		//	(ft_strchr(argv[scnt], '-') == NULL))
		//	return (0);
		if (arg_ispath(argv[scnt], lsargs) == 0 &&
			argv[scnt][0] != '-')
			return (0);
		scnt++;
	}
	return (1);
}
*/

static int	args_are_valid(char **argv, t_lsargs lsargs)
{
	int		scnt;
	int		valid;
	char	*pth;
	size_t	argsz;
	size_t	pthsz;

	scnt = 1;
	valid = 1;
	pth = NULL;
	argsz = 0;
	pthsz = 0;
	while (argv[scnt] != NULL)
	{
		if (arg_ispath(argv[scnt]) == 0)
		{
			argsz = ft_strlen(argv[scnt]);
			pthsz = ft_strlen(lsargs.path);
			pth = (char *)malloc(sizeof(char) * (argsz + pthsz));
			ft_strcpy(pth, lsargs.path);
			ft_strcat(pth, argv[scnt]);
			if (arg_ispath(pth) == 0)
				if (argv[scnt][0] != '-')
					valid = 0;
			free(pth);
		}
		scnt++;
	}
	return (valid);
}

t_lsargs	analyze_args(char **argv)
{
	int			scnt;
	int			ccnt;
	t_lsargs	lsargs;

	scnt = 1;
	ccnt = 0;
	lsargs_init(&lsargs);
	lsargs_set_path(&lsargs, argv);
	if (lsargs.path == NULL)
	{
		//lsargs.path = "./";
		lsargs.path = ft_strdup("./");
		ft_putendl("No Args for path");
	}
	if (args_are_valid(argv, lsargs) == 0)
	{
		ft_putendl_fd("Error: Bad option format.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		scnt++;
	}
	return (lsargs);
}
