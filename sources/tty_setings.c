/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_setings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:47 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:15:05 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_ttyinfo	*safe_tty(t_ttyinfo **item)
{
	static t_ttyinfo *safe;

	if (*item == NULL)
		return (safe);
	safe = *item;
	return (*item);
}

void		set_settings_close(t_ttyinfo *tty)
{
	if (tty)
	{
		if (tcsetattr(tty->fd, TCSANOW, &tty->term_old) == -1)
			main_end(-1);
	}
}

void		set_settings_open(t_ttyinfo *tty)
{
	if (tty)
	{
		if (tcgetattr(tty->fd, &tty->term_new) == -1 ||
			tcgetattr(tty->fd, &tty->term_old) == -1)
			main_end(-1);
		tty->term_new.c_lflag &= ~(ECHO | ICANON);
		tty->term_new.c_oflag &= ~(OPOST);
		tty->term_new.c_cc[VMIN] = 1;
		tty->term_new.c_cc[VTIME] = 0;
		if (tcsetattr(tty->fd, TCSANOW, &tty->term_new) == -1)
			main_end(-1);
	}
}

t_ttyinfo	*init_struct(int ac)
{
	t_ttyinfo	*result;

	result = NULL;
	if (!(result = (t_ttyinfo *)malloc(sizeof(t_ttyinfo))))
		print_error("Not enough memory\n", 1);
	if (tgetent(NULL, getenv("TERM")) <= 0)
	{
		free(result);
		print_error("Term didn't find\n", 1);
	}
	if ((result->fd = open(ttyname(0), O_RDWR)) < 0)
	{
		free(result);
		print_error("Term didn't open\n", 1);
	}
	result->key = 0;
	result->num = ac - 1;
	result->cursor = NULL;
	set_settings_open(result);
	return (result);
}
