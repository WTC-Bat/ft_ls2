#include "ft_ls.h"

static void	s_file_prent_basic(struct s_file *sfile)
{
	ft_putstr(sfile->name);
	if (sfile->next == NULL)
		ft_putchar('\n');
	else
		ft_putstr("  ");
}

static void	s_file_prent_long(struct s_file *sfile)
{
	ft_putstr(sfile->perms);
	ft_putchar(' ');
	//ft_putstr(sfile->strhlinks);		//////
	ft_putstr(ft_itoa(sfile->hlinks));
	ft_putchar(' ');
	ft_putstr(sfile->uname);
	ft_putchar(' ');
	ft_putstr(sfile->gname);
	ft_putchar(' ');
	//ft_putstr(sfile->strsize);		/////
	ft_putstr(ft_itoa(sfile->size));
	ft_putchar(' ');
	ft_putstr(sfile->mod_time);
	ft_putchar(' ');
	ft_putstr(sfile->name);
	ft_putchar('\n');
}

/*
**	Block count must be modified to include/exclude hidden files depending on whether the -a option
**	is specified or not.
*/
void	blocks_print_total(struct s_file *sfile, t_lsargs lsargs)
{
	int	blocks;

	blocks = 0;
	ft_putstr("total ");
	while (sfile != NULL)
	{
		if (lsargs.show_all == 0)
		{
			if (sfile->name[0] != '.')
			{
				blocks += sfile->block_count;
			}
		}
		else
		{
			blocks += sfile->block_count;
		}
		sfile = sfile->next;
	}
	ft_putnbr_endl(blocks);
}

/*
void	blocks_print_total(struct s_file *sfile)
{
	int	blocks;

	blocks = 0;
	ft_putstr("total ");
	while (sfile != NULL)
	{
		blocks += sfile->block_count;
		sfile = sfile->next;
	}
	ft_putnbr_endl(blocks);
}
*/

void	handle_print(struct s_file *sfile, t_lsargs lsargs)
{
	if (lsargs.long_form == 1)
		blocks_print_total(sfile, lsargs);
	while (sfile != NULL)
	{
		if (sfile->name[0] == '.')
		{
			if (lsargs.show_all == 1)
			{
				if (lsargs.long_form == 1)
					s_file_prent_long(sfile);
				else
					s_file_prent_basic(sfile);
			}
		}
		else
		{
			if (lsargs.long_form == 1)
				s_file_prent_long(sfile);
			else
				s_file_prent_basic(sfile);
		}
		sfile = sfile->next;
	}
}
