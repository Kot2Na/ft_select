#ifndef SELECT_H
# define SELECT_H

# include <termios.h>
# include <term.h>
# include <curses.h>
# include "libft.h"

typedef struct	s_ttyinfo
{
	char		**items;
	char		*select;
	int			fd;
}				t_ttyinfo;

#endif
