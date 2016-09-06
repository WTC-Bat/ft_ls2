//#include "../includes/ft_ls.h"
#include "ft_ls.h"

void	lsargs_set_path(t_lsargs *lsargs, char **argv)
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

void lsargs_init(int argc, char **argv, t_lsargs *lsargs)
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

void	lsargs_set(char c, t_lsargs *lsargs)
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
	else
	{
		ft_putstr_fd("Error: Unknown option \'-", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("\'", 2);
		exit(1);
	}
}
