/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:21:14 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:30:38 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	get_cor(t_dlist *list, t_ttyinfo *tty, int *x, int *y)
{
	int		i;
	t_win	win;

	ioctl(tty->fd, TIOCGWINSZ, &win);
	if ((i = num_item(list, tty->cursor)) >= 0)
	{
		*x = i / win.ws_row;
		*y = i % win.ws_row;
	}
}

int		change_cor_y(int num, int x, int y, t_win win)
{
	if (y >= win.ws_row || x * win.ws_row + y >= num)
		y = 0;
	else if (y < 0)
	{
		if (x < num / win.ws_row)
			y = win.ws_row - 1;
		else
			y = num - x * win.ws_row - 1;
	}
	return (y);
}

int		change_cor_x(int num, int x, int y, t_win win)
{
	if (x < 0)
	{
		x = num / win.ws_row;
		if (x * win.ws_row + y >= num)
			x--;
	}
	else if (x * win.ws_row + y >= num)
		x = 0;
	return (x);
}

void	change_cursor(t_dlist *list, t_ttyinfo *tty, int x, int y)
{
	int		i;
	t_win	win;

	ioctl(tty->fd, TIOCGWINSZ, &win);
	if (tty->key == DOWN || tty->key == UP)
		y = change_cor_y(tty->num, x, y, win);
	else
		x = change_cor_x(tty->num, x, y, win);
	i = x * win.ws_row + y;
	tty->cursor = get_item(list, i);
}
