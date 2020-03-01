/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:26 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:51:17 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	print_error(char *text, int code)
{
	ft_putstr_fd(text, 2);
	exit(code);
}

int		print_check(t_win *win, t_ttyinfo *tty)
{
	int result;
	int col;
	int row;

	result = 0;
	col = win->ws_col / (tty->maxsize + 1);
	row = win->ws_row;
	if (col * row >= tty->num)
		result = 1;
	return (result);
}

void	printer(t_ttyinfo *tty, t_dlist *list, t_win win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (list)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), tty->fd);
		if (list == tty->cursor)
			ft_putstr_fd(tgetstr("us", NULL), tty->fd);
		if (list->selected)
			ft_putstr_fd(tgetstr("so", NULL), tty->fd);
		ft_putstr_fd(list->item, tty->fd);
		if (list == tty->cursor)
			ft_putstr_fd(tgetstr("ue", NULL), tty->fd);
		if (list->selected)
			ft_putstr_fd(tgetstr("se", NULL), tty->fd);
		list = list->next;
		y++;
		if (y == win.ws_row)
		{
			y = 0;
			x += tty->maxsize + 1;
		}
	}
}

void	print_items(t_dlist *list, t_ttyinfo *tty)
{
	t_win	win;

	if (list && tty)
	{
		ioctl(tty->fd, TIOCGWINSZ, &win);
		ft_putstr_fd(tgetstr("cl", NULL), tty->fd);
		if (print_check(&win, tty))
			printer(tty, list, win);
		else
		{
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), tty->fd);
			ft_putstr_fd("Not enough space\n", tty->fd);
		}
	}
}
