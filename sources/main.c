#include "select.h"

int	main(int ac, char **av, char **ev)
{
	t_ttyinfo *tty;

	tty = (t_ttyinfo *)malloc(sizeof(t_ttyinfo));
	if((tty->fd = open(ttyname(0), O_RDWR | O_NDELAY) > 0))
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 10, 5), 0);
		printf("lol");
		ft_putstr_fd("Hell, ", 0);
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 12, 7), 0);
		ft_putstr_fd("Word!", 0);
		printf("haha");
		close(tty->fd);
	}
	return (0);
}