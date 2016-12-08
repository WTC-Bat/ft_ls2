void	s_file_free(struct s_file *sfile)
{
	struct s_file	*tmp;

	while (sfile != NULL)
	{
		tmp = sfile;
		sfile = sfile->next;
		// ft_strclr(tmp->perms);
		free(tmp->perms);
		// ft_strclr(tmp->strhlinks);
		free(tmp->strhlinks);
		// ft_strclr(tmp->uname);
		free(tmp->uname);
		// ft_strclr(tmp->gname);
		free(tmp->gname);
		// ft_strclr(tmp->strsize);
		free(tmp->strsize);
		// ft_strclr(tmp->mod_time);
		free(tmp->mod_time);
		// ft_strclr(tmp->name);
		free(tmp->name);
		// ft_strclr(tmp->dir_path);
		free(tmp->dir_path);
	}
}
