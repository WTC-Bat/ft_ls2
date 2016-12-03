#include "ft_ls.h"

char	*do_pad_left(int longest, int len, char *padstr)
{
	char	*pad;
	char	*fsize;

	// ft_putnbr_endl(longest);
	// ft_putnbr_endl(len);
	ft_putendl("MALLOCING PAD");
	//mallocing pad is giving incorrect checksum for freed object error
	pad = (char *)malloc(sizeof(char) * (longest - len) + 1);
	ft_putendl("PAD MALLOC'D");
	ft_memset(pad, ' ', (longest - len));
	ft_putendl("MEMSET");
	pad[(longest - len)] = '\0';
	ft_putendl("MALLOCING FSIZE");
	// fsize = (char *)malloc(sizeof(char) * len + (longest - len) + 1);	//+1?
	fsize = (char *)malloc(sizeof(char) * (longest - (len - 1)));
	ft_putendl("FSIZE MALLOC'D");
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
	// ft_memset(pad, ' ', (longest - len));	//+1?
	ft_memset(pad, ' ', (longest - (len - 1)));
	pad[(longest - len)] = '\0';
	// fsize = (char *)malloc(sizeof(char) * len + (longest - len));	//+1?
	fsize = (char *)malloc(sizeof(char) * len + (longest - (len - 1)));
	ft_strcpy(fsize, padstr);
	ft_strcat(fsize, pad);
	free(pad);
	return (fsize);
}
