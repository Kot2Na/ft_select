#include "select.h"

char	PC;
char	*BC;
char	*UP;
short	ospeed;


int print_char(int c)
{
	if (c < 128)
		write(0, &c, 1);
	return (1);
}

int	main(int ac, char **av, char **ev)
{
	t_ttyinfo *tty;
	char *temp;
	char buf[1024];

	tty = (t_ttyinfo *)malloc(sizeof(t_ttyinfo));
	if ((tty->fd = open(ttyname(0), O_RDWR | O_EVTONLY)) > 0)
	{
		temp = tgetstr("pc", NULL);
		PC = temp ? *temp : 0;
		BC = tgetstr("le", NULL);
		UP = tgetstr("up", NULL);

		if (tgetent(buf, getenv("TERM")) == 1)
		{
			tcgetattr(tty->fd, &tty->term);
			tty->term.c_lflag &= ~(ECHO | ICANON);
			tty->term.c_oflag &= ~(OPOST);
			tty->term.c_cc[VMIN] = 1;
			tty->term.c_cc[VTIME] = 0;
			tcsetattr(tty->fd, TCSANOW, &tty->term);
			ft_putstr_fd(tgetstr("vi", NULL), tty->fd);

			ft_putstr_fd(tgetstr("cl", NULL), tty->fd);

			//tputs(tgetstr("cl", NULL), 1, print_char);

			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), tty->fd);

			//tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, print_char);

			ft_putstr_fd("Hell, ", tty->fd);
			//tputs("Hell, ", 1, print_char);

			//tputs(tgoto(tgetstr("cm", NULL), 2, 2), 1, print_char);
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 2, 2), tty->fd);

			ft_putstr_fd("Word!", tty->fd);
			//tputs("Word!", 1, print_char);
		
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 4, 4), tty->fd);
			ft_putstr_fd("HAHA!", tty->fd);
	
			//tputs(tgoto(tgetstr("cm", NULL), 4, 4), 1, print_char);
			
			//tputs("HAHA!", 1, print_char);
		}
		tty->term.c_lflag |= (ECHO | ICANON);
		tty->term.c_oflag |= (OPOST);
		tcsetattr(tty->fd, TCSANOW, &tty->term);
		close(tty->fd);
	}
	return (0);
}