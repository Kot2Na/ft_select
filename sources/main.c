#include "select.h"

int print_char(int c)
{
	if (c < 128)
		write(0, &c, 1);
	return (1);
}

int	main(int ac, char **av, char **ev)
{
	t_ttyinfo	*tty;
	t_dlist		*list;
	
	tty = init_struct(ev);
	list = create_list(av);
	ft_putstr_fd(tgetstr("vi", NULL), tty->fd);
	while (1)
	{
		print_items(list, tty);
		read(tty->fd, &tty->key, 8);
		key_handling(list, tty);
	}
	return (0);
}