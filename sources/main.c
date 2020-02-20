#include "select.h"

int	main(int ac, char **av, char **ev)
{
	t_ttyinfo	*tty;
	t_dlist		*list;
	
	tty = init_struct(ac);
	list = create_list(av, tty);
	ft_putstr_fd(tgetstr("vi", NULL), tty->fd);
	while (1)
	{
		print_items(list, tty);
		if (read(tty->fd, &tty->key, sizeof(long int)) > 0)
		{
			key_handling(list, tty);
		}
	}
	return (0);
}