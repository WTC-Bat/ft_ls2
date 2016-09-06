#include "ft_ls.h"

static void	s_file_print_members2(struct s_file *sfile)
{
	if (sfile->dir_path != NULL)
		ft_putendl(sfile->dir_path);
	else
		ft_putchar('\n');
}

void		s_file_print_members(struct s_file *sfile)
{
	while (sfile != NULL)
	{
		ft_putstr("Permissions:\t");
		ft_putendl(sfile->perms);
		ft_putstr("Hardlinks:\t");
		ft_putnbr_endl(sfile->hlinks);
		ft_putstr("User Name:\t");
		ft_putendl(sfile->uname);
		ft_putstr("Group Name:\t");
		ft_putendl(sfile->gname);
		ft_putstr("Size:\t\t");
		ft_putnbr_endl(sfile->size);
		ft_putstr("Modified Time:\t");
		ft_putendl(sfile->mod_time);
		ft_putstr("Name:\t\t");
		ft_putendl(sfile->name);
		ft_putstr("Is Directory:\t");
		ft_putnbr_endl(sfile->is_dir);
		ft_putstr("Directory Path:\t");
		s_file_print_members2(sfile);
		ft_putchar('\n');
		sfile = sfile->next;
	}
}
