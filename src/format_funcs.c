#include "ft_ls.h"

char	*format_time(time_t *ttmtime)
{
	char	*fmttime;
	char	*tmptime;

	tmptime = ctime(ttmtime);
	fmttime = ft_strsub(tmptime, 4, (ft_strlen(tmptime) - 13));
	return (fmttime);
}
