#ifndef SELECT_H
# define SELECT_H

# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <sys/ioctl.h>
# include "libft.h"

typedef struct	s_ttyinfo
{
	char			**items;
	char			*selected;
	int				fd;
	struct termios	term;
}				t_ttyinfo;

#endif
