/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:33 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:16:24 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	wake_up(int s)
{
	t_ttyinfo	*tty;

	(void)s;
	tty = NULL;
	tty = safe_tty(&tty);
	if (tgetent(NULL, getenv("TERM")) <= 0)
	{
		ft_putstr_fd("Some error\n", 2);
		main_end(-1);
	}
	set_settings_open(tty);
	set_signals();
	print_items(gohead_list(tty->cursor), tty);
}

void	go_sleep(int s)
{
	t_ttyinfo		*tty;

	(void)s;
	tty = NULL;
	tty = safe_tty(&tty);
	set_settings_close(tty);
	signal(SIGTSTP, SIG_DFL);
	ioctl(tty->fd, TIOCSTI, "\x1A");
}

void	size_changed(int s)
{
	t_ttyinfo	*tty;
	t_dlist		*head;

	(void)s;
	tty = NULL;
	tty = safe_tty(&tty);
	head = gohead_list(tty->cursor);
	if (tgetent(NULL, getenv("TERM")) <= 0)
	{
		ft_putstr_fd("Term didn't find\n", 2);
		main_end(1);
	}
	print_items(head, tty);
}

void	set_signals(void)
{
	signal(SIGWINCH, size_changed);
	signal(SIGTSTP, go_sleep);
	signal(SIGCONT, wake_up);
	signal(SIGPIPE, main_end);
	signal(SIGILL, main_end);
	signal(SIGABRT, main_end);
	signal(SIGSYS, main_end);
	signal(SIGINT, main_end);
	signal(SIGEMT, main_end);
	signal(SIGSEGV, main_end);
	signal(SIGTRAP, main_end);
	signal(SIGKILL, main_end);
	signal(SIGUSR2, main_end);
	signal(SIGHUP, main_end);
	signal(SIGUSR1, main_end);
	signal(SIGQUIT, main_end);
	signal(SIGBUS, main_end);
	signal(SIGFPE, main_end);
	signal(SIGALRM, main_end);
	signal(SIGTERM, main_end);
}
