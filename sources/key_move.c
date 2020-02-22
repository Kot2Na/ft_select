#include "select.h"

void	get_cor(t_dlist *list, t_ttyinfo *tty, int *x, int *y)
{
	int i;
	t_win win;

	ioctl(tty->fd, TIOCGWINSZ, &win);
	if ((i = num_item(list, tty->cursor)) >= 0)
	{
		*x = i / win.ws_row;
		*y = i % win.ws_row;
	}
}

void	change_cursor(t_dlist *list, t_ttyinfo *tty, int x, int y)
{
	int i;
	t_win win;

	ioctl(tty->fd, TIOCGWINSZ, &win);
	if (tty->key == DOWN || tty->key == UP)
	{
		if (y >= win.ws_row || x * win.ws_row + y >= tty->num)
			y = 0;
		else if (y < 0)
			if (x < tty->num / win.ws_row)
				y = win.ws_row - 1;
			else
				y = tty->num - x * win.ws_row - 1;
	}
	else 
	{
		if (x < 0)
		{
			x = tty->num / win.ws_row;
			if (x * win.ws_row + y >= tty->num)
				x--;
		}
		else if (x * win.ws_row + y >= tty->num)
			x = 0;
	}
	i = x * win.ws_row + y;
	tty->cursor = get_item(list, i);
}

void	right_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x + 1, y);
	}
}

void	left_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x - 1, y);
	}
}

void	up_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x, y + 1);
	}
}

void	down_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x, y - 1);
	}
}
