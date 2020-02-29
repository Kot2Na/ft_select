#include "select.h"

void	main_end(int num)
{
	t_ttyinfo	*tty;
	t_dlist		*head;

	tty = NULL;
	tty = safe_tty(&tty);
	if (tty)
	{
		head = gohead_list(tty->cursor);
		if (num == -1)
			ft_putstr_fd(tgetstr("cl", NULL), tty->fd);
		ft_putstr_fd(tgetstr("me", NULL), tty->fd);
		ft_putstr_fd(tgetstr("ve", NULL), tty->fd);
		tty->term.c_lflag |= (ECHO | ICANON);
		tty->term.c_oflag |= (OPOST);
		tcsetattr(tty->fd, TCSANOW, &tty->term);
		destr_list(head);
		close(tty->fd);
		free(tty);
	}
	exit(num);
}