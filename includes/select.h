#ifndef SELECT_H
# define SELECT_H

# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <sys/ioctl.h>
# include "libft.h"

# define ESC 0x1B
# define RIGHT 0x435B1B
# define LEFT 0x445B1B
# define UP 0x425B1B
# define DOWN 0x415B1B
# define SPACE 0x20
# define BSPACE 0x7F
# define ENTER 0xA
# define DEL 0x7E335B1B

typedef struct winsize	t_win;

typedef struct		s_dlist
{
	char			*item;
	int				selected;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_ttyinfo
{
	int				maxsize;
	int				num;
	int				fd;
	int				key;
	struct termios	term;
	t_dlist			*cursor;
}					t_ttyinfo;

t_ttyinfo			*init_struct(int ac);
int					num_item(t_dlist *start, t_dlist *find);
void				key_handling(t_dlist *list, t_ttyinfo *tty);
void				main_end(int num, t_dlist *list, t_ttyinfo *tty);
void				print_items(t_dlist *list, t_ttyinfo *tty);
void				destr_list(t_dlist *list);
void				toend_list(t_dlist **head, t_dlist *new);
void				right_key(t_dlist *list, t_ttyinfo *tty);
void				left_key(t_dlist *list, t_ttyinfo *tty);
void				up_key(t_dlist *list, t_ttyinfo *tty);
void				down_key(t_dlist *list, t_ttyinfo *tty);
void				space_key(t_dlist *list, t_ttyinfo *tty);
void				enter_key(t_dlist *list, t_ttyinfo *tty);
void				backspace_key(t_dlist *list, t_ttyinfo *tty);
void				print_error(char *text, int code);
t_dlist				*gohead_list(t_dlist *list);
t_dlist				*remove_item(t_dlist *item);
t_dlist				*get_item(t_dlist *list, int n);
t_dlist				*newitem_list(char *item);
t_dlist				*create_list(char **av, t_ttyinfo *tty);

#endif