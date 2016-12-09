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

static char	**set_args(char *dirpath, t_lsargs lsargs)
{
	char	**args;

	if ((args = (char**)malloc(sizeof(*args) * 4)) == NULL)
	{
		ft_putendl("ERROR ALLOCATING ARGS");
		exit(1);
	}
}

void		recursion(struct s_file *sfile, t_lsargs lsargs)
{
	char	**dirs;
	int		dcnt;

	dirs = get_dirs(sfile);
	dcnt = 0;
	while (dirs[dcnt] != NULL)	//substr on dirs?
	{
		dcnt++;
	}

	// int	cnt = 0;
	// ft_putendl("DIRS:");
	// while (dirs[cnt] != NULL)
	// {
	// 	ft_putendl(dirs[cnt]);
	// 	cnt++;
	// }
	// ft_putendl("ENDDIRS");

	if (lsargs.all_members == 1)
	{
		ft_putendl("ERROROROR");
	}
}
