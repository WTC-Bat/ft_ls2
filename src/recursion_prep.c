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

/* ONLY ADD NON-HIDDEN DIRECTORIES UNLESS 'show_all' IS SET TO 1 */
char		**get_dirs(struct s_file *sfile)
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
