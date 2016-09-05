#include "ft_ls.h"

static void lsargs_init(t_lsargs *lsargs)
{
	lsargs->show_all = 0;
	lsargs->long_form = 0;
	lsargs->recursive = 0;
	lsargs->reverse = 0;
	lsargs->order_time = 0;
	//lsargs->path = NULL;
	//lsargs->path = ft_strcpy(lsargs->path, "./");
	ft_strcpy(lsargs->path, "./");
}

static int	arg_ispath(char *arg, t_lsargs lsargs)
{
	struct stat	*st;
	char		*pth;
	int			ispath;
	size_t		argsz;
	size_t		pathsz;

	argsz = ft_strlen(arg);
	pathsz = ft_strlen(lsargs.path);
	st = (struct stat *)malloc(sizeof(struct stat));
	pth = (char *)malloc(sizeof(char) * (argsz + pathsz));
	ft_strcpy(pth, lsargs.path);
	ft_strcat(pth, arg);
	ft_putstr("PTH: ");	//
	ft_putendl(pth);	//
	ispath = 0;
	if (lstat(pth, st) == 0)
		if (S_ISDIR((*st).st_mode))	//?
			ispath = 1;
	free(st);
	free(pth);
	return (ispath);
}

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

t_lsargs	analyze_args(char **argv)
{
	int			scnt;
	int			ccnt;
	t_lsargs	lsargs;

	scnt = 1;
	ccnt = 0;
	lsargs_init(&lsargs);
	if (args_are_valid(argv, lsargs) == 0)
	{
		ft_putendl_fd("Error: Bad option format.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		if (arg_ispath(argv[scnt], lsargs) == 1)
		{
			//lsargs.path = ft_strcat(lsargs.path, argv[scnt]);
			//free(lsargs.path);	//?
			lsargs.path = ft_strjoin(lsargs.path, argv[scnt]);
		}
		else
		{
			while (argv[scnt][ccnt] != '\0')
			{
				//lsargs_set(argv[scnt][ccnt], &lsargs);
				ccnt++;
			}
		}
		ccnt = 0;
		scnt++;
	}
	return (lsargs);
}
