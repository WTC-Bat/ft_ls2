#include "ft_ls.h"

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
			//return ;
			break;
		}
		else	//may be uneccesary. may also be a precaution?
		{
			/*
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
			*/
			lsargs->path = ft_strdup("./");
		}
		scnt++;
	}
}

static void lsargs_init(int argc, char **argv, t_lsargs *lsargs)
{
	lsargs->show_all = 0;
	lsargs->long_form = 0;
	lsargs->recursive = 0;
	lsargs->reverse = 0;
	lsargs->order_time = 0;
	lsargs->all_members = 0;
	if (argc > 1)
		lsargs_set_path(lsargs, argv);
	else
		lsargs->path = ft_strdup("./");
}

static void	lsargs_set(char c, t_lsargs *lsargs)
{
	if (c == 'a')
		lsargs->show_all = 1;
	else if (c == 'l')
		lsargs->long_form = 1;
	else if (c == 'r')
		lsargs->reverse = 1;
	else if (c == 't')
		lsargs->order_time = 1;
	else if (c == 'R')
		lsargs->recursive = 1;
	else if (c == 'Z')
		lsargs->all_members = 1;
}

static int	args_are_valid(int argc, char **argv)
{
	int		scnt;

	scnt = 1;
	if (argc == 1)
		return (1);
	else
	{
		while (argv[scnt] != NULL)
		{
			if (arg_ispath(argv[scnt]) == 0 && argv[scnt][0] != '-')
				return (0);
			scnt++;
		}
	}
	return (1);
}

t_lsargs	analyze_args(int argc, char **argv)
{
	int			scnt;
	int			ccnt;
	t_lsargs	lsargs;

	scnt = 1;
	ccnt = 0;
	lsargs_init(argc, argv, &lsargs);
	if (args_are_valid(argc, argv) == 0)
	{
		ft_putendl_fd("Error: Bad option format.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		if (argv[scnt][ccnt] == '-')
		{
			ccnt++;
			while (argv[scnt][ccnt] != '\0')
			{
				lsargs_set(argv[scnt][ccnt], &lsargs);
				ccnt++;
			}
		}
		ccnt = 0;
		scnt++;
	}
	return (lsargs);
}
