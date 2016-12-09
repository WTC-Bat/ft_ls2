#include "ft_ls.h"

int		main(int argc, char **argv)
{
	if (argc == 0)
	{
		ft_putendl_fd("Error: How did you even...?", 2);
		exit(1);
	}
	ft_ls(argc, argv);
	return (0);
}
