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
	//safe_tty(&tty);
	set_signals(tty);
	ft_putstr_fd(tgetstr("vi", NULL), tty->fd);
	while (1)
	{
		if (tty->cursor)
			list = gohead_list(tty->cursor);
		print_items(list, tty);
		read(tty->fd, &tty->key, sizeof(long int));
		//if (read(tty->fd, &tty->key, sizeof(long int)) > 0)
		//{
			key_handling(list, tty);
		//}
	}
	return (0);
}