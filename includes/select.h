#ifndef SELECT_H
# define SELECT_H

# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <sys/ioctl.h>
# include "libft.h"

# define ESC 0x1B

typedef struct		s_dlist
{
	char			*item;
	int				selected;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct	s_ttyinfo
{
	int				maxsize;
	int				num;
	int				fd;
	long			key;
	struct termios	term;
	t_dlist			*cursor;
}				t_ttyinfo;

t_ttyinfo			*init_struct(char **env);
void				key_handling(t_dlist *list, t_ttyinfo *tty);
void				main_end(int num, t_dlist *list, t_ttyinfo *tty);
void				print_items(t_dlist *list, t_ttyinfo *tty);
void				destr_list(t_dlist *list);
void				toend_list(t_dlist **head, t_dlist *new);
t_dlist				*newitem_list(char *item);
t_dlist				*create_list(char **av);

#endif
