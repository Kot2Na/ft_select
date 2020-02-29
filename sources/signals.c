# include "select.h"

void	wake_up(int s)
{
	t_ttyinfo	*tty;
	char		byte[2];

	(void)s;
	tty = NULL;
	tty = safe_tty(&tty);
	tcgetattr(tty->fd, &tty->term);
	tty->term.c_cflag &= ~(ECHO | ICANON);
	tty->term.c_oflag &= ~(OPOST);
	tty->term.c_cc[VMIN] = 1;
	tty->term.c_cc[VTIME] = 0;
	tcsetattr(tty->fd, TCSANOW, &tty->term);
	if (tgetent(NULL, getenv("TERM")) <= 0)
	{
		ft_putstr_fd("Some error\n", 2);
		main_end(-1);
	}
	set_signals(tty);
	ft_putstr_fd(tgetstr("vi", NULL), tty->fd);
	ft_putstr_fd(tgetstr("ti", NULL), tty->fd);
	byte[0] = -62;
	//byte[0] = 0;
	byte[1] = 0;
	ioctl(0, TIOCSTI, byte);
}

void	go_sleep(int s)
{
	struct termios	t_term;
	char			byte[2];

	(void)s;
	if (tcgetattr(0, &t_term) == -1)
	{
		ft_putstr_fd("Some error\n", 2);
		main_end(-1);
	}
	byte[0] = t_term.c_cc[VSUSP];
	byte[1] = 0;
	t_term.c_lflag |= (ECHO | ICANON);
	t_term.c_oflag |= OPOST;
	if (tcsetattr(0, TCSADRAIN, &t_term) == -1)
	{
		ft_putstr_fd("Some error\n", 2);
		main_end(-1);
	}
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, byte);
}

void    size_changed(int s)
{
    t_ttyinfo   *tty;
    t_dlist     *head;

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

void    set_signals(t_ttyinfo *tty)
{
    safe_tty(&tty);
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
