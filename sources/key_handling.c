#include "select.h"

void	key_handling(t_dlist *list, t_ttyinfo *tty)
{
	write(tty->fd, &tty->key, 8);
	if (tty->key = ESC)
	{
		main_end(0, list, tty);
	}
}