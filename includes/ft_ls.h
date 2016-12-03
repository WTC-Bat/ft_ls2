#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <pwd.h>
# include <unistd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct	s_lsargs
{
	int		show_all;
	int		long_form;
	int		recursive;
	int		reverse;
	int		order_time;
	int		all_members;
	char	*path;
}				t_lsargs;

struct			s_file
{
	char			*perms;
	int				hlinks;
	char			*strhlinks;
	char			*uname;
	char			*gname;
	size_t			size;
	char			*strsize;
	time_t			ttmtime;
	char			*mod_time;
	blkcnt_t		block_count;
	char			*name;
	int				is_dir;
	char			*dir_path;
	struct s_file	*next;
};

t_lsargs	analyze_args(int argc, char **argv);
int			arg_ispath(char *arg);
char		*do_pad_left(int longest, int len, char *padstr);
char		*do_pad_right(int longest, int len, char *padstr);
void		do_sort(struct s_file *root, struct s_file *nxt);
// void		format_gname(struct s_file *sfile);
// void		format_links(struct s_file *sfile);
// void		format_size(struct s_file *sfile);
char		*format_time(time_t *ttmtime);
// void		format_uname(struct s_file *sfile);
// int			get_longest_gname(struct s_file *sfile);
// int			get_longest_links(struct s_file *sfile);
// int			get_longest_size(struct s_file *sfile);
// int			get_longest_uname(struct s_file *sfile);
int			get_longest(struct s_file *sfile, char c);
void		handle_print(struct s_file *sfile, t_lsargs lsargs);
void		lsargs_set(char c, t_lsargs *lsargs);
void		lsargs_set_path(t_lsargs *lsargs, char **argv);
void 		lsargs_init(int argc, char **argv, t_lsargs *lsargs);
void		lsargs_free(t_lsargs lsargs);
void		s_file_set_dirpath(struct s_file *sf, struct stat *st, char *pth);
char		*s_file_get_path(t_lsargs lsargs, char *d_name);
// void		s_file_pad(struct s_file *sfile);
char		*s_file_permissions(struct stat *st);
void		s_file_print_members(struct s_file *sfile);
void		s_file_sort_az(struct s_file *sfile);
void		s_file_sort_az_rev(struct s_file *sfile);
void		s_file_sort_mtime(struct s_file *sfile);
void		s_file_sort_mtime_rev(struct s_file *sfile);
void		s_file_format(struct s_file *sfile);
void		s_file_free(struct s_file *sfile);
char		*s_get_name(char *dnm, struct stat *st, char *pth, t_lsargs la);

#endif
