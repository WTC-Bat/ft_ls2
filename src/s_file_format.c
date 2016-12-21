#include "ft_ls.h"

static void	format_hlinks(struct s_file *sfile, size_t longest)
{
	char	*hstr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (sfile != NULL)
	{
		// hstr = ft_strdup(ft_itoa(sfile->hlinks)); //ft_itoa allocation is un-freeable. need to take a look
		hstr = ft_itoa(sfile->hlinks);
		len = ft_strlen(hstr);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
			{
				if (hstr != NULL)
				{
					sfile->strhlinks = ft_strdup(hstr);
					continue;
				}
			}
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			sfile->strhlinks = ft_strjoin(pad, hstr);
			ft_strdel(&pad);
		}
		else
		{
			sfile->strhlinks = ft_strdup(hstr);
		}
		// ft_strdel(&hstr);
		sfile = sfile->next;
	}
}

static void	format_size(struct s_file *sfile, size_t longest)
{
	char	*sstr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (sfile != NULL)
	{
		sstr = ft_strdup(ft_itoa(sfile->size));
		len = ft_strlen(sstr);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
			{
				if (sstr != NULL)
				{
					sfile->strsize = ft_strdup(sstr);
					continue;
				}
			}
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			sfile->strsize = ft_strjoin(pad, sstr);
			ft_strdel(&pad);
		}
		else
		{
			sfile->strsize = ft_strdup(sstr);
		}
		ft_strdel(&sstr);
		sfile = sfile->next;
	}
}


static void	format_uname(struct s_file *sfile, size_t longest)
{
	char	*ustr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (sfile != NULL)
	{
		len = ft_strlen(sfile->uname);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
				continue;
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			ustr = ft_strdup(sfile->uname);
			ft_strdel(&(sfile)->uname);
			sfile->uname = ft_strjoin(pad, ustr);
			ft_strdel(&ustr);
			ft_strdel(&pad);
		}
		sfile = sfile->next;
	}
}


static void	format_gname(struct s_file *sfile, size_t longest)
{
	char	*gstr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (sfile != NULL)
	{
		len = ft_strlen(sfile->gname);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
				continue;
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			gstr = ft_strdup(sfile->gname);
			ft_strdel(&(sfile)->gname);
			sfile->gname = ft_strjoin(pad, gstr);
			ft_strdel(&gstr);
			ft_strdel(&pad);
		}
		sfile = sfile->next;
	}
}

void		s_file_format(struct s_file *sfile)
{
	size_t	hlen;
	size_t	slen;
	size_t	ulen;
	size_t	glen;

	hlen = get_longest(sfile, 'h');
	format_hlinks(sfile, hlen);
	slen = get_longest(sfile, 's');
	format_size(sfile, slen);
	ulen = get_longest(sfile, 'u');
	format_uname(sfile, ulen);
	glen = get_longest(sfile, 'g');
	format_gname(sfile, glen);
}
