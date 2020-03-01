/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:10 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:09:28 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	main(int ac, char **av, char **ev)
{
	t_ttyinfo	*tty;
	t_dlist		*list;

	if (ev == NULL || *ev == NULL)
		print_error("No environment\n", 1);
	if (ac < 2)
		print_error("No arguments\n", 1);
	tty = init_struct(ac);
	list = create_list(av, tty);
	safe_tty(&tty);
	set_signals();
	while (1)
	{
		if (tty->cursor)
			list = gohead_list(tty->cursor);
		print_items(list, tty);
		read(tty->fd, &tty->key, sizeof(long));
		key_handling(list, tty);
	}
	return (0);
}
