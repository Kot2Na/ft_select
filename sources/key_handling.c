/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:07:18 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:31:19 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	key_handling(t_dlist *list, t_ttyinfo *tty)
{
	if (tty->key == ESC)
		main_end(0);
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
	else if (tty->key == BSPACE || tty->key == DEL)
		backspace_key(list, tty);
	else if (tty->key == ENTER)
		enter_key(list, tty);
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
			main_end(0);
		list = gohead_list(tty->cursor);
		tty->maxsize = max_len(list);
	}
}

void	enter_key(t_dlist *list, t_ttyinfo *tty)
{
	int		flag;

	flag = 0;
	if (list && tty)
	{
		ft_putstr_fd(tgetstr("cl", NULL), tty->fd);
		set_settings_close(tty);
		while (list)
		{
			if (list->selected)
			{
				if (flag)
					ft_putstr_fd(" ", 1);
				ft_putstr_fd(list->item, 1);
				flag = 1;
			}
			list = list->next;
		}
		main_end(-1);
	}
}
