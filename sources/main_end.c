/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:19 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:08:20 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (num != -1)
			ft_putstr_fd(tgetstr("cl", NULL), tty->fd);
		ft_putstr_fd(tgetstr("me", NULL), tty->fd);
		ft_putstr_fd(tgetstr("ve", NULL), tty->fd);
		set_settings_close(tty);
		destr_list(head);
		close(tty->fd);
		free(tty);
	}
	exit(num);
}
