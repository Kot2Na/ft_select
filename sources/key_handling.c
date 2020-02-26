#include "select.h"

void	key_handling(t_dlist *list, t_ttyinfo *tty)
{
	if (tty->key == ESC)
		main_end(0, list, tty);
	else if (tty->key == RIGHT)
		right_key(list, tty);
	else if (tty->key == LEFT)
		left_key(list, tty);
	else if (tty->key == UP)
		up_key(list, tty);
	else if (tty->key == DOWN)
		down_key(list, tty);
	else if (tty->key == SPACE)
		space_key(list, tty);
	else if (tty->key == BSPACE)
		backspace_key(list, tty);
	tty->key = 0;
}

void	space_key(t_dlist *list, t_ttyinfo *tty)
{
	t_dlist *cursor;

	if (list && tty)
	{
		cursor = tty->cursor;
		if (cursor->selected)
			cursor->selected = 0;
		else
			cursor->selected = 1;
	}
}

void	backspace_key(t_dlist *list, t_ttyinfo *tty)
{
	if (list && tty)
	{
		tty->cursor = remove_item(tty->cursor);
		tty->num -= 1;
		if (tty->cursor == NULL)
			main_end(0, NULL, tty);
	}
}