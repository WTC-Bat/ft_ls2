#include "ft_ls.h"

char	*do_pad_left(int longest, int len, char *padstr)
{
	char	*pad;
	char	*fsize;

	pad = (char *)malloc(sizeof(char) * (longest - len) + 1);
	ft_memset(pad, ' ', (longest - len));
	pad[(longest - len)] = '\0';
	fsize = (char *)malloc(sizeof(char) * len + (longest - len) + 1);	//+1?
	ft_strcpy(fsize, pad);
	ft_strcat(fsize, padstr);
	free(pad);
	return (fsize);
}

char	*do_pad_right(int longest, int len, char *padstr)
{
	char	*pad;
	char	*fsize;

	pad = (char *)malloc(sizeof(char) * (longest - len) + 1);
	ft_memset(pad, ' ', (longest - len));	//+1?
	pad[(longest - len)] = '\0';
	fsize = (char *)malloc(sizeof(char) * len + (longest - len));	//+1?
	ft_strcpy(fsize, padstr);
	ft_strcat(fsize, pad);
	free(pad);
	return (fsize);
}
