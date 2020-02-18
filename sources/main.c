#include "select.h"

int print_char(int c)
{
	if (c < 128)
		write(0, &c, 1);
	return (1);
}

int	main(int ac, char **av, char **ev)
{
	t_ttyinfo *tty;
	t_dlist *list;
	t_dlist *iter;
	int i;

	tty = init_struct(ev);
	list = create_list(av);
	ft_putstr_fd(tgetstr("vi", NULL), tty->fd);
	ft_putstr_fd(tgetstr("cl", NULL), tty->fd);
	i = 0;
	iter = list;
	while (iter)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), tty->fd);
		ft_putstr_fd(iter->item, tty->fd);
		iter = iter->next;
		i++;
	}
	tty->term.c_lflag |= (ECHO | ICANON);
	tty->term.c_oflag |= (OPOST);
	tcsetattr(tty->fd, TCSANOW, &tty->term);
	destr_list(list);
	close(tty->fd);
	free(tty);
	return (0);
}