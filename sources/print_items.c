#include "select.h"

void	print_items(t_dlist *list, t_ttyinfo *tty)
{
	int i;

	i = 0;
	if (list && tty)
	{
		ft_putstr_fd(tgetstr("cl", NULL), tty->fd);
		while (list)
		{
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), tty->fd);
			ft_putstr_fd(list->item, tty->fd);
			list = list->next;
			i++;
		}
	}
}