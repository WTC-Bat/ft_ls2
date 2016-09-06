#include "ft_ls.h"

char	*s_get_name(char *dnm, struct stat *st, char *pth, t_lsargs la)
{
	char	*name;
	char	*lname;
	size_t	nsz;
	size_t	lnsz;

	lname = NULL;
	nsz = 0;
	lnsz = 0;
	if (S_ISLNK(st->st_mode) > 0)
	{
		if (la.long_form == 1)
		{
			lname = (char *)malloc(sizeof(char) * 1024);
			readlink(pth, lname, 1024);	//!?
			nsz = ft_strlen(dnm);
			lnsz = ft_strlen(lname);
			name = (char *)malloc(sizeof(char) * (nsz + lnsz + 4));
			//?
			ft_strcpy(name, dnm);
			ft_strcat(name, " -> ");
			ft_strcat(name, lname);
			//?
			free(lname);
			return (name);
		}
	}
	return (dnm);
}
