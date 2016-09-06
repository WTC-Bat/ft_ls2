#include "ft_ls.h"

int	arg_ispath(char *arg)
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
		ft_putendl_fd("Error: Unknown argument. Check path, if used.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		if (argv[scnt][ccnt] == '-')	//??!!
		{
			if (arg_ispath(argv[scnt]) == 0)
			{
				ccnt++;
				while (argv[scnt][ccnt] != '\0')
				{
					lsargs_set(argv[scnt][ccnt], &lsargs);
					ccnt++;
				}
				ccnt = 0;
			}
		}
		scnt++;
	}
	return (lsargs);
}
