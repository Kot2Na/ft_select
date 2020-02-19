#include "select.h"

void	main_end(int num, t_dlist *list, t_ttyinfo *tty)
{
	tty->term.c_lflag |= (ECHO | ICANON);
	tty->term.c_oflag |= (OPOST);
	tcsetattr(tty->fd, TCSANOW, &tty->term);
	destr_list(list);
	close(tty->fd);
	free(tty);
	exit(num);
}