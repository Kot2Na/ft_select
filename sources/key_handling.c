#include "select.h"

void	key_handling(t_dlist *list, t_ttyinfo *tty)
{
	if (tty->key == ESC)
	{
		main_end(0, list, tty);
	}
	tty->key = 0;
}