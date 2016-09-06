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
char		*format_time(time_t *ttmtime);
void		lsargs_set(char c, t_lsargs *lsargs);
void		lsargs_set_path(t_lsargs *lsargs, char **argv);
void 		lsargs_init(int argc, char **argv, t_lsargs *lsargs);
char		*s_file_get_path(t_lsargs lsargs, char *d_name);
char		*s_file_permissions(struct stat *st);
char		*s_get_name(char *dnm, struct stat *st, char *pth, t_lsargs la);

#endif
